#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double eps = 1e-8;

// 高斯消元法
void gaussian_elimination(vector<vector<double>>& coef, vector<double>& val) {
    int m = coef.size(), n = coef[0].size();

    // 将系数矩阵化为上三角矩阵
    for (int j = 0; j < n; ++j) {
        // 从j到m-1行中，寻找某一行的第j个元素不为0的行
        for (int i = j; i < m; ++i) {
            if (coef[i][j] != 0) {
                swap(coef[i], coef[j]);
                break;
            }
        }

        // 从j+1到m-1行，采用初等行变换消除每行的第j个元素，使其为0
        for (int i = j + 1; i < m; ++i) {
            double tmp = coef[i][j] / coef[j][j];
            // coef[i][j] = 0;
            for (int k = j; k < n; ++k) {
                coef[i][k] -= coef[j][k] * tmp;
            }
            val[i] -= val[j] * tmp;
        }
    }

    vector<double> ans(n, 0);
    // 计算值
    // 由于每一行都比前一行少一个系数，所以在m行中只有n行有系数
    for (int i = n - 1; i >= 0; --i) {
        // 利用已经计算出的结果，将第i行中的i+1至n-1列的值消除
        for (int j = i + 1; j < n; ++j) {
            val[i] -= coef[i][j] * ans[j];
            coef[i][j] = 0;
        }
        ans[i] = val[i] / coef[i][i];
    }

    int d = sqrt(ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        double tmp = ans[i];
        int v = tmp > eps ? (int)(tmp + 0.5) : (int)(tmp - 0.5);

        cout << v;
        if ((i + 1) % d == 0) cout << "\n";
        else cout << " ";
    }

    return;
}

int main() {
    int h, w, d;
    cin >> h >> w >> d;

    vector<vector<int>> a(h, vector<int>(w, 0));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    vector<double> b((h - d + 1) * (w - d + 1), 0);
    for (int i = 0; i < b.size(); ++i) 
        cin >> b[i];

    vector<vector<double>> matrix;
    for (int i = 0; i < h - d + 1; ++i) {
        for (int j = 0; j < w - d + 1; ++j) {
            vector<double> tmp;
            for (int dx = i; dx < i + d; ++dx)
                for (int dy = j; dy < j + d; ++dy)
                    tmp.push_back(a[dx][dy]);
            matrix.push_back(tmp);
        }
    }

    gaussian_elimination(matrix, b);
    return 0;
}