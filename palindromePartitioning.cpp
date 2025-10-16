/*
    given a string s, partition s such that every substring of the partition is a palindrome. return all possible palindrome partitioning of s
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    vector<vector<string>> res;
    vector<string> path;

    bool isPalindrome(string &s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }

    void backtrack(string &s, int start){
        if(start == s.size()){
            res.push_back(path);
            return;
        }
        for(int end = start; end < s.size(); end++){
            if(isPalindrome(s, start, end)){
                path.push_back(s.substr(start, end- start + 1));
                backtrack(s, end+1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s){
        backtrack(s, 0);
        return res;
    }
};
int main(){
    Solution sol;
    string s = "aab";
    vector<vector<string>> ans = sol.partition(s);

    cout<<"[";
   for (auto &vec : ans) {
        cout << "[ ";
        for (auto &str : vec)
            cout << str << " ";
        cout << "]";
    }cout<<endl;
    return 0;
}
