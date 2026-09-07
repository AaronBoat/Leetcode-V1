#include <vector>
#include <unordered_map>
using namespace std;

class LRUCache
{
    struct Node
    {
        int key, val;
        int next, prev;
        bool free = true;
        /* data */
    };

private:
    vector<Node> pools;
    static constexpr int reserve_size = 10000; // TODO: change initial func to reserve + 4(free dummy also count for 2)
    unordered_map<int, int> cache;             // key to  node index , all keys in the cache
    int head_dummy, tail_dummy;                // in cache is a linked list to O(1) delete and insert
    int head_free_dummy, tail_free_dummy;      // manual memory assign in the vector<> pools
    int capacity;

    void remove(int index) // node index in pools
    {
        pools[pools[index].next].prev = pools[index].prev;
        pools[pools[index].prev].next = pools[index].next;
    }

    void insert_to_head(int index) // insert a node(index) to head of the list
    {
        pools[pools[head_dummy].next].prev = index;
        pools[index].next = pools[head_dummy].next;
        pools[head_dummy].next = index;
        pools[index].prev = head_dummy;
    }

    int new_node(int key, int value) // ptr.. is the index of next free in pools
    {
        int ptr_new_node = pools[head_free_dummy].next;

        pools[head_free_dummy].next = pools[ptr].next;
        pools[pools[ptr].next].prev = head_free_dummy;

        pools[ptr_new_node].key = key;
        pools[ptr_new_node].val = value;
        pools[ptr_new_node].free = false;
        return ptr_new_node;
    }

    void free_node(int index)
    {
        pools[index].free = true;

        pools[index].next = pools[head_free_dummy].next;
        pools[index].prev = head_free_dummy;
        pools[pools[head_free_dummy].next].prev = index;
        pools[head_free_dummy].next = index;
    }

public:
    LRUCache(int capacity)
    {
        pools.reserve(reserve_size + 2);
        head_dummy = 0;
        tail_dummy = 1;
        pools[head_dummy].next = tail_dummy;
        pools[tail_dummy].prev = head_dummy;
        pools[head_dummy].free = false;
        pools[head_dummy].free = false;

        this->capacity = capacity;

        head_free_dummy = 2;
        tail_free_dummy = reserve_size + 1;
        for (int i = 2; i < reserve_size + 1; i++)
        {
            pools[i].next = i + 1;
            pools[i + 1].prev = i;
            // free linked list
        }
    }

    int get(int key)
    {
        auto it = cache.find(key);
        if (it != cache.end())
        {
            remove(it->second);
            insert_to_head(it->second);
            // touch
            return pools[it->second].val;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        auto it = cache.find(key);
        if (it != cache.end())
        {
            pools[it->second].val = value;
            remove(it->second);
            insert_to_head(it->second);
        }
        else
        {
            int ptr_new_node = new_node(key, value);

            if (cache.size() < capacity)
            {
                insert_to_head(ptr_new_node);
                cache[key] = ptr_new_node;
            }
            else
            {
                // cache.erase(pools[pools[tail_dummy].prev].key);
                // remove(pools[tail_dummy].prev);

                int evicted_idx = pools[tail_dummy].prev;
                cache.erase(pools[evicted_idx].key); // 先删除 map 对应元素
                remove(evicted_idx);                 // 从 LRU 链表中摘除
                free_node(evicted_idx);              // 回收回 Free List

                insert_to_head(ptr_new_node);
                cache[key] = ptr_new_node;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */