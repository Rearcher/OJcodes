#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    string word;
    cin >> word;

    unordered_set<char> visited;
    vector<vector<char>> result(5, vector<char>(5));
    int x = 0, y = 0;

    for (int i = 0; i < word.size(); ++i) {
        char c = word[i];
        if (c == 'J') c = 'I';
        if (visited.count(c)) continue;

        result[x][y] = c;
        visited.insert(c);
        if (y + 1 == 5) {
            x += 1;
            y = 0;
        } else {
            y += 1;
        }
    }

    for (char c = 'A'; c <= 'Z'; ++c) {
        if (c == 'J' || visited.count(c)) continue;

        result[x][y] = c;
        visited.insert(c);
        if (y + 1 == 5) {
            x += 1;
            y = 0;
        } else {
            y += 1;
        }
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << result[i][j];
        }
        cout << "\n";
    }
}