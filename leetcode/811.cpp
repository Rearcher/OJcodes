// 811. Subdomain Visit Count
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> cnt;
        for (string domain : cpdomains) {
            int i = 0;
            while (i < domain.size() && domain[i] != ' ') i++;
            i++;

            int num = stoi(domain.substr(0, i));
            cnt[domain.substr(i)] += num;
            while (i < domain.size()) {
                while (i < domain.size() && domain[i] != '.') i++;
                i++;
                if (i < domain.size())
                    cnt[domain.substr(i)] += num;
            }
        }
        
        vector<string> result;
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            string temp = to_string(it->second) + " " + it->first;
            result.push_back(temp);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> cpdomains{"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    vector<string> res = s.subdomainVisits(cpdomains);
    for (auto r : res) cout << r << "\n";
}