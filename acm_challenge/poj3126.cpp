#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAX_N = 10005;
bool is_prime[MAX_N];
int visited[MAX_N];

void sieve(int n) {
    for (int i = 0; i <= n; ++i) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = 2 * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

int main() {
    sieve(MAX_N);

    int n;
    string a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        if (a == b) {
            cout << "0\n";
            continue;
        }

        fill(visited, visited + MAX_N, false);
        queue<pair<string, int>> que;
        que.push(pair<string, int>(a, 0));
        visited[atoi(a.c_str())] = true;

        int res = -1;
        while (!que.empty()) {
            pair<string, int> cur = que.front();
            que.pop();

            if (cur.first == b) {
                res = cur.second;
                break;
            }

            for (int i = 0; i < 4; ++i) {
                string next = cur.first;
                for (int j = (i == 0 ? 1 : 0); j <= 9; ++j) {
                    if (next[i] == '0' + j) continue;
                    next[i] = '0' + j;

                    int next_num = atoi(next.c_str());
                    if (is_prime[next_num] && !visited[next_num]) {
                        que.push(pair<string, int>(next, cur.second + 1));
                        visited[next_num] = true;
                    }
                }
            }
        }
        cout << res << "\n";
    }
}