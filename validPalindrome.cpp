#include<iostream>
#include<string>
using namespace std;
class Solution{
public: 
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        
        while(left < right){
            if(isalnum(s[left])){
                if(isalnum(s[right])){
                    if(tolower(s[left]) != tolower(s[right])){
                        return false;
                    }
                    left++; right--;
                }else right--;
            }else left++;
        }
        return true;
    }
};
int main(){
    string str = "Ac3?e3c&a";
    Solution sol;
    if(sol.isPalindrome(str))
        cout<<"Its a valid palindrome."<<endl;
    else
        cout<<"Is not a valid palindrome."<<endl;
    
    return 0;
}
