#include <vector>
#include <string_view>
#include <string>
struct FastTrieNode {
    bool is_end{false};
    uint32_t children[26]{0}; // 用 32 位整数索引代替 64 位指针（0 表示空）
};

class Trie {
private:
    // static constexpr int size_of_alphabet = 26;
    // alignas(64) struct TrieNode
    // {
    //     bool is_end;
    //     TrieNode* next[size_of_alphabet];
    //     /* data */

    //     TrieNode(bool _is_end)
    //     {
    //         is_end = _is_end;
    //     }
    // };
    std::vector<FastTrieNode> pool;
public:
    Trie() {
        static constexpr int reserve_nodes = 20000;
        pool.reserve(reserve_nodes);
        pool.emplace_back();

    }
    
    void insert(std::string_view word) {
        uint32_t ptr_now = 0 ;
        for(auto c:word)
        {
            const int index = c - 'a';
            if(pool[ptr_now].children[index] == 0)
            {
                pool[ptr_now].children[index] = pool.size();
                pool.emplace_back();
            }
            ptr_now = pool[ptr_now].children[index];
        }
        pool[ptr_now].is_end = true;
    }
    
    bool search(std::string_view word) {
        uint32_t ptr_now = 0;
        for(auto c:word)
        {
            const int index = c - 'a';
            if(pool[ptr_now].children[index] == 0)
            {
                return false;
            }
            ptr_now = pool[ptr_now].children[index];
        }
        return pool[ptr_now].is_end;
    }
    
    bool startsWith(string prefix) {
        uint32_t ptr_now = 0;
        for(auto c:prefix)
        {
            const int index = c - 'a';
            if(pool[ptr_now].children[index] == 0)
            {
                return false;
            }
            ptr_now = pool[ptr_now].children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */