#include<queue>
#include<vector>
#include<utility>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> max_heap; //小侧大顶堆
    priority_queue<int,vector<int>,greater<int>>  min_heap; // 大侧小顶堆
    //int total_size = 0;
    static constexpr int reserve_size = 1000;
public:
    MedianFinder() {
        //total_size = 0;
        vector<int> max_container;
        vector<int> min_container;

        max_container.reserve(reserve_size);
        min_container.reserve(reserve_size);

        max_heap = priority_queue<int> (less<int>(),std::move(max_container));
        min_heap = priority_queue<int,vector<int>,greater<int>> (greater<int>(),move(min_container));
    }
    
    void addNum(int num) {
        if(!max_heap.empty())
        {
            if(num > max_heap.top())
            {
                min_heap.push(num);
            }
            else
            {
                max_heap.push(num);
            }
        }
        else
        {
            max_heap.push(num);
        }

        if(max_heap.size() - min_heap.size() >= 2)
        {
            while(max_heap.size() > min_heap.size() + 1)
            {
                int val = max_heap.top();
                max_heap.pop();
                min_heap.push(val);
            }
        }

        if(min_heap.size() > max_heap.size())
        {
            while(min_heap.size() > max_heap.size())
            {
                int val = min_heap.top();
                min_heap.pop();
                max_heap.push(val);
            }
        }
    }
    
    double findMedian() {
        if((min_heap.size( ) + max_heap.size() )% 2 ==0)
        {
            [[unlikely]]
            return (double)((min_heap.top() + max_heap.top())/2.0);
        }
        else
        {
            [[likely]]
            return max_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */