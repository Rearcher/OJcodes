// 468. Validate IP Address
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        string result = "Neither";
        if (IP.size() > 39) return result;

        string::size_type hasDot = IP.find('.');
        string::size_type hasColon = IP.find(':');

        if ((hasDot == string::npos && hasColon == string::npos) || 
            (hasDot != string::npos && hasColon != string::npos))
            return result;

        if (hasDot != string::npos && validIPv4(IP))
            result = "IPv4";
        
        if (hasColon != string::npos && validIPv6(IP))
            result = "IPv6";

        return result;
    }

private:
    bool validIPv4(string IP) {
        stringstream ss(IP);
        int count = 0;
        string tmp;

        while (getline(ss, tmp, '.')) {
            if (IP.back() == '.') return false;

            count += 1;
            if (count > 4) return false;
            if (tmp.empty() || tmp.size() > 3) return false;
            int i = 0;
            while (i < tmp.size() && tmp[i] == '0') i++;
            if (i > 0 && tmp != "0") return false;

            i = 0;
            int number = 0;
            while (i < tmp.size()) {
                if (!isdigit(tmp[i])) return false;
                number = number * 10 + (tmp[i] - '0');
                i++;
            }
            if (number > 255) return false;
        }

        return count == 4;
    }

    bool validIPv6(string IP) {
        if (IP.back() == ':') return false;

        stringstream ss(IP);
        int count = 0;
        string tmp;

        while (getline(ss, tmp, ':')) {
            count += 1;
            if (count > 8) return false;
            if (tmp.empty() || tmp.size() > 4) return false;
            
            int i = 0;
            while (i < tmp.size()) {
                if (isdigit(tmp[i]) || (tmp[i] >= 'a' && tmp[i] <= 'f') || (tmp[i] >= 'A' && tmp[i] <= 'F')) {
                    i++;
                    continue;
                }
                return false;
            }
        }

        return count == 8;
    }
};

int main() {
    Solution s;
    // cout << s.validIPAddress("172.16.254.1") << endl;
    // cout << s.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334") << endl;
    // cout << s.validIPAddress("256.256.256.256") << endl;
    // cout << s.validIPAddress("2001:0db8:85a3::8A2E:0370:7334") << endl;
    // cout << s.validIPAddress("02001:0db8:85a3:0000:0000:8a2e:0370:7334") << endl;
    // cout << s.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334:") << endl;
    cout << s.validIPAddress("192.0.0.1") << endl;
}