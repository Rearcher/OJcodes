// 126. Word Ladder II
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        unordered_map<string, vector<string>> nodeNeighbours;
        unordered_map<string, int> distance;

        vector<string> sub;
        vector<vector<string>> result;

        for (string word : wordList) dict.insert(word);
        dict.insert(beginWord);
        bfs(beginWord, endWord, dict, nodeNeighbours, distance);
        dfs(beginWord, endWord, dict, nodeNeighbours, distance, sub, result);

        return result;
    }

private:
    vector<string> getNeighbours(string node, unordered_set<string>& dict) {
        vector<string> result;
        for (int i = 0; i < node.size(); ++i) {
            for (int j = 0; j < 26; ++j) {
                char c = node[i];
                if (c == 'a' + j) continue;

                node[i] = 'a' + j;
                if (dict.count(node)) result.push_back(node);
                node[i] = c;
            }
        }
        return result;
    }

    void bfs(string begin, string end, unordered_set<string>& dict, unordered_map<string, vector<string>>& nodeNeighbours, unordered_map<string, int>& distance) {
        queue<string> q;
        q.push(begin);
        distance[begin] = 0;

        while (!q.empty()) {
            int cnt = q.size();
            bool reachEnd = false;

            for (int i = 0; i < cnt; ++i) {
                string cur = q.front();
                q.pop();

                int curDistance = distance[cur];
                vector<string> neighbours = getNeighbours(cur, dict);
                for (string neig : neighbours) {
                    nodeNeighbours[cur].push_back(neig);
                    if (!distance.count(neig)) {
                        distance[neig] = curDistance + 1;
                        if (end == neig) reachEnd = true;
                        else q.push(neig);
                    }
                }

                if (reachEnd) break;
            }
        }
    }

    void dfs(string cur, string end, unordered_set<string>& dict, unordered_map<string, vector<string>>& nodeNeighbours, unordered_map<string, int>& distance, vector<string>& sub, vector<vector<string>>& result) {
        sub.push_back(cur);
        if (end == cur) {
            result.push_back(vector<string>(sub));
        } else {
            for (string neig : nodeNeighbours[cur]) 
                if (distance[neig] == distance[cur] + 1) dfs(neig, end, dict, nodeNeighbours, distance, sub, result);
        }
        sub.pop_back();
    }
};

int main() {

}