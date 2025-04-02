#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = 0; // Pointer for the position to place the next valid element
        int curr_num = 1e4 + 1; // Initialize with a value outside the range of nums
        int repeat = 0; // Counter to track the number of occurrences of the current number

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != curr_num) { // If the current number is different from the previous one
                nums[curr] = nums[i]; // Place the number at the current position
                curr_num = nums[curr]; // Update the current number
                repeat = 1; // Reset the repeat counter
                curr++; // Move the pointer
            } else if (repeat == 1) { // Allow at most two occurrences of the same number
                nums[curr] = nums[i]; // Place the number at the current position
                repeat = 2; // Update the repeat counter
                curr++; // Move the pointer
            }
        }
        return curr; // Return the length of the modified array
    }
};

void printArray(const vector<int>& nums, int k) {
    cout << "[";
    for (int i = 0; i < k; i++) {
        cout << nums[i];
        if (i < k - 1) {
            cout << ",";
        }
    }
    for (int i = k; i < nums.size(); i++) {
        cout << ",_";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;

    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    cout << "Input: nums = [1,1,1,2,2,3]" << endl;
    int k1 = solution.removeDuplicates(nums1);
    cout << "Output: " << k1 << ", nums = ";
    printArray(nums1, k1);

    vector<int> nums2 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << "Input: nums = [0,0,1,1,1,1,2,3,3]" << endl;
    int k2 = solution.removeDuplicates(nums2);
    cout << "Output: " << k2 << ", nums = ";
    printArray(nums2, k2);

    return 0;
}
