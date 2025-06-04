#include "Lib.h"

// Define Hero Methods
void Hero::setLives(int lives) {
    this->lives = lives;
}

void Hero::setPower(int power) {
    this->power = power;
}

void Hero::setName(std::string name) {
    this->name = name;
}

int Hero::getLives() {
    return lives;
}

int Hero::getPower() {
    return power;
}

std::string Hero::getName() {
    return name;
}

void Hero::move(int offsetX, int offsetY) {
    position.x += offsetX;
    position.y += offsetY;
}

void Hero::heal() {
    lives += 1;
}

void Hero::attack(Villain &villain) {
    villain.takeDamage();
}

void Hero::takeDamage() {
    lives -= 1;
}

void Hero::represent() {
    std::cout << name << " Lives:  " << lives << std::endl;
}


// Define Villain Methods
void Villain::setLives(int lives) {
    this->lives = lives;
}

void Villain::setPower(int power) {
    this->power = power;
}

void Villain::setName(std::string name) {
    this->name = name;
}

int Villain::getLives() {
    return lives;
}

int Villain::getPower() {
    return power;
}

std::string Villain::getName() {
    return name;
}

void Villain::move(int offsetX, int offsetY) {
    position.x += offsetX;
    position.y += offsetY;
}

void Villain::attack(Hero &hero) {
    hero.takeDamage();
}

void Villain::takeDamage() {
    lives -= 1;
}

void Villain::represent() {
    std::cout << name << " Lives: " << lives << std::endl;
}

// Define the Builder methods
void HeroBuilder::reset() {
    hero = Hero();
}

void HeroBuilder::setName(std::string name) {
    hero.setName(name);
}

void HeroBuilder::setLives(int lives) {
    hero.setLives(lives);
}

void HeroBuilder::setPower(int power) {
    hero.setPower(power);
}

Hero HeroBuilder::getProduct() {
    Hero product = this->hero;
    reset();

    return product;
}


// Villain Builder class
void VillainBuilder::reset() {
    villain = Villain();
}

void VillainBuilder::setName(std::string name) {
    villain.setName(name);
}

void VillainBuilder::setLives(int lives) {
    villain.setLives(lives);
}

void VillainBuilder::setPower(int power) {
    villain.setPower(power);
}

Villain VillainBuilder::getProduct() {
    Villain product = villain;
    reset();   
    return product;
}

// Define the Director Methods
void Director::constructHero(HeroBuilder& builder) {
    builder.reset();
    builder.setLives(100);
    builder.setName("Hero");
    builder.setPower(75);
}   

void Director::constructVillain(VillainBuilder& builder) {
    builder.reset();
    builder.setLives(25);
    builder.setName("Bad Guy");
    builder.setPower(10);
}
