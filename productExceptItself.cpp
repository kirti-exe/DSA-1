#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n, 1);

        int prefix = 1;
        for(int i=0; i<n; ++i){
            ans[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for(int i =n-1; i>=0; --i){
            ans[i]*= suffix;
            suffix *= nums[i];
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};

    cout << "Input: ";
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;

    Solution sol;
    vector<int> ans = sol.productExceptSelf(nums);

    cout << "Output: ";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
