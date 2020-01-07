#include <honeywell_abp.h>

Honeywell_ABP::Honeywell_ABP(uint16_t address)
{
    address_ = address;
}

void Honeywell_ABP::getData()
{
    Wire.requestFrom(address_, (uint8_t) 2);
    byte1_ = Wire.read();
    byte2_ = Wire.read();
}


/* 
honeywell_abp::honeywell_abp(uint8_t slaveAdr, float pressureMin, float pressureMax)
{
    abpAddress = slaveAdr;
    p_min = pressureMin;
    p_max = pressureMax;
}

float honeywell_abp::getPressure(uint16_t raw)
{
    return (raw - output_min)*(p_max - p_min)/(output_max - output_min) + p_min;
}
void honeywell_abp::getData()
{
    Wire.requestFrom(abpAddress, (uint8_t) 2);
    while(Wire.available())
    {
        uint8_t byte1 = Wire.read();
        uint8_t byte2 = Wire.read();
    }

    status = byte1 & 0xC0;
    bridge_data = ((byte1 & 0x3F) << 2) | byte2;
    pressure = getPressure(bridge_data);
} */