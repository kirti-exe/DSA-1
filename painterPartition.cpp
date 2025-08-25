#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution{
public:
    bool isPossible(vector<int>& boards, int k, long long maxTime){
        long long currSum = 0;
        int painters = 1;

        for(int len : boards){
            if(len > maxTime)   return false;

            if(currSum + len <= maxTime){
                currSum += len;
            }else{
                painters++;
                currSum = len;

                if(painters > k) return false;
            }
        }
        return true;
    }

    int paintersPartition(vector<int>& boards, int k){
        long long low = *max_element(boards.begin(), boards.end());
        long long high = accumulate(boards.begin(), boards.end(), 0LL);
        long long ans = high;

        while(low <= high){
            long long mid = low + (high-low)/2;

            if(isPossible(boards, k, mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;

    Solution sol;
    cout<<"Minimum time required: "<<sol.paintersPartition(boards, k)<<endl;
    return 0;
}
