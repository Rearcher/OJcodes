// bulls and cows
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, vector<int>> hashMap;
        int cntA = 0, cntB = 0;
        
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                cntA++;
            } else {
                if (hashMap.find(secret[i]) != hashMap.end()) {
                    hashMap[secret[i]].push_back(i);
                } else {
                    hashMap.insert(pair<char, vector<int>>(secret[i], vector<int>()));
                    hashMap[secret[i]].push_back(i);
                }
            }
        }
        
        for (int i = 0; i < guess.size(); i++) {
            if (secret[i] != guess[i] && hashMap.find(guess[i]) != hashMap.end()) {
                if (hashMap[guess[i]].size() > 0) {
                    hashMap[guess[i]].pop_back();
                    cntB++;
                } else {
                    hashMap.erase(guess[i]);
                }
            }
        }
        
        string ans = "";
        ans += std::to_string(cntA);
        ans += "A";
        ans += std::to_string(cntB);
        ans += "B";
        
        return ans;
    }
};

// another solution
class Solution {
public:
    // only contains digits 
    string getHint(string secret, string guess) {
        int aCnt = 0;
        int bCnt = 0;
        vector<int> sVec(10, 0); // 0 ~ 9 for secret
        vector<int> gVec(10, 0); // 0 ~ 9 for guess 
        if (secret.size() != guess.size() || secret.empty()) { return "0A0B"; }
        for (int i = 0; i < secret.size(); ++i) {
            char c1 = secret[i]; char c2 = guess[i];
            if (c1 == c2) {
                ++aCnt; 
            } else {
                ++sVec[c1-'0'];
                ++gVec[c2-'0'];
            }
        }
        // count b 
        for (int i = 0; i < sVec.size(); ++i) {
            bCnt += min(sVec[i], gVec[i]);
        }
        return to_string(aCnt) + 'A' + to_string(bCnt) + 'B';
    }
};
