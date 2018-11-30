    #include <iostream>
    #include <string>
    #include <set>
    #include <algorithm>
    using namespace std;

    typedef pair<char, int> p;

    int main() {
        freopen("input", "r", stdin);

        string s;
        int k;
        cin >> k >> s;

        int n = s.size();
        set<p> heap;
        for (int i = 0; i <= n - k; ++i)
            heap.insert({s[i], i});
        
        string res = "";
        int l = 0, r = n - k;
        for (int i = 0; i < k; ++i) {
            p tmp = *heap.begin();
            res.push_back(tmp.first);

            for (int j = l; j <= tmp.second; ++j)
                heap.erase({s[j], j});
            if (++r < n) 
                heap.insert({s[r], r});
            l = tmp.second + 1;
        }
        cout << res << "\n";
    }