#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<string> cache;
    string word;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> word;
        string reverse_word = word;
        reverse(reverse_word.begin(), reverse_word.end());
        if (cache.count(reverse_word)) res += 1;
        cache.insert(word);
    }
    
    cout << res << "\n";
    return 0;
}