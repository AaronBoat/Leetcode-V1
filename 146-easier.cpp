#include <unordered_map>

class LRUCache
{
    struct Node
    {
        int key, val;
        Node *next, *prev;

        Node()
        {
            this->key = -1;
            this->val = -1;
        }
        Node(int key,int val)
        {
            this->key = key;
            this->val = val;
        }
    };

private:
    int capacity;
    Node *head_dummy, *tail_dummy;
    std::unordered_map<int, Node *> key_to_node; // all nodes in the cache

    inline void remove(Node *n)
    {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    inline void add_to_head(Node *n)
    {
        n->next = head_dummy->next;
        n->prev = head_dummy;
        head_dummy->next->prev = n;
        head_dummy->next = n;
    }

public:
    LRUCache(int capacity)
    {
        head_dummy = new Node();
        tail_dummy = new Node();
        head_dummy->next = tail_dummy;
        tail_dummy->prev = head_dummy;

        this->capacity = capacity;
    }

    int get(int key)
    {
        auto it = key_to_node.find(key);
        if (it != key_to_node.end())
        {
            remove(it->second);
            add_to_head(it->second);
            return it->second->val;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        auto it = key_to_node.find(key);
        if (it != key_to_node.end())
        {
            [[unlikely]] remove(it->second);
            add_to_head(it->second);
        }
        else
        {
            Node* insert = new Node(key,value);
            [[likely]]
            if (key_to_node.size() >=capacity)
            {
                [[likely]]
                key_to_node.erase(tail_dummy->key);
                remove(tail_dummy->prev);
                add_to_head(insert);

            }
            else
            {
                [[unlikely]]
                add_to_head(insert);
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