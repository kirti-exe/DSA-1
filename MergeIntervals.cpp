#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};

        // Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {
            vector<int>& last = merged.back();

            // Step 2: Check for overlap
            if(intervals[i][0] <= last[1]) {
                // Merge
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // No overlap, add new interval
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = sol.merge(intervals);

    cout << "Merged Intervals: ";
    for(auto& interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    return 0;
}
