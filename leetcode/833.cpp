// 833. Find And Replace in String
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        if (indexes.empty()) return S;
        
        vector<pair<int, pair<string, string>>> infos(indexes.size());
        for (int i = 0; i < indexes.size(); ++i) {
            infos[i] = {indexes[i], {sources[i], targets[i]}};    
        }
        sort(infos.begin(), infos.end());
        
        string res = (infos[0].first > 0) ? S.substr(0, infos[0].first) : "";
        
        for (int j = 0; j < infos.size(); ++j) {
            int i = infos[j].first;
            string source = infos[j].second.first;
            string target = infos[j].second.second;
            
            int len = source.size();
            if (S.substr(i, len) == source) {
                res += target;
                i += len;
            }
            
            int limit = (j == infos.size() - 1) ? S.size() : infos[j + 1].first;
            res += S.substr(i, limit - i);
        }
        return res;
    }
};