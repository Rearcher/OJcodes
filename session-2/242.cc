/* anagram */
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alpha(26, 0);
        
        for (auto c : s)
            alpha[c-'a']++;
        for (auto c : t)
            alpha[c-'a']--;
        
        for (auto n : alpha)
            if (n != 0) return false;
        
        return true;
    }
};
