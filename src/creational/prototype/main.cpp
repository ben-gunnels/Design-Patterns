#include "main.h"

int main() {
    // Initialize the first caches of each type
    LRUCache firstLRUCache = LRUCache(2);
    LFUCache firstLFUCache = LFUCache(2);

    firstLRUCache.put(1, 10);
    firstLRUCache.put(2, 20);
    firstLRUCache.put(3, 30);

    std::cout << "Try to get key 1: " << firstLRUCache.get(1) << std::endl; // Should return -1

    // Copy the caches
    LRUCache* secondLRUCache = firstLRUCache.clone();
    LFUCache* secondLFUCache = firstLFUCache.clone();

    secondLFUCache->put(1, 2);
    secondLFUCache->put(2, 3);

    std::cout << "Try to get key 1: " << secondLFUCache->get(1) << std::endl; // Should return 2

    return 1;
}