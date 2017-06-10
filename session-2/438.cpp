// 438. Find All Anagrams in a String
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.empty() || p.empty()) 
            return result;

        vector<int> hash(26, 0);
        for (char c : p)
            hash[c - 'a']++;

        int left = 0, right = 0, count = p.length();
        while (right < s.length()) {
            if (hash[s[right] - 'a'] >= 1) 
                count--;
            
            hash[s[right] - 'a'] -= 1;
            right += 1;

            if (count == 0)
                result.push_back(left);

            if (right - left == p.length()) {
                if (hash[s[left] - 'a'] >= 0)
                    count++;
                hash[s[left] - 'a'] += 1;
                left += 1;
            }
        } 

        return result;
    }
};

int main() {
    Solution s;
    vector<int> result = s.findAnagrams("abab", "ab");
    for (int a : result)
        cout << a << " ";
    cout << "\n";
}