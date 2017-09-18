// 592. Fraction Addition and Subtraction
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        int begin = 0, end = 0;
        vector<long long> result{0, 0};

        while (begin < expression.size()) {
            if (end > 0 && (end >= expression.size() || expression[end] == '+' || expression[end] == '-')) {
                cout << "current fraction: " << expression.substr(begin, end - begin) << endl;
                vector<long long> f = parse(expression.substr(begin, end - begin));
                cout << "current parse: {" << f[0] << ", " << f[1] << "}" << endl;

                result = add(result, f);
                cout << "current result: {" << result[0] << ", " << result[1] << "}" << endl;
                begin = end;
            }
            end++;                         
        }


        string res;
        if (result[0] < 0 || result[1] < 0) {
            res += "-";
        }
        res += to_string(abs(result[0])) + "/" + to_string(abs(result[1]));
        return res;
    }

private:
    vector<long long> parse(string fraction) {
        vector<long long> result;
        int i = 0;

        while (i < fraction.size()) {
            if (fraction[i] == '/') {
                result.push_back(stoi(fraction.substr(0, i)));
                result.push_back(stoi(fraction.substr(i+1)));
                break;
            }
            i++;
        }

        return result;
    }

    vector<long long> add(vector<long long>& f1, vector<long long>& f2) {
        if (f1[0] == f1[1] && f1[0] == 0) {
            return f2;
        }

        long long curLcm = lcm(f1[1], f2[1]);
        
        f1[0] *= curLcm / f1[1];
        f2[0] *= curLcm / f2[1];

        long long tmp = f1[0] + f2[0];
        long long tmp_gcd = gcd(tmp, curLcm);

        return vector<long long>{tmp / tmp_gcd, curLcm / tmp_gcd};
    }

    // largest common divisor
    long long gcd(long long a, long long b) {
        long long m = max(a, b), n = min(a, b);
        while (n) {
            long long t = m % n;
            m = n;
            n = t;
        }
        return m;
    }

    // least common multiplier
    long long lcm(int a, int b) {
        long long result = a * b / gcd(a, b);
        return result;
    }
};

int main() {
    Solution s;
    cout << s.fractionAddition("1/3-1/2") << endl;
}