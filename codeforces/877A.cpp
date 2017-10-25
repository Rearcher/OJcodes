#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> names{"Danil", "Olya", "Slava", "Ann", "Nikita"};
    string line;
    cin >> line;

    int i = 0, flag = 0;
    while (i < line.size()) {
        bool step = true;
        for (int j = 0; j < 5; ++j) {
            if (i + names[j].size() <= line.size() && names[j] == line.substr(i, names[j].size())) {
                if (flag) {
                    cout << "NO\n";
                    return 0;
                }
                i += names[j].size();
                flag = 1;
                step = false;
                break;
            }
        }

        if (step) i++;
    }

    if (flag) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}