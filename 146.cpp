#include<unordered_map>
#include<list>
#include<vector>
using namespace std;
class LRUCache {
    struct Node{
        int key,val;
        int next,prev;
    };
private:
    // list<int> cache;
    vector<Node> pool_nodes;
    unordered_map<int,int> key_to_val;
    int ptr_dummy_head , ptr_dummy_tail;
    int free_head_pool;
    static constexpr int reserve_size = 10000;

    void delete_node(int idx_pool)
    {
        pool_nodes[pool_nodes[idx_pool].prev].next = pool_nodes[idx_pool].next;
        pool_nodes[pool_nodes[idx_pool].next].prev = pool_nodes[idx_pool].prev;
        key_to_val.
    }
public:
    LRUCache(int capacity) {
        pool_nodes.reserve(capacity + 2);
        ptr_dummy_head = 0;
        ptr_dummy_tail = 1;
        pool_nodes[ptr_dummy_head].next = 1;
        pool_nodes[ptr_dummy_tail].prev = 0;

        for(int i = 2 ; i < capacity + 1 ; i++)
        {
            pool_nodes[i].next = i + 1;
            pool_nodes[i].prev = -1;
        }
        free_head_pool = 2;
    }
    
    int get(int key) { //get index in cache
        auto it = key_to_val.find(key);
        if(it == key_to_val.end())
        {
            return -1;
        }
        else{
            return it->second;
        }
    }
    
    void put(int key, int value) {
        auto it = key_to_val.find(key);
        if(it != key_to_val.end())
        {

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */