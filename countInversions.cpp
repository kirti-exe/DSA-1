#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to merge two sorted halves and count inversions
    long long merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp;
        int i = left;      // start of left subarray
        int j = mid + 1;   // start of right subarray
        long long inv_count = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                inv_count += (mid - i + 1); // count inversions
                j++;
            }
        }

        // Copy remaining elements
        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]);

        // Copy back to original array
        for (int k = left; k <= right; k++) {
            arr[k] = temp[k - left];
        }

        return inv_count;
    }

    // Merge sort function that returns inversion count
    long long mergeSort(vector<int>& arr, int left, int right) {
        long long inv_count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            inv_count += mergeSort(arr, left, mid);
            inv_count += mergeSort(arr, mid + 1, right);
            inv_count += merge(arr, left, mid, right);
        }
        return inv_count;
    }

    // Main function to call from outside
    long long countInversions(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    Solution sol;
    long long result = sol.countInversions(arr);
    cout << "Number of inversions: " << result << endl;
    return 0;
}
