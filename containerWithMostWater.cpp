#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int maxArea(vector<int>& height){
        int maxWater = 0;
        int leftpointer = 0, rightpointer = height.size() - 1;

        while(leftpointer < rightpointer){
            int currWidth = rightpointer - leftpointer;
            int currHeight = min(height[leftpointer], height[rightpointer]);
            int currWater = currWidth * currHeight;
            maxWater = max(maxWater, currWater);

            height[leftpointer] < height[rightpointer] ? leftpointer ++ : rightpointer --;
        }

        return maxWater;
    }
};
int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    Solution s;
    int result = s.maxArea(height);
    cout<<result<<endl;
    return 0;
}
