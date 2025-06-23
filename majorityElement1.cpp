// Given an array nums of size n, return the majority element
// the majority element is the element that appears more than [n/2] times

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int majorElement(vector<int> v){
    map<int, int> mpp;
    for(int i=0; i<v.size(); i++){
        mpp[v[i]]++;
    }

    for(auto iterate : mpp){
        if(iterate.second > (v.size() / 2)){
            return iterate.first;
        }
    }
    return -1;
}

// its time complexity will be : O(nlogn)+ O(n)

int main(){
    vector<int> arr = {2,2,3,3,1,2,2};
    int ele = majorElement(arr);

    cout << ele << endl;
    return 0;
}
