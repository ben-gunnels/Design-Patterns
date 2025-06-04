#include "main.h"

int main() {
    // The director manages the building process
    Director director;
    // For building the Hero
    HeroBuilder heroBuilder = HeroBuilder();
    director.constructHero(heroBuilder);

    Hero hero = heroBuilder.getProduct();

    // To build the Villain
    VillainBuilder villainBuilder = VillainBuilder();
    director.constructVillain(villainBuilder); 

    Villain villain = villainBuilder.getProduct();

    hero.represent();
    villain.represent();

    hero.attack(villain);
    villain.represent();

    return 0;
}