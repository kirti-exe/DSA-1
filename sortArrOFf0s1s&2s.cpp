#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    void sortArray(vector<int>& arr, int n){                            //time complexity: O(n)      space complexity: O(1)
        int low = 0, mid = 0, high = n-1;
        while(mid <= high){
            if(arr[mid] == 0){
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            } else if (arr[mid] == 1){
                mid++;
            } else {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }

    void printArray(vector<int>&arr, int n){
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};
int main(){
    vector<int> arr = {0,1,1,0,1,2,1,2,0,0,0};
    int n = arr.size();

    Solution sol;
    sol.sortArray(arr, n);
    cout<<"Sorted Array: ";
    sol.printArray(arr, n);
    return 0;
}
