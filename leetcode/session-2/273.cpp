// 273. Integer to English Words
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        int i = 0;
        string words = "";

        while (num > 0) {
            if (num % 1000 != 0) {
                words = helper(num % 1000) + thousands[i] + " " + words;
            }
            num /= 1000;
            i++;
        }

        while (words.size() && words.back() == ' ') words.pop_back();
        return words;
    }

private:
    string helper(int num) {
        if (num == 0) return "";
        else if (num < 20) return below20[num] + " ";
        else if (num < 100) return below100[num / 10] + " " + helper(num % 10);
        else return below20[num / 100] + " Hundred " + helper(num % 100); 
    }

    static vector<string> below20;
    static vector<string> below100;
    static vector<string> thousands;
};

vector<string> Solution::below20 = vector<string>{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> Solution::below100 = vector<string>{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
vector<string> Solution::thousands = vector<string>{"", "Thousand", "Million", "Billion"};

int main() {
    Solution s;
    cout << s.numberToWords(1234567) << endl;
}