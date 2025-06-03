#include "main.h"

int main() {
    // Create the abstract holders for the factory and game object
    GameObjectFactory *factory;

    std::cout << "Please enter the type of object you would like to create for the game: {vehicle, character} ";

    std::string characterSelection;

    std::cin >> characterSelection;

    if (characterSelection == "vehicle") factory = new VehicleFactory();
    else factory = new CharacterFactory();

    GameObject* object = factory->createGameObject();

    object->move(10, 10);
    object->render();
}