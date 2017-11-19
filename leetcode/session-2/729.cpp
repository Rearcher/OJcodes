// 729. My Calendar I
#include "leetcode.hpp"
using namespace std;

class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if (m.empty()) {
            m[start] = end;
            return true;
        }

        auto iter = m.lower_bound(start);
        if (iter != m.end() && iter->first < end) return false;
        if (iter != m.begin()) {
            --iter;
            if (iter->second > start) return false;
        }

        m[start] = end;
        return true;
    }

private:
    map<int, int> m;
};

int main() {
    MyCalendar c;
    cout << c.book(10, 20) << endl;
    cout << c.book(15, 25) << endl;
    cout << c.book(20, 30) << endl;
}