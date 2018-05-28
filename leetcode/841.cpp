#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(rooms, visited, 0, n);
        return n == 0;
    }

private:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int room, int& cnt) {
        visited[room] = true;
        cnt -= 1;

        for (int next : rooms[room]) {
            if (!visited[next])
                dfs(rooms, visited, next, cnt);
        }
    }
};

int main() {
    
}