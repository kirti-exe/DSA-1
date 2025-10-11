#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void backtrack(int i, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result){
        if(target == 0){
            result.push_back(current);
            return;
        }
        if(i >= candidates.size() || target < 0) return;
        current.push_back(candidates[i]);
        backtrack(i, candidates, target - candidates[i], current, result);
        current.pop_back();

        backtrack(i+1, candidates, target, current, result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, candidates, target, current, result);
        return result;
    }
};
int main(){
    vector<int> candidates = {2,3,5};
    int target = 8;
    Solution sol;
    
    vector<vector<int>> ans = sol.combinationSum(candidates, target);

    cout<<"Combiantions that sum to "<<target<<":\n";
    for(auto& vec: ans){
        cout<<"[ ";
        for(int num: vec) cout<<num<<" ";
        cout<<"]\n";
    }
    return 0;
}
