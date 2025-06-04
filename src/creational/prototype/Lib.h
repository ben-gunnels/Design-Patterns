#include <unordered_map>
#include <list>
#include <iostream>


class CachePrototype {
public:
    // Constructors
    CachePrototype() = default;
    CachePrototype(const CachePrototype& other) = default;

    // Virtual methods
    virtual ~CachePrototype() = default;
    // Cloning method
    virtual CachePrototype* clone() const = 0;
};


class LRUCache: CachePrototype {
public:
    // Constructors
    LRUCache(int capacity): capacity(capacity) {};
    LRUCache(const LRUCache& source) : CachePrototype(source), capacity(source.capacity) {};

    // Cache Methods
    int get(int key);
    void put(int key, int value);

    // Cloning Method
    LRUCache* clone() const override {
        return new LRUCache(*this);
    }

private:
    int capacity;

    // Doubly linked list: stores key-value pairs
    std::list<std::pair<int, int>> itemList;

    // Hash map: key → iterator to itemList
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> itemMap;

};

class LFUCache: CachePrototype {
public:
    // Constructors
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {};
    LFUCache(const LFUCache& source) : 
        CachePrototype(source), 
        capacity(source.capacity),
        minFreq(source.minFreq)
        {};

    // Cache Methods
    int get(int key);
    void put(int key, int value);

    // Cloning method
    LFUCache* clone() const override {
        return new LFUCache(*this);
    }

private:
    int capacity;
    int minFreq;

    // key -> (value, freq)
    std::unordered_map<int, std::pair<int, int>> key_to_val_freq;

    // freq -> list of keys (for LRU ordering)
    std::unordered_map<int, std::list<int>> freq_to_keys;

    // key -> iterator in the freq list
    std::unordered_map<int, std::list<int>::iterator> key_to_iter;

    void updateFrequency(int key);
};