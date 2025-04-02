#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = 0;
        int curr_num = 1e4 + 1;
        int repeat = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != curr_num) {
                nums[curr] = nums[i];
                curr_num = nums[curr];
                repeat = 1;
                curr++;
            } else if (repeat == 1) {
                nums[curr] = nums[i];
                repeat = 2;
                curr++;
            } 
        }
        return curr;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = solution.removeDuplicates(nums1);
    cout << "Input: nums = [1,1,1,2,2,3]" << endl;
    cout << "Output: " << k1 << ", nums = [";
    for (int i = 0; i < k1; i++) {
        cout << nums1[i] << (i < k1 - 1 ? "," : "");
    }
    for (int i = k1; i < nums1.size(); i++) {
        cout << ",_";
    }
    cout << "]" << endl;

    // Test case 2
    vector<int> nums2 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int k2 = solution.removeDuplicates(nums2);
    cout << "Input: nums = [0,0,1,1,1,1,2,3,3]" << endl;
    cout << "Output: " << k2 << ", nums = [";
    for (int i = 0; i < k2; i++) {
        cout << nums2[i] << (i < k2 - 1 ? "," : "");
    }
    for (int i = k2; i < nums2.size(); i++) {
        cout << ",_";
    }
    cout << "]" << endl;

    return 0;
}
