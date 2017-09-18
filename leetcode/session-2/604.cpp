// 604. Design Compressed String Iterator
#include "leetcode.hpp"
using namespace std;

class StringIterator {
public:
    StringIterator(string compressedString) {
        str = compressedString;
        count = position = mark = 0;
        newAlpha = true;
    }

    char next() {
        char result = ' ';
        if (!hasNext()) return result;

        if (newAlpha) {
            mark = position + 1;
            int cnt = 0;
            while (mark < str.length() && isdigit(str[mark])) {
                cnt = cnt * 10 + (str[mark] - '0');
                mark++;
            }
            count = cnt - 1;
            newAlpha = false;
            result = str[position];
        } else {
            if (count > 0) {
                count -= 1;
                result = str[position];
            } else if (count == 0) {
                newAlpha = true;
                position = mark;
                result = next();
            }
        }

        return result;
    }

    bool hasNext() {
        return count > 0 ? position < str.length() : mark < str.length();
    }

private:
    string str;
    int count, position, mark;
    bool newAlpha;
};

int main() {
    StringIterator obj = StringIterator("X6");
    while (obj.hasNext()) {
        cout << obj.next();
    }
    cout << endl;
}