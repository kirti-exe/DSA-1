#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        unordered_map<string, vector<string>> map;
        map.reserve(strs.size()*2);
        for(const string &s : strs){
            int count[26] = {0};
            for(char c : s)
                ++count[c - 'a'];

            string key;
            key.reserve(26*3);
            for(int i=0; i<26; ++i){
                key.append(to_string(count[i]));
                key.push_back('#');
            }
            map[key].push_back(s);
        }

        vector<vector<string>> result;
        result.reserve(map.size());
        for(auto &p : map)
            result.push_back(move(p.second));
        return result;
    }
};
int main(){
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> groups = sol.groupAnagrams(strs);

    for(const auto &g : groups){
        cout<<"[";
        for(const auto &w : g) 
            cout<<w<<" ";
        cout<<"]"<<endl;
    }
    return 0;
}
