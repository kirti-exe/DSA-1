// Given an array nums of size n, return the majority element
// the majority element is the element that appears more than [n/2] times

#include<iostream>
#include<vector>
using namespace std;

int majorElement(vector<int> v){
    int count = 0;
    int element;

    // Step 1: Find candidate
    for(int i = 0; i < v.size(); i++){
        if(count == 0){
            count = 1;
            element = v[i];
        } else if(v[i] == element){
            count++;
        } else {
            count--;
        }
    }

    // Step 2: Verify candidate
    int counter1 = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == element) 
            counter1++;
    }

    if(counter1 > v.size() / 2){
        return element;
    }
    return -1;
}
// time complexity : O(N) + O(N)
int main(){
    vector<int> arr = {2,2,3,3,1,2,2};
    int ele = majorElement(arr);

    cout << ele << endl;
    return 0;
}
