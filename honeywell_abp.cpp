#include <honeywell_abp.h>

Honeywell_ABP::Honeywell_ABP(uint16_t address, int p_min, int p_max)
{
    address_ = address;
    p_min_ = p_min;
    p_max_ = p_max;
}

void Honeywell_ABP::joinBytes()
{
    joinedBytes_ = (byte1_ << 8 | byte2_) & 0x3FFF;
}

void Honeywell_ABP::requestBytes()
{
    Wire.requestFrom(address_, (uint8_t) 2);
    byte1_ = Wire.read();
    byte2_ = Wire.read();
    status_ = byte1_ >> 6;
}

void Honeywell_ABP::calcPressure(uint16_t output)
{
    pressure_ = (output - output_min_) * (p_max_ - p_min_) / (output_max_ - output_min_) + p_min_;
}

float Honeywell_ABP::getPressure()
{
    requestBytes();
    joinBytes();
    calcPressure(joinedBytes_);

    return pressure_;
}