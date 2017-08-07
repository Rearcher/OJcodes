// 133. Clone Graph
#include "leetcode.hpp"
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        queue<UndirectedGraphNode*> q;
        unordered_map<int, UndirectedGraphNode*> map;
        unordered_set<int> visited;

        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode *tmp = q.front();
            q.pop();

            if (visited.count(tmp->label)) continue;
            visited.insert(tmp->label);

            if (!map.count(tmp->label)) {
                UndirectedGraphNode *copy = new UndirectedGraphNode(tmp->label);
                map[tmp->label] = copy;
            }

            for (UndirectedGraphNode *neig : tmp->neighbors) {
                if (!map.count(neig->label)) map[neig->label] = new UndirectedGraphNode(neig->label);
                map[tmp->label]->neighbors.push_back(map[neig->label]);

                if (!visited.count(neig->label)) q.push(neig);
            }
        }

        return map[node->label];
    }
};

int main() {

}