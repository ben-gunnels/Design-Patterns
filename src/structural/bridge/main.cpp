#include "main.h"

int main() {
    SmartLight DeskLampBulb("DeskLampBulb", 10);
    SmartHeater StudyHeater("StudyHeater");

    // Controllers hold pointers to SmartDevice base type
    SmartHomeObjectController LightRemote(&DeskLampBulb);
    SmartHomeObjectController HeaterRemote(&StudyHeater);

    // Light control
    LightRemote.turnOnDevice();
    std::cout << "Lightbulb Power: " << LightRemote.getPower() << std::endl;
    LightRemote.turnOffDevice();

    // Heater control
    HeaterRemote.turnOnDevice();
    std::cout << "Heater Power: " << HeaterRemote.getPower() << std::endl;
    HeaterRemote.turnOffDevice();

    // Adjust heat level before turning on
    HeaterRemote.setDevicePowerLevel(8);
    HeaterRemote.turnOnDevice();
    std::cout << "Heater Power (after increase): " << HeaterRemote.getPower() << std::endl;
    HeaterRemote.turnOffDevice();
}