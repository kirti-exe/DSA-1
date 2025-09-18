#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
class Solution{
  public:
    string reverseWords(string s){
      string word, result;
      stringstream ss(s);

      vector<string> words;
      while(ss >> word){
        words.push_back(word);
      }

      reverse(words.begin(), words.end());
      for(int i=0; i<words.size(); i++){
        result += words[i];
        if(i != words.size()-1) result += " ";
      }
      return result;
    }
};
int main(){
    Solution sol;
    string s = " hello world ";
    cout<<sol.reverseWords(s)<<endl;

    s = " the sky is blue ";
    cout<<sol.reverseWords(s)<<endl;
    return 0;
}
