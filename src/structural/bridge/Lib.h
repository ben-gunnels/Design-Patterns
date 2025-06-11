/**
 * @file Lib.h
 * 
 * @author Benjamin Gunnels (bengunnels8@gmail.com)
 * @brief Implements a bridge design pattern for managing an abstract implementation of a Smart home device controller.
 * 
 * @date 2025-10-04
 * 
 * @copyright Copyright (Benjamin Gunnels) 2025
 *
 * 
 * 
 */
#pragma once
#include <iostream>
#include <string>
#include <random>

class SmartDevice {
public:
    // Constructor & destructor
    SmartDevice(std::string deviceName) : deviceName(deviceName), power(100), powerState(0) {
        // Set the id as a random number from 1-100
        std::random_device rd;                            // Seed (non-deterministic if available)
        std::mt19937 gen(rd());                           // Mersenne Twister engine
        std::uniform_int_distribution<> dist(1, 100);     // Range: 1 to 100

        int randomID = dist(gen);
        id = randomID;
    };

    virtual ~SmartDevice() = 0;

    // Get information
    std::string getDeviceName() { return deviceName; };
    int getPower() { return power; };
    bool getPowerState() { return powerState; };

    // Achieve functionality
    virtual void turnOnDevice() = 0;
    virtual void turnOffDevice() = 0;
    virtual void setPowerLevel(int p) = 0;
    virtual int getPowerLevel() const = 0;

protected:
    int id; // Unique Identifier
    std::string deviceName;
    int power;
    bool powerState; // 0 - off, 1 - on
    
    // Manage device state
    void togglePowerState() { powerState = !powerState; };
    virtual void updatePower() = 0;
};


class SmartLight : public SmartDevice {
public:
    SmartLight(std::string deviceName, int brightness)
        : SmartDevice(deviceName), brightness(brightness) {
    }

    void setPowerLevel(int b) override;
    int getPowerLevel() const override { return brightness; };
 
    // Functionality
    void turnOnDevice() override;
    void turnOffDevice() override;

private:
    int brightness;
    void updatePower() override;
};

class SmartHeater : public SmartDevice {
public:
    SmartHeater(std::string deviceName)
        : SmartDevice(deviceName), heat(5) {
    }

    void setPowerLevel(int h) override;
    int getPowerLevel() const override { return heat; };

    // Functionality
    void turnOnDevice() override;
    void turnOffDevice() override;

private:
    int heat;
    void updatePower() override;
};

class SmartHomeObjectController {
public:
    SmartHomeObjectController(SmartDevice* smartDevice) : device(smartDevice) {};
    
    // Access device functionality
    void turnOnDevice();
    void turnOffDevice();
    int getPower();
    bool getPowerState();

    // Determines how much power the device will use
    void setDevicePowerLevel(int p);

private:
    SmartDevice* device;
};