#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int quick_pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    // freopen("input", "r", stdin);
    string line;
    while (cin >> line) {
        if (line == "0") break;
        
        line = line.substr(2, line.size() - 5);
        int len = line.size(), n = atoi(line.c_str());
        if (n == 0) {
            cout << "0/1\n";
            continue;
        }
        
        int t = quick_pow(10, len), min_numerator = -1, min_denominator = -1;
        for (int i = 0; i < len; ++i) {
            int first = (i == 0) ? 0 : atoi(line.substr(0, i).c_str());
            int numerator = n - first;
            int denominator = t - quick_pow(10, i);
            int d = gcd(denominator, numerator);

            numerator /= d;
            denominator /= d;

            if (min_denominator == -1 || denominator < min_denominator) {
                min_numerator = numerator;
                min_denominator = denominator;
            }
        }
        cout << min_numerator << "/" << min_denominator << "\n";
    }
}