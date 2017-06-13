// 535. Encode and Decode TinyURL
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    Solution() {
        for (int i = 0; i < 26; ++i) {
            alphabet.push_back('a' + i);
            alphabet.push_back('A' + i);
            if (i < 10) {
                alphabet.push_back('0' + i);
            }

            encodeMap.clear();
            decodeMap.clear();
            srand(time(0));
        }
    }

    string encode(string longUrl) {
        if (encodeMap.count(longUrl))
            return encodeMap[longUrl];

        string code = generate();
        while (decodeMap.count(code)) {
            code = generate();
        }
        
        encodeMap[longUrl] = code;
        decodeMap[code] = longUrl;

        return "http://tinyurl.com/" + code;
    }

    string decode(string shortUrl) {
        return decodeMap[shortUrl.substr(19)];
    }

private:
    vector<char> alphabet;
    unordered_map<string, string> encodeMap, decodeMap;

    string generate() {
        string code = "";
        for (int i = 0; i < 6; ++i) {
            int idx = rand() % alphabet.size() + 1;
            code.push_back(alphabet[idx]);
        }
        return code;
    }
};

int main() {
    Solution s;
    string url = "https://leetcode.com/problems/design-tinyurl";
    string short_url = s.encode(url);
    string long_url = s.decode(short_url);
    cout << url << "\n" << short_url << "\n" << long_url << "\n";
}