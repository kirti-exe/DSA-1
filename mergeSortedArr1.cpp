// program to merge two sorted arrays without using extra space
#include<iostream>
#include<algorithm>
using namespace std;
class Solution{
}
public:
    void merge1(int arr1[], int arr2[], int n, int m){
        int left = n-1;
        int right = m;
        while(left >= 0 && right < m){
            if(arr1[left] > arr2[right]){
                swap(arr1[left], arr2[right]);
                left--, right++;
            }else{
                break;
            }
        }   
        sort(arr1, arr1+n);
        sort(arr2, arr2+m);
        // time complexity = O(minimum,(n,m)) + O(nlogn) + O(nlogn)
    }
};
int main(){
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {0, 2, 6, 8, 9};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    Solution s;
     s.merge1(arr1, arr2, n, m);     //uses  sorting after swap
  
    cout << "Merged array: ";
    for(int i = 0; i < n; i++){
        cout << arr1[i] << " ";
    }
    for(int i = 0; i < m; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}
