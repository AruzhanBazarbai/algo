// /* 706. Design HashMap
// Design a HashMap without using any built-in hash table libraries.

// Implement the MyHashMap class:

// MyHashMap() initializes the object with an empty map.
// void put(int key, int value) inserts a (key, value) pair into the HashMap. 
// If the key already exists in the map, update the corresponding value.
// int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
// void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
// */
#include <iostream>
#include <vector>
using namespace std;
// done
class MyHashMap {
public:
    vector<pair<long long,int> > hashes;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        bool ok=true;
        for(int i=0;i<hashes.size();i++){
            if(key==hashes[i].first){
                ok=false;
                hashes[i].second=value;
                break;
            }
        }
        if(ok) hashes.push_back(make_pair(key,value));
    }
    
    int get(int key) {
        bool ok=true;
        for(int i=0;i<hashes.size();i++){
            if(key==hashes[i].first){
                ok=false;
                return hashes[i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for(int i=0;i<hashes.size();i++){
            if(key==hashes[i].first){
                swap(hashes[i],hashes[hashes.size()-1]);
                hashes.pop_back();
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */