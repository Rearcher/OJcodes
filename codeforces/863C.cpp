#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int judge(int a, int b) {
    if (a == b) return 0;
    if (a == b + 1 || a + 2 == b) return 1;
    return -1;
}

int main() {
    vector<vector<int>> A(4, vector<int>(4, 0));
    vector<vector<int>> B(4, vector<int>(4, 0));

    long long k;
    int a, b, t;
    cin >> k >> a >> b;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cin >> t;
            A[i][j] = t;
        }
    }
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cin >> t;
            B[i][j] = t;
        }
    }

    vector<int> points;
    unordered_map<string, int> m;
    points.push_back(judge(a, b));
    m[to_string(a) + "," + to_string(b)] = 0;

    long long len, scoreA = 0, scoreB = 0, begin = 0;
    for (long long i = 1; i <= k; ++i) {
        int newA = A[a][b], newB = B[a][b];
        string key = to_string(newA) + "," + to_string(newB);
        if (m.count(key)) {
            for (int j = m[key]; j < i + 1; ++j) {
                if (points[j] == 1) scoreA += 1;
                else if (points[j] == -1) scoreB += 1;
            }
            len = i - m[key];
            begin = m[key];
            break;
        }

        points.push_back(judge(newA, newB));
        m[key] = points.size() - 1;
        a = newA, b = newB;
    }

    long long cntA = 0, cntB = 0;
    if (k <= begin) {
        for (long long i = 0; i < k; ++i) {
            if (points[i] == 1) cntA += 1;
            else if (points[i] == -1) cntB += 1;
        }
        cout << cntA << " " << cntB << endl;
    } else {
        for (long long i = 0; i < begin; ++i) {
            if (points[i] == 1) cntA += 1;
            else if (points[i] == -1) cntB += 1;
        }

        long long repeat = (k - begin) / len;
        cntA += repeat * scoreA;
        cntB += repeat * scoreB;

        long long left = (k - begin) % len;
        for (long long i = begin; i < begin + left; ++i) {
            if (points[i] == 1) cntA += 1;
            else if (points[i] == -1) cntB += 1;
        }
        cout << cntA << " " << cntB << endl;
    }

    return 0;
}