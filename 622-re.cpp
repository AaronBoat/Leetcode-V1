#include <vector>
using namespace std;

class MyCircularQueue
{
private:
    vector<int> q;
    int num_elements;
    int head = 0;
    int next_pos = 1;
    int k;

    inline void add_mod_k(int &x)
    {
        x = (x + 1) % k;
    }

    inline void minus_mod_k(int &x)
    {
        x = (x - 1 ) %k;
    }

    inline int get_minus_mod_k(int x)
    {
        return (x + k - 1) %k;
    }
public:
    MyCircularQueue(int k)
    {
        q.resize(k + 1);
        num_elements = 0;

        head = 0;
        next_pos = 0;
        this->k = k;
    }

    bool enQueue(int value)
    {
        if (num_elements >= k)
        {
            return false;
        }
        else
        {
            q[next_pos] = value;
            add_mod_k(next_pos);
            num_elements++;
            return true;
        }
    }

    bool deQueue()
    {
        if(num_elements > 0)
        {
            add_mod_k(head);
            num_elements--;
            return true;
        }
        else{
            return false;
        }
    }

    int Front()
    {
        if(num_elements > 0)
        {
            return q[head];
        }
        else
        {
            return -1;
        }
    }

    int Rear()
    {
        if(num_elements>0)
        {
            return q[get_minus_mod_k(next_pos)];
        }
        else
        {
            return -1;
        }
    }

    bool isEmpty()
    {
        return !(num_elements > 0);
    }

    bool isFull()
    {
        return num_elements == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */