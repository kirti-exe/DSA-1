#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &A) {
        int idx = -1;
        int n = A.size();

        // Step 1: Find the first decreasing element from the end
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                idx = i;
                break;
            }
        }

        // If no such element found, reverse the entire array
        if (idx == -1) {
            reverse(A.begin(), A.end());
            return;
        }

        // Step 2: Find the next greater element from the end and swap
        for (int i = n - 1; i > idx; i--) {
            if (A[i] > A[idx]) {
                swap(A[i], A[idx]);
                break;
            }
        }

        // Step 3: Reverse the suffix
        reverse(A.begin() + idx + 1, A.end());
    }
};

// Time complexity : O(3n), Space complexity : O(1)

int main() {
    vector<int> arr = {3, 1, 2};  // {2, 1, 5, 4, 3, 0, 0}
    Solution sol;

    sol.nextPermutation(arr);

    cout << "Next permutation: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
