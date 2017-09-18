/* maximum product of word lengths */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int max = 0;
        if (n < 2) return max;
        
        vector<int> mask(n, 0);
        
        sort(words.begin(), words.end(), [](string a, string b){
           return a.length() > b.length();});
        
        for (int i = 0; i < n; i++) {
            for (auto c : words[i]) {
                mask[i] |= 1 << (c-'a');
            }
        }
        
        for (int i = 0; i < n-1; i++) {
            if (words[i].size() * words[i].size() <= max) break;
            for (int j = i+1; j < n; j++) {
                if ((mask[i]&mask[j])==0) {
                    max = std::max(max, (int)(words[i].length()*words[j].length()));
                    break;
                }
            }
        }
        
        return max;
    }
};

int main() {
	Solution s;
	vector<string> a{"abcw","baz","foo","bar","xtfn","abcdef"};
	cout << s.maxProduct(a) << endl;
}
