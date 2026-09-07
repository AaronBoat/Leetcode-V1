#include <vector>
#include <iostream>
using namespace std;

class MyCircularQueue
{
private:
    int head, tail_next;
    vector<int> q;
    int k;
    void add_1(int &n)
    {
        n++;
        if (n >= k)
        {
            n -= k;
        }
    }
    int to_add_1(int n)
    {
        n++;
        if (n >= k)
        {
            n -= k;
        }
        return n;
    }
    int to_minus_1(int n)
    {
        n--;
        if (n < 0)
        {
            n += k;
        }
        return n;
    }

public:
    MyCircularQueue(int k)
    {
        q.reserve(k);
        head = 0;
        tail_next = 1;
        this->k = k;
    }

    bool enQueue(int value)
    {

        if (to_minus_1(tail_next) != head)
        {
            q[tail_next] = value;
            // 1
            cout << "enqueue: head = " << head << " , tail_next = " << tail_next << " with value: " << value << '\n';
            // 2
            add_1(tail_next);
            return true;
        }
        else
        {
            return false;
        }
    }

    bool deQueue()
    {
        if (head != to_minus_1(tail_next))
        {
            q[head] = -1;
            add_1(head);
            return true;
        }
        else
        {
            return false;
        }
    }

    int Front()
    {
        if (head != to_minus_1(tail_next))
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
        if (head != to_minus_1(tail_next))
        {
            return q[tail_next];
        }
        else
        {
            return -1;
        }
    }

    bool isEmpty()
    {
        return head == to_minus_1(tail_next);
    }

    bool isFull()
    {
        return tail_next == head + k || tail_next == head || head == tail_next + k;
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