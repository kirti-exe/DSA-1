#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string longestPrefix(string s){
        int n = s.size();
        vector<int> lps(n,0);    //longest prefix suffix array

        for(int i=1; i<n; i++){
            int len = lps[i-1];
            while(len > 0 && s[i] != s[len]){
                len = lps[len-1];
            }
            if(s[i]==s[len]){
                len++;
            }
            lps[i] = len;
        }
        return s.substr(0, lps[n-1]);
    }
};
int main(){
    Solution sol;
    string s = "level";
    cout<<"Longest happy prefix: "<<sol.longestPrefix(s)<<endl;
    return 0;
}
