#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n= matrix[0].size();
        int left = 0, right = m * n - 1;

        while(left<=right){
            int mid = left + (right - left)/2;
            int row = mid / n;
            int col = mid % n;
            int val = matrix[row][col];

            if(val == target) return true;
            else if (val < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> matrix = {
        {3, 4, 7, 9}, 
        {12, 13, 16, 18},
        {20, 21, 23, 29}
        };
    
    int target = 23;

    if(sol.searchMatrix(matrix, target)){
        cout<<"Target "<<target<<" found in matrix."<<endl;
    } else {
        cout<<"Target "<<target<<" not found in matrix."<<endl;
    }

    return 0;
}
