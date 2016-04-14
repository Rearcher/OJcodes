// word pattern
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> hashMap1;
        unordered_map<string, char> hashMap2;
        
        vector<string> strVec;
        string temp;
        
        stringstream ss(str);
        while (ss >> temp) {
            strVec.push_back(temp);
        }
        
        if (strVec.size() != pattern.size()) return false;
        
        for (int i = 0; i < pattern.size(); ++i) {
            if (hashMap1.find(pattern[i]) == hashMap1.end()) {
                if (hashMap2.find(strVec[i]) == hashMap2.end()) {
                    hashMap1.insert(pair<char, string>(pattern[i], strVec[i]));
                    hashMap2.insert(pair<string, char>(strVec[i], pattern[i]));
                } else {
                    return false;
                }
            } else if (strVec[i] != hashMap1[pattern[i]]) {
                return false;
            }
        }
        return true;
    }
};
