// 855. Exam Room
#include "leetcode.hpp"
using namespace std;

class ExamRoom {
public:
    ExamRoom(int N) {
        this->N = N;
    }
    
    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }
        
        int dist = *seats.begin(), last = *seats.begin();
        int res = 0;
        for (auto it = seats.begin(); it != seats.end(); ++it) {
            int cur = (*it - last) / 2;
            if (cur > dist) {
                res = last + cur;
                dist = cur;
            }
            last = *it;
        }
        
        int cur = N - 1 - last;
        if (cur > dist) res = N - 1;
        
        seats.insert(res);
        return res;
    }
    
    void leave(int p) {
        seats.erase(p);
    }
    
private:
    set<int> seats;
    int N;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */