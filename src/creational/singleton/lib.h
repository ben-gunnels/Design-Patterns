/**
 * @file Lib.h
 * 
 * @author Benjamin Gunnels (bengunnels8@gmail.com)
 * @brief Implements a Singleton design pattern for managing a global leaderboard for a game.
 * @date 2025-06-04
 * 
 * @copyright Copyright (Benjamin Gunnels) 2025
 *
 * 
 */
#include <iostream>
#include <string>
#include <list>
#include <set>
#include <mutex>
#include <memory>

class GlobalLeaderboard {
public:
    // Returns the global instance of the leaderboard (this)
    static GlobalLeaderboard* getInstance();

    // Methods to add to the leaderboard and lookup a player's score
    void insert(std::string username, int score);
    int lookup(std::string username);

    // Delete copy constructor and assignment
    GlobalLeaderboard(const GlobalLeaderboard&) = delete;
    GlobalLeaderboard& operator=(const GlobalLeaderboard&) = delete;

private:
    // Constructor is hidden
    GlobalLeaderboard(){};

    // Holds static instance of global database
    static std::unique_ptr<GlobalLeaderboard> instance;

    // Mutex to synchronize access
    static std::mutex mtx;

    // Leaderboard data and objects
    // Custom comparator
    struct CompareByValue {
        bool operator()(const std::pair<std::string, int>& a,
                        const std::pair<std::string, int>& b) const {
            return a.second < b.second;
        }
    };

    std::multiset<std::pair<std::string, int>, CompareByValue> username_score_leaderboard; // list of <username, score> insertion keeps sorted by score
};