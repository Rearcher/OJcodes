// 635. Design Log Storage System
#include "leetcode.hpp"
using namespace std;

class LogSystem {
public:
    LogSystem() {
        gras = {"Year", "Month", "Day", "Hour", "Minute", "Second"};
        idx = {4, 7, 10, 13, 16, 19};
    }

    void put(int id, string timestamp) {
        timestamps.push_back({to_string(id), timestamp});
    }

    vector<int> retrieve(string s, string e, string gra) {
        vector<int> result;
        int gra_idx = 0;
        while (gras[gra_idx] != gra) 
            gra_idx += 1;
        
        int index = idx[gra_idx];
        for (auto timestamp : timestamps) {
            if (timestamp[1].substr(0, index) >= s.substr(0, index) && timestamp[1].substr(0, index) <= e.substr(0, index))
                result.push_back(stoi(timestamp[0]));
        }

        return result;
    }

private:
    vector<string> gras;
    vector<int> idx;
    vector<vector<string>> timestamps;
};

int main() {
    
}