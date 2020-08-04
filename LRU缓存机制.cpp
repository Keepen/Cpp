// //问题描述：
// //  运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

// 获取数据 get(key) - 如果关键字 (key) 存在于缓存中，则获取关键字的值（总是正数），否则返回 -1。
//  写入数据 put(key, value) - 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字/值」。
//  当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

// LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );

// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // 返回  1
// cache.put(3, 3);    // 该操作会使得关键字 2 作废
// cache.get(2);       // 返回 -1 (未找到)
// cache.put(4, 4);    // 该操作会使得关键字 1 作废
// cache.get(1);       // 返回 -1 (未找到)
// cache.get(3);       // 返回  3
// cache.get(4);       // 返回  4
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it == m.end()){
            return -1;
        }
        else{
            _lst.push_front(make_pair(it->first, it->second->second));
            _lst.erase(it->second);
            m[key] = _lst.begin();
            return it->second->second;
        }
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it == m.end()){
            _lst.push_front(make_pair(key, value));
            m[key] = _lst.begin();
            ++size;
            if(size > _capacity){
                m.erase(_lst.back().first);
                _lst.pop_back();
                --size;
            }
        }
        else{
            _lst.push_front(make_pair(key, value));
            _lst.erase(it->second);
            m.erase(it);
            m[key] = _lst.begin();
        }
    }
    list<pair<int, int>> _lst;  //存放当前的页
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int size = 0;
    int _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    return 0;
}
