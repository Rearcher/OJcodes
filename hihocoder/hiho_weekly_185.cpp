// hiho一下，第185周
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(int N, int M, vector<int>& A, vector<int>& B, vector<vector<bool>>& waters, pair<int, int> start, pair<int, int> target) {
    auto cmp = [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
        return a.first > b.first;
    };
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> pq(cmp);
    pq.push({0, start});

    vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> visited(N + 1, vector<bool>(M + 1, false));
    while (!pq.empty()) {
        int dist = pq.top().first;
        pair<int, int> pos = pq.top().second;
        pq.pop();

        if (visited[pos.first][pos.second]) continue;        
        visited[pos.first][pos.second] = true;

        for (int i = 0; i < dirs.size(); ++i) {
            int newX = pos.first + dirs[i].first;
            int newY = pos.second + dirs[i].second;
            if (newX < 1 || newX > N || newY < 1 || newY > M) continue;
            if (visited[newX][newY] || waters[newX][newY]) continue;

            int newDist = dist;
            if (i == 0) newDist += B[pos.first];
            else if (i == 1) newDist += B[pos.first - 1];
            else if (i == 2) newDist += A[pos.second];
            else if (i == 3) newDist += A[pos.second - 1];

            if (newX == target.first && newY == target.second) return newDist;
            pq.push({newDist, {newX, newY}});
        }
    }
    return -1;
}

int main() {
    // freopen("hihocoder/input.txt", "r", stdin);

    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(N);
    for (int i = 1; i < N; ++i) cin >> B[i];
    for (int i = 1; i < M; ++i) cin >> A[i];

    int K;
    cin >> K;
    vector<vector<bool>> waters(N + 1, vector<bool>(M + 1, false));
    for (int i = 0; i < K; ++i) {
        int a, b;
        cin >> a >> b;
        waters[a][b] = true;
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        cout << bfs(N, M, A, B, waters, {x, y}, {p, q}) << "\n";
    }
}