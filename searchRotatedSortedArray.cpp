#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int search(vector<int>& nums, int target){
        int i = 0;
        int r = nums.size() - 1;

        while( i <= r){
            int mid = i + (r - i)/2;
            if(nums[mid] == target) return mid;

            if(nums[i] <= nums[mid]){
                //left half is sorted
                if(nums[i] <= target && target < nums[mid]){
                    r = mid - 1;
                } else {
                    i = mid + 1;
                }
            } else {
                //right half is sorted
                if(nums[mid] < target && target <= nums[r]){
                    i = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main(){
    vector<int> arr = {7,8,9,1,2,3,4,5,6};
    int target = 1;

    Solution sol;
    int index = sol.search(arr, target);

    if(index != -1){
        cout<<"Target found at Index: "<<index<<endl;
    } else {
        cout<<"Target not found. "<<endl;
    }
    return 0;
}
