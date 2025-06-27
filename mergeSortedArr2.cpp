// program to merge two sorted arrays without using extra space
#include<iostream>
#include<algorithm>
using namespace std;
class Solution{
private:
void swapIfGreater(int arr1[], int arr2[], int idx1, int idx2){
    if(arr1[idx1] > arr2[idx2]){
        swap(arr1[idx1], arr2[idx2]);
    }
}
public:
    void merge2(int arr1[], int arr2[], int n, int m){
        int len = (n + m);
        int gap = (len / 2) + (len % 2);
        while(gap > 0){
            int left =0;
            int right = left + gap;
            while(right < len){
                // arr1 and arr2
                if(left < n && right >= n){
                    swapIfGreater(arr1, arr2, left, right - n);
                }
                // arr2 and arr2
                else if(left >= n){
                    swapIfGreater(arr2, arr2, left - n, right - n);
                }
                // arr1 and arr1
                else{
                    swapIfGreater(arr1, arr1, left, right);
                }
                left++, right++;
            }
            if(gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
    }
};
int main(){
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {0, 2, 6, 8, 9};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    Solution s;
    s.merge2(arr1, arr2, n, m);     //uses gap method
    
    
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
