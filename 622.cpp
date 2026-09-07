#include<vector>
using namespace std;

class MyCircularQueue {
private:
    int head,tail;
    vector<int> q;
    int k;
    void add_1(int &n)
    {
        n++;
        if(n >= k)
        {
            n -= k;
        }
    }
public:
    MyCircularQueue(int k) {
        q.reserve(k);
        head = 0;
        tail = -1;
        this->k = k;
    }
    
    bool enQueue(int value) {
        add_1(tail);
        if(tail != head)
        {
            q[tail] = value;
            //1
cout<<"enqueue: head = "<<head<<" , tail = "<<tail<<'\n';
            //2
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool deQueue() {
        if(head != tail)
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
    
    int Front() {
        if(head != tail)
        {
            return q[head];
        }
        else
        {
            return -1;
        }
    }
    
    int Rear() {
        if(head != tail)
        {
            return q[tail];
        }
        else
        {
            return -1;
        }
    }
    
    bool isEmpty() {
        return head == tail;
    }
    
    bool isFull() {
        int next_tail = tail + 1;
        return next_tail == head + k || next_tail == head || head == next_tail + k;
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