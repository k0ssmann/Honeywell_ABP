#include <honeywell_abp.h>

Honeywell_ABP::Honeywell_ABP(uint16_t Address, int Pmin, int Pmax)
{
    mAddress = Address;
    mPmin = Pmin;
    mPmax = Pmax;
}

bool Honeywell_ABP::getData()
{
    int n;
    n = Wire.requestFrom(mAddress, (uint8_t) 4);

    if(n == 4) // Did we receive the number of requested bytes?
    {
        for(int i = 0; i < 4; i++)
        {
            buffer[i] = Wire.read();
        }
        mStatus = buffer[0] >> 6;
        mBridgeData = (buffer[0] << 8 | buffer[1]) & 0x3FFF;
        mTemperatureData = ((buffer[2] << 8) | (buffer[3] >> 5)) & 0x7FF;
        mPressure = OutputFunction(mBridgeData);
        mTemperature = ConversionFunction(mTemperatureData);

        return true;
    }

    return false;
}

float Honeywell_ABP::OutputFunction(uint16_t output)
{
    return (output - mOutputMin) * (mPmax - mPmin) / (mOutputMax - mOutputMin) + mPmin;
}

float Honeywell_ABP::ConversionFunction(uint16_t output)
{
    return (output / 2047 * 200) - 50;
}

const char* Honeywell_ABP::getStatus() const
{
    switch(mStatus)
    {
        case 0: return "Status Code 0: Normal operation.";
        case 1: return "Status Code 1: Device in command mode";
        case 2: return "Status Code 2: Stale data.";
        case 3: return "Status Code 3: Diagnostic condition.";
        default: return "Unknown error";
    }
}