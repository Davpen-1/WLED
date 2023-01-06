#ifndef UMBUnkown_h
#define UMBUnkown_h

#include "battery_defaults.h"
#include "battery.h"

/**
 *  Lion Battery
 * 
 */
class Unkown : public Battery
{
    private:

    public:
        Unkown()
        {
            this->setMinVoltage(USERMOD_BATTERY_UNKOWN_MIN_VOLTAGE);
            this->setMaxVoltage(USERMOD_BATTERY_UNKOWN_MAX_VOLTAGE);
            this->setCapacity(USERMOD_BATTERY_UNKOWN_CAPACITY);
            this->setVoltage(this->getVoltage());
            this->setCalibration(USERMOD_BATTERY_UNKOWN_CALIBRATION);
        }

        void update(batteryConfig cfg)
        {
            if(cfg.minVoltage) this->setMinVoltage(cfg.minVoltage); else this->setMinVoltage(USERMOD_BATTERY_UNKOWN_MIN_VOLTAGE);
            if(cfg.maxVoltage) this->setMaxVoltage(cfg.maxVoltage); else this->setMaxVoltage(USERMOD_BATTERY_UNKOWN_MAX_VOLTAGE);
            if(cfg.calibration) this->setCapacity(cfg.calibration); else this->setCapacity(USERMOD_BATTERY_UNKOWN_CAPACITY);
            if(cfg.calibration) this->setCalibration(cfg.calibration); else this->setCalibration(USERMOD_BATTERY_UNKOWN_CALIBRATION);
        }

        float mapVoltage(float v, float min, float max) override
        {
            return this->linearMapping(v, min, max); // basic mapping
        };

        void calculateAndSetLevel(float voltage) override
        {
            this->setLevel(this->mapVoltage(voltage, this->getMinVoltage(), this->getMaxVoltage()));
        };
};

#endif