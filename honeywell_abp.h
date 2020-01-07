#ifndef Honeywell_ABP_h
#define Honeywell_ABP_h

#include <Arduino.h>
#include <Wire.h>

class Honeywell_ABP {
    public:

        /* void getData();
        float getPressure(uint16_t raw);
        uint8_t getStatus() {return status;};
        uint8_t getAddress() {return abpAddress;};
        uint16_t getBridge_data() {return bridge_data;};
        uint8_t getByte1() {return byte1;};
        uint8_t getByte2() {return byte2;};

        honeywell_abp(uint8_t slaveAdr, float pressureMin, float pressureMax); */

        Honeywell_ABP(uint16_t address);
        void getData();

        uint8_t getByte1() {return byte1_;};
        uint8_t getByte2() {return byte2_;};

    private:

            uint16_t address_;
            uint8_t byte1_;
            uint8_t byte2_;
        

/*         uint8_t abpAddress;
        uint8_t byte1;
        uint8_t byte2;

        int p_min;
        int p_max;
        float pressure;

        uint16_t bridge_data;
        uint8_t status;

        uint16_t output_min = 0x0666;
        uint16_t output_max = 0x399A; */

};


#endif