// /*
// 705. Design HashSet-(как unordered set)
// Design a HashSet without using any built-in hash table libraries.

// Implement MyHashSet class:

// void add(key) Inserts the value key into the HashSet.
// bool contains(key) Returns whether the value key exists in the HashSet or not.
// void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
// */
#include <iostream>
#include <vector>
using namespace std;
// done
class MyHashSet {
public:
    vector<long long> hashes;
    MyHashSet() {
        
    }
    
    void add(int key) {
        bool ok=true;
        for(int i=0;i<hashes.size();i++){
            if(key==hashes[i]){
                ok=false;
                break;
            }
        }
        if(ok) hashes.push_back(key);
    }
    
    void remove(int key) {
        for(int i=0;i<hashes.size();i++){
            if(key==hashes[i]){
                swap(hashes[i],hashes[hashes.size()-1]);
                hashes.pop_back();
                return;
            }
        }
    }
    
    bool contains(int key) {
        bool ok=false;
        for(int i=0;i<hashes.size();i++){
            if(key==hashes[i]){
                ok=true;
                return ok;
            }
        }
        return ok;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */