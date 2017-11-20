// 731. My Calendar II
#include "leetcode.hpp"
using namespace std;

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (auto it = m.lower_bound(start); it != m.end() && it->first < end; ++it) 
            if (it->second >= 2) return false;
        
        int cnt = 0;
        for (auto p : v) 
            if (p.first <= start && p.second > start)
                cnt++;
        if (cnt >= 2) return false;
        for (auto it = m.lower_bound(start); it != m.end() && it->first < end; ++it)
            ++it->second;
        m[start] = cnt + 1;
        v.push_back({start, end});
        return true;
    }

private:
    map<int, int> m;
    vector<pair<int, int>> v;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */

int main() {
    MyCalendarTwo c;
    cout << c.book(10, 20) << endl;
    cout << c.book(50, 60) << endl;
    cout << c.book(10, 40) << endl;
    cout << c.book(5, 15) << endl;
    cout << c.book(5, 10) << endl;
    cout << c.book(25, 55) << endl;    
}