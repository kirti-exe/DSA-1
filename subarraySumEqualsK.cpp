#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumFreq;
        prefixSumFreq[0] = 1; // Initialize with sum 0 to handle sum from start
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;
            if (prefixSumFreq.find(sum - k) != prefixSumFreq.end()) {
                count += prefixSumFreq[sum - k];
            }
            prefixSumFreq[sum]++;
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1}; // Example input
    int k = 2;
    cout << "Number of subarrays with sum " << k << " = " << sol.subarraySum(nums, k) << endl;
    return 0;
}
