#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int width = right - left;
            int currentHeight = min(height[left], height[right]);
            int currentArea = width * currentHeight;
            maxWater = max(maxWater, currentArea);

            // Move the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    Solution sol;
    int result = sol.maxArea(height);
    cout << "Maximum water container area: " << result << endl;

    return 0;
}
