class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>, greater<int>> min_heap;
    MedianFinder() {
    }

    void addNum(int num) {
        if (min_heap.empty() && max_heap.empty())
        {
            max_heap.push(num);
        } else if (min_heap.empty())
        {
            if (num < max_heap.top())
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            } else min_heap.push(num);
        } else
        {
            if (num <= max_heap.top())
            {
                if (max_heap.size() > min_heap.size())
                {
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                    max_heap.push(num);
                } else max_heap.push(num);
            } else if (max_heap.top() < num && num < min_heap.top())
            {
                if (max_heap.size() > min_heap.size())
                    min_heap.push(num);
                else
                    max_heap.push(num);
            } else
            {
                if (max_heap.size() > min_heap.size())
                {
                    min_heap.push(num);
                } else
                {
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                    min_heap.push(num);
                }
            }
        }

    }

    double findMedian() {
        if (max_heap.empty() && min_heap.empty()) return 0;
        if (max_heap.size() == min_heap.size())
            return double(max_heap.top() + min_heap.top()) / 2;
        if (max_heap.size() > min_heap.size())
            return max_heap.top();
        return min_heap.top();
    }
};