// 295. Find Medium from Data Stream
#include "leetcode.hpp"
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        left.push(num);
        right.push(-left.top());
        left.pop();

        if (left.size() < right.size()) {
            left.push(-right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        return left.size() > right.size() ? left.top() : (left.top() - right.top()) / 2.0;
    }

private:
    // left saves the left half of current data stream
    // right saves the right half of current data stream
    priority_queue<long long> left, right;
};

int main() {

}