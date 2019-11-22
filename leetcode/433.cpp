// medium
// #bfs
// #two-end bfs
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) return 0;
        
        unordered_set<string> valid(bank.begin(), bank.end());
        if (valid.find(end) == valid.end()) return -1;
        
        unordered_set<string> s1, s2, *p1, *p2;
        s1.insert(start);
        s2.insert(end);
        
        int res = 0, n = start.size();
        while (!s1.empty() && !s2.empty()) {
            if (s1.size() < s2.size()) p1 = &s1, p2 = &s2;
            else p1 = &s2, p2 = &s1;
            
            unordered_set<string> tmp;
            res++;
            for (auto iter = p1->begin(); iter != p1->end(); ++iter) {
                for (int i = 0; i < n; ++i) {
                    string cur = *iter;
                    for (auto c : string("ACGT")) {
                        cur[i] = c;
                        if (p2->count(cur)) return res;
                        if (valid.count(cur)) {
                            tmp.insert(cur);
                            valid.erase(cur);
                        }
                    }
                }
            }
            *p1 = tmp;
        }
        
        return -1;
    }
};