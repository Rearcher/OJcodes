/* majority element */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0;
        int candidate;
        for (auto num : nums) {
            if (counter == 0) {
                candidate = num;
                counter++;
            }
            else if (candidate == num) counter++;
            else counter--;
        }
        return candidate;
    }
};
