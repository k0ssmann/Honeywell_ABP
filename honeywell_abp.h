#ifndef Honeywell_ABP_h
#define Honeywell_ABP_h

#include <Arduino.h>
#include <Wire.h>

class Honeywell_ABP {
    public:

        Honeywell_ABP(uint16_t address, int p_min, int p_max);
        bool getData();
        const char* getStatus() const;
        float getPressure() {return mPressure;};
        float getTemperature() {return mTemperature;};
        float OutputFunction(uint16_t output);
        float ConversionFunction(uint16_t output);

    private:

            uint16_t mAddress;
            uint8_t buffer[4];
            uint8_t mStatus;
            uint16_t mBridgeData;
            uint16_t mTemperatureData;

            int mPmin;
            int mPmax;

            float mPressure;
            float mTemperature;

            uint16_t mOutputMin = 0x0666;
            uint16_t mOutputMax = 0x399A;

};


#endif