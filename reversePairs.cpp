#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int reversePairs(vector<int>& nums){
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int>& nums, int left, int right){
        if(left >= right) return 0;

        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);

        int j = mid + 1;
        for(int i = left; i<= mid; i++){
            while(j <= right && (long long)nums[i] > 2LL * nums[j])
                j++;
            count += (j - (mid + 1));
        }

        merge(nums, left, mid, right);

        return count;
    }

    void merge(vector<int>& nums, int left, int mid, int right){
        vector<int> temp;
        int i = left, j = mid + 1;

        while(i <= mid && j <= right){
            if(nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }

        while(i <= mid) temp.push_back(nums[i++]);
        while(j <= right) temp.push_back(nums[j++]);

        for(int k = left; k <= right; k++)
            nums[k] = temp[k - left];
    }
};
int main(){
    vector<int> nums ={1,3,2,3,1};
    Solution sol;
    cout<<sol.reversePairs(nums)<<endl;
    return 0;
}
