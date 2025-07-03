#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int singleNum(vector<int>& nums){
        int result = 0;
        for(int num : nums){
            result ^= num;    //XOR operation
        } 
    return result;
    }
};


int main(){
    vector<int> nums = {4,1,2,1,2};

    Solution sol;
    cout<<"The number occuring once is: "<<sol.singleNum(nums)<<endl; 
    return 0;
}
