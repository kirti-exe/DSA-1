// Find the largest sum of contiguous subarray (Kadane's Algorithm)

#include<iostream>
#include<vector>

using namespace std;

int maxSubarraySum(vector<int>& nums){
    int maxSum = INT32_MIN;
    int currentSum = 0;

    for(int num : nums){
        currentSum = max(num, currentSum + num);

        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main(){
    vector<int> arr  = {2,1,-3,4,-1,2,1,-5,4};
    cout<<"Maximum Subarray Sum: "<<maxSubarraySum(arr)<<endl;   
    return 0;
}
