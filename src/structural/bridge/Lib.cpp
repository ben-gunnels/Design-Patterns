#include "Lib.h"

SmartDevice::~SmartDevice() {};

// Access device functionality through the device's controller
void SmartHomeObjectController::turnOnDevice() {
    device->turnOnDevice();
}

void SmartHomeObjectController::turnOffDevice() {
    device->turnOffDevice();
}

int SmartHomeObjectController::getPower() {
    return device->getPower();
}

bool SmartHomeObjectController::getPowerState() {
    return device->getPowerState();
}

void SmartHomeObjectController::setDevicePowerLevel(int p) {
    device->setPowerLevel(p);
}

// Define the concrete implementations of the SmartDevice subclasses

// Define SmartLight methods
void SmartLight::setPowerLevel(int b) {
    brightness = std::min(std::max(1, b), 10);
}

void SmartLight::turnOnDevice() {
    if (!powerState && power > 0) { // Use power until it runs out
        togglePowerState();
        updatePower(); // Reduce the power everytime the device is turned on.
        std::cout << "Light on!" << std::endl;
    }
}

void SmartLight::turnOffDevice() {
    if (powerState) {
        togglePowerState();
        std::cout << "Light off!" << std::endl;
    }
}

void SmartLight::updatePower() {
    power = std::max(power - 1, 0);
}

// Define SmartHeater methods
void SmartHeater::setPowerLevel(int h) {
    heat = std::min(std::max(h, 1), 20);
}

void SmartHeater::turnOnDevice() {
    if (!powerState && power > 0) { // Use power until it runs out
        togglePowerState();
        updatePower(); // Reduce the power everytime the device is turned on.
        std::cout << "Heating up!" << std::endl;
    }
}

void SmartHeater::turnOffDevice() {
    if (powerState) {
        togglePowerState();
        std::cout << "Heater shutting down!" << std::endl;
    }
}

void SmartHeater::updatePower() {
    power = std::max(power - heat, 0); // Reduce the power available everytime it is turned on.
}