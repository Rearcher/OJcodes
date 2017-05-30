// 492. construct the rectangle
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> result;
        int square_root = sqrt(area);

        if (area % square_root == 0) {
            result.push_back(area / square_root);
            result.push_back(square_root);
        } else {
            int width = square_root;
            while (width > 0 && area % width != 0) {
                width--;
            }
            result.push_back(area / width);
            result.push_back(width);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> result = s.constructRectangle(2);
    cout << result[0] << " " << result[1] << "\n";
}