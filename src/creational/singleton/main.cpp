#include "main.h"

int main() {
    GlobalLeaderboard* leaderboard = GlobalLeaderboard::getInstance();

    leaderboard->insert("Alice", 100); 
    std::cout << "Alice's score: " << leaderboard->lookup("Alice") << std::endl;
    leaderboard->insert("Bob", 150);
    std::cout << "Bob's score: " << leaderboard->lookup("Bob") << std::endl;
    leaderboard->insert("Charlie", 120);
    std::cout << "Charlie's score: " << leaderboard->lookup("Charlie") << std::endl;
}
