#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void backtrack(int start, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result){
        if(target == 0){
            result.push_back(current);
            return;
        }

        for(int i=start; i<candidates.size(); i++){
            if(i > start && candidates[i] == candidates[i-1]) continue;

            if(candidates[i] > target) break;

            current.push_back(candidates[i]);
            backtrack(i+1, candidates, target-candidates[i], current, result);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(0, candidates, target, current, result);
        return result;
    }
};
int main(){
    Solution sol;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = sol.combinationSum2(candidates, target);

    cout<<"Combinations that sum to "<<target<<":\n";
    for(auto& vec : ans){
        cout<<"[";
        for(int num : vec) cout<<num<<"";
        cout<<"]\n";
    }
    
    return 0;
}
