#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
  bool isAnagram(string s, string t){
    if(s.size() != t.size())  return false;

    vector<int> count(26, 0);
    for(char c : s) count[c-'a']++;
    for(char c : t) count[c-'a']--;

    for(int i : count){
      if(i != 0) return false;
    }
    return true;
  }
};
int main(){
  string s = "anagram";
  string t = "nagaram";
  Solution sol;
  if(sol.isAnagram(s, t)){
    cout<<"Valid Anagram"<<endl;
  }else{
    cout<<"Not a Valid Anagram"<<endl;
  }
return 0;
}
