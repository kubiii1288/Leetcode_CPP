//
// Created by Anh Le on 8/13/26.
//

class SmallestInfiniteSet {
public:
    int current = 1;
    priority_queue<int,vector<int>,std::greater<int>> heap;
    unordered_set<int> inHeap;

    SmallestInfiniteSet() {

    }

    int popSmallest() {
        if (heap.empty())
        {
            return current++;
        } else
        {
            int smallest = heap.top();
            heap.pop();
            inHeap.erase(smallest);
            return smallest;
        }
    }

    void addBack(int num) {
        if (num < current && inHeap.count(num) == 0)
        {
            heap.push(num);
            inHeap.insert(num);
        }
    }
};