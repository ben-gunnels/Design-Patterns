/**
 * @file Lib.h
 * 
 * @author Benjamin Gunnels (bengunnels8@gmail.com)
 * @brief Implements an abstract factory design pattern for creating a variety of game objects (Vehicles and Characters).
 * @date 2025-06-04
 * 
 * @copyright Copyright (Benjamin Gunnels) 2025
 *
 * 
 * 
 */

#include <string>
#include <iostream>

// Holds the position for the game object
struct Position {
    int x;
    int y;
};

class GameObject {
public:
    GameObject(int x, int y, std::string& name) : pos{x, y}, name(name) {};
    void render();
    void move(int offsetX, int offsetY);

protected:
    std::string name;
    Position pos;
};

// Define concrete types of GameObject
class VehicleObject: public GameObject {
public:
    VehicleObject(int x, int y, std::string& name) : GameObject(x, y, name) {};
};

class CharacterObject : public GameObject {
public:
    CharacterObject(int x, int y, std::string& name) : GameObject(x, y, name) {};
};

// Abstract Factory type for the Vehicle and Character Factories.
class GameObjectFactory {
public:
    virtual GameObject* createGameObject() = 0;
    virtual ~GameObjectFactory() = default;
};

class VehicleFactory : public GameObjectFactory {
public: 
    VehicleFactory(){};
    GameObject* createGameObject() override;
};

class CharacterFactory : public GameObjectFactory {
public: 
    CharacterFactory(){};
    GameObject* createGameObject() override;
};

