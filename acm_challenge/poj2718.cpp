#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        string line;
        getline(cin, line);
        line.erase(remove(line.begin(), line.end(), ' '), line.end());

        int res = 0x3fffffff;
        int len = line.size();
        int cut = len / 2, permute = 1 << len;
        set<string> visited;

        do {
            bitset<10> used(permute);
            string s1 = "", s2 = "";
            for (int i = 0; i < len; ++i) {
                if (used[i]) s1 += line[i];
                else s2 += line[i];
            }

            if (s1.size() != cut) continue;
            if (visited.count(s1)) continue;
            visited.insert(s2);

            do {
                if (s1[0] == '0' && s1.size() > 1) continue;
                int n1 = atoi(s1.c_str());
                do {
                    if (s2[0] == '0' && s2.size() > 1) continue;
                    int n2 = atoi(s2.c_str());
                    res = min(res, (int)abs(n1 - n2));

                } while (next_permutation(s2.begin(), s2.end()));
            } while (next_permutation(s1.begin(), s1.end()));
            
        } while (--permute);

        cout << res << endl;
    }
    return 0;
}