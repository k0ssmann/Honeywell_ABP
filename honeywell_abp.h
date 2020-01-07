#ifndef Honeywell_ABP_h
#define Honeywell_ABP_h

#include <Arduino.h>
#include <Wire.h>

class Honeywell_ABP {
    public:

        Honeywell_ABP(uint16_t address, int p_min, int p_max);
        void requestBytes();
        void joinBytes(uint8_t byte1, uint8_t byte2);
        void calcPressure(uint16_t bridge_data);

        uint8_t getByte1() {return byte1_;}; 
        uint8_t getByte2() {return byte2_;};
        uint8_t getStatus() {return status_;};
        uint16_t getJoinedBytes() {return joinedBytes_;};
        float getPressure();


    private:

            uint16_t address_;
            uint8_t byte1_;
            uint8_t byte2_;
            uint8_t status_;
            uint16_t joinedBytes_;

            int p_min_;
            int p_max_;

            float pressure_;

            uint16_t output_min_ = 0x0666;
            uint16_t output_max_ = 0x399A;

};


#endif