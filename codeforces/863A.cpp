#include <iostream>
#include <string>
using namespace std;

int main() {
    int x;
    cin >> x;

    string str = to_string(x);
    int i = 0, j = str.size() - 1;
    while (j > i && str[j] == '0') j--;
    while (i < j) {
        if (str[i++] != str[j--]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}