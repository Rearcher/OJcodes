// 715. Range Module
#include "leetcode.hpp"
using namespace std;

class RangeModule {
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto l = intervals.upper_bound(left), r = intervals.upper_bound(right);
        if (l != intervals.begin()) {
            l--;
            if (l->second < left) l++;
        }
        if (l != r) {
            left = min(left, l->first);
            right = max(right, (--r)->second);
            intervals.erase(l, ++r);
        }
        intervals[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto iter = intervals.upper_bound(left);
        if (iter == intervals.begin() || (--iter)->second < right) return false;
        return true;
    }
    
    void removeRange(int left, int right) {
        auto l = intervals.upper_bound(left), r = intervals.upper_bound(right);
        if (l != intervals.begin()) {
            l--;
            if (l->second < left) l++;
        }
        if (l == r) return;
        int l1 = min(left, l->first), r1 = max(right, (--r)->second);
        intervals.erase(l, ++r);
        if (l1 < left) intervals[l1] = left;
        if (r1 > right) intervals[right] = r1;
    }

private:
    map<int, int> intervals;
};

int main() {

}