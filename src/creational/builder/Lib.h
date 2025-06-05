/**
 * @file Lib.h
 * 
 * @author Benjamin Gunnels (bengunnels8@gmail.com)
 * @brief Implements a builder design pattern for building some archetypal video game characters (Heroes and Villains).
 * The concrete builder classes manage the creation of their delegated objects, rather than passing data through a bloated constructor.
 * @date 2025-06-04
 * 
 * @copyright Copyright (Benjamin Gunnels) 2025
 *
 * 
 * 
 */

#include <string>
#include <iostream>

class Hero;
class Villain; 

struct Position {
    int x;
    int y;
};

class Hero {
public:
    Hero() = default;
    void setLives(int lives);
    void setPower(int power);
    void setName(std::string name);   
    int getLives();
    int getPower();
    std::string getName();

    void move(int offsetX, int offsetY);
    void heal();
    void attack(Villain &villain);
    void takeDamage();
    void represent();

private:
    int lives;
    int power;
    std::string name;
    
    Position position{0, 0};
};

class Villain {
public:
    Villain() = default;
    void setLives(int lives);
    void setPower(int power);
    void setName(std::string name);
    int getLives();
    int getPower();
    std::string getName();

    void move(int offsetX, int offsetY);
    void attack(Hero &hero);
    void takeDamage();
    void represent();

private:
    int lives;
    int power;
    std::string name;

    Position position{0, 0};
};

// Abstract Builder class defines the common methods for building the subclasses
class Builder {
public: 
    virtual void reset() = 0;
    virtual void setLives(int lives) = 0;
    virtual void setPower(int power) = 0;
    virtual void setName(std::string name) = 0;
};

class HeroBuilder: Builder {
public: 
    HeroBuilder(){};
    void reset();
    void setName(std::string name);
    void setLives(int lives);
    void setPower(int power);

    // Return the product
    Hero getProduct();
private:
    Hero hero;
};

class VillainBuilder: Builder {
public:
    VillainBuilder(){};
    void reset();
    void setName(std::string name);
    void setLives(int lives);
    void setPower(int power);

    // Return the product
    Villain getProduct();
private:
    Villain villain;
};

// Handles the management of creation given a builder class
class Director {
public:
    Director() {};
    
    void constructHero(HeroBuilder& builder);
    void constructVillain(VillainBuilder& builder);
};




























