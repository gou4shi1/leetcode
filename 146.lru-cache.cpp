/*
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Hard (20.37%)
 * Total Accepted:    185.7K
 * Total Submissions: 903.5K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * 
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 */
//#include "header.h"

// pair
typedef pair<int, int> PII;
#define mp make_pair
#define fi first
#define se second

class LRUCache {
    unordered_map<int, list<PII>::iterator> _map;
    list<PII> _cache;
    int _capacity;

public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        if (_map.count(key)) {
            auto it = _map[key];
            _cache.splice(_cache.begin(), _cache, it);
            return _cache.begin()->se;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (_map.count(key)) {
            auto it = _map[key];
            it->se = value;
            _cache.splice(_cache.begin(), _cache, it);
        } else {
            if (_cache.size() >= _capacity) {
                auto t = _cache.back();
                _map.erase(t.fi);
                _cache.pop_back();
            }
            _cache.insert(_cache.begin(), mp(key, value));
            _map[key] = _cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
