#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

pair<int, int> cows[2505], bottles[2505];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    int c, l;
    scanf("%d%d", &c, &l);
    for (int i = 0; i < c; ++i) scanf("%d%d", &cows[i].first, &cows[i].second);
    for (int i = 0; i < l; ++i) scanf("%d%d", &bottles[i].first, &bottles[i].second);
    sort(cows, cows + c);
    sort(bottles, bottles + l);

    int i = 0, res = 0;
    for (int j = 0; j < l; ++j) {
        while (i < c && cows[i].first <= bottles[j].first) {
            pq.push(cows[i].second);
            i++;
        }

        while (!pq.empty() && bottles[j].second) {
            int x = pq.top(); pq.pop();
            if (x >= bottles[j].first) {
                res++;
                bottles[j].second--;
            }
        }
    }
    printf("%d\n", res);
}