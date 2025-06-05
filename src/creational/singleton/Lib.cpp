#include "Lib.h"

std::unique_ptr<GlobalLeaderboard> GlobalLeaderboard::instance = nullptr;
std::mutex GlobalLeaderboard::mtx;

GlobalLeaderboard* GlobalLeaderboard::getInstance() {
    // Public accessor for the singleton instance
    if (!instance) {
        std::lock_guard<std::mutex> lock(mtx);
        if (!instance) {
            instance.reset(new GlobalLeaderboard());
        }
    }
    return instance.get();
}

void GlobalLeaderboard::insert(std::string name, int score) {
    // Add the user into the leaderboard 
    username_score_leaderboard.insert({name, score});
}

int GlobalLeaderboard::lookup(std::string name) {
    for (const auto& data : username_score_leaderboard) {
        if (data.first == name)
            return data.second;
    }
    // Default
    return -1;
}