#include "Lib.h"

// Define LRU methods
int LRUCache::get(int key) {
    auto it = itemMap.find(key);
    if (it == itemMap.end()) {
        return -1;  // Key not found
    }

    // Move the accessed item to the front (most recently used)
    itemList.splice(itemList.begin(), itemList, it->second);
    return it->second->second;  // return value
}

void LRUCache::put(int key, int value) {
    auto it = itemMap.find(key);

    if (it != itemMap.end()) {
        // Key exists, update the value and move to front
        it->second->second = value;
        itemList.splice(itemList.begin(), itemList, it->second);
    } else {
        // If at capacity, remove the least recently used item
        if (itemList.size() == capacity) {
            int lruKey = itemList.back().first;
            itemMap.erase(lruKey);
            itemList.pop_back();
        }

        // Insert the new item at the front
        itemList.emplace_front(key, value);
        itemMap[key] = itemList.begin();
    }
}

// Define LFU methods
void LFUCache::updateFrequency(int key) {
    // Get the keys frequency
    int freq = key_to_val_freq[key].second;

    // Erase the iterator at that frequency
    freq_to_keys[freq].erase(key_to_iter[key]);


    if (freq_to_keys[freq].empty()) {
        freq_to_keys.erase(freq);
        
        if (minFreq == freq) minFreq++;
    }

    // Increment the frequency from use
    freq++;
    key_to_val_freq[key].second = freq;

    freq_to_keys[freq].push_front(key);

    key_to_iter[key] = freq_to_keys[freq].begin();
} 

int LFUCache::get(int key) {
    if (key_to_val_freq.find(key) == key_to_val_freq.end())
        return -1;
    
    updateFrequency(key);
    return key_to_val_freq[key].first;

}

void LFUCache::put(int key, int value) {
    if (capacity == 0)
        return;
    
        if (key_to_val_freq.count(key)) {
            key_to_val_freq[key].first = value;
            updateFrequency(key);
            return;
        }

        if (key_to_val_freq.size() >= capacity) {
            // Evict the LFU key
            int evict_key = freq_to_keys[minFreq].back();
            freq_to_keys[minFreq].pop_back();

            if (freq_to_keys[minFreq].empty())
                freq_to_keys.erase(minFreq);

            key_to_val_freq.erase(evict_key);
            key_to_iter.erase(evict_key);   
        }

        // Insert the new key
        key_to_val_freq[key] = {value, 1};
        freq_to_keys[1].push_front(key);
        key_to_iter[key] = freq_to_keys[1].begin();
        minFreq = 1;
}