#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution{
public:
    string removeOccurrences(string s, string part){
        int n = s.size(), k = part.size();
        string result;
        result.reserve(n);

        for(int i = 0; i < n; i++){
            result.push_back(s[i]);
            if((int)result.size() >= k){
                bool match = true;
                for(int j = 0; j < k; j++){
                    if(result[result.size() - k + j] != part[j]){
                        match = false;
                        break;
                    }
                }
                if(match){
                    for(int j = 0; j < k; j++){
                        result.pop_back();
                    }
                }
            }
        }
        return result;
    }
};
int main(){
    Solution sol;

    string s  = "daabcbaabcbc";     //ouput: dab
    string part = "abc";
    cout<<sol.removeOccurrences(s, part)<<endl;

    
    s = "axxxxyyyyb";        //output: ab
    part = "xy";
    cout<<sol.removeOccurrences(s, part)<<endl;
    return 0;
}
