#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
class Solution{
public:
    int lengthOfLongestSubstring(string s){
        unordered_map<char, int> charIndex;
        int maxLength = 0;
        int start = 0;

        for(int end = 0; end < s.length(); end++){
            char current = s[end];
            if(charIndex.find(current) != charIndex.end() && charIndex[current] >= start){
                start = charIndex[current] + 1;
            }
            charIndex[current] = end;
            maxLength = max(maxLength, end-start+1);
        }
        return maxLength;
    }
};
int main(){
    Solution sol;
    string input = "abcabcbb";

    int result = sol.lengthOfLongestSubstring(input);
    cout<<"Length of longest substring without repeating characters: "<<result<<endl;

    return 0;
}
