// isomorphic
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hashMap1, hashMap2;
        int i = -1;
        while (++i < s.size()) {
            if (hashMap1.find(s[i]) == hashMap1.end()) {
                if (hashMap2.find(t[i]) == hashMap2.end()) {
                    hashMap1.insert(pair<char,char>(s[i],t[i]));
                    hashMap2.insert(pair<char,char>(t[i],s[i]));
                } else {
                    return false;
                }
            } else if (hashMap1[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};
