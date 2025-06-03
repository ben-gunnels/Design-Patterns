#include "Lib.h"

void GameObject::render()
{
    std::cout << "Name: " << name << " X: " << pos.x << " Y: " << pos.y;
}

void GameObject::move(int offsetX, int offsetY)
{
    pos.x += offsetX;
    pos.y += offsetY;
}

GameObject* VehicleFactory::createGameObject() {
    std::string name = "Vehicle";
    return new VehicleObject(0, 0, name);
}

GameObject* CharacterFactory::createGameObject() {
    std:: string name = "Character";
    return new CharacterObject(0, 0, name);
}