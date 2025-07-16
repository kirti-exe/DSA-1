#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Time Complexity: O(n^3), Space Complexity: no space used
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicates for i

            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;  // Skip duplicates for j

                int k = j + 1;
                int l = n - 1;

                while(k < l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;

                        while(k < l && nums[k] == nums[k - 1]) k++;  // Skip duplicates for k
                        while(k < l && nums[l] == nums[l + 1]) l--;  // Skip duplicates for l
                    }
                    else if(sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target1 = 0;

    vector<int> arr2 = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5};
    int target2 = 8;

    Solution s;

    vector<vector<int>> result = s.fourSum(arr, target1);

    for(const auto& quad : result) {
        for(int num : quad)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}
