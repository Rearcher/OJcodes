class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > a;
        vector<int> b(200, 0);
        for(int i=0; i<m+n; i++) a.push_back(b);
        for(int i=0; i<m+n; i++) {
            a[i][i] = 1;
            a[i][0] = 1;
        }
        for(int i=2; i<m+n; i++)
            for(int j=1; j<i; j++)
                a[i][j] = a[i-1][j-1]+a[i-1][j];
        return a[m+n-2][m-1];
    }   

};
