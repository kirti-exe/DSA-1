#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class solution {
public:
    vector<int> findMissingAndRepeatingValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int n = grid.size();
        int a = 0, b = 0;

        int expSum = 0, actualSum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                actualSum += grid[i][j];

                if(s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j]; // Repeating value
                }
                s.insert(grid[i][j]);
            }
        }

        expSum = (n * n) * (n * n + 1) / 2;
        b = expSum + a - actualSum; // Missing value
        ans.push_back(a);
        ans.push_back(b);

        return ans;
    }
};

int main() {
    vector<vector<int>> grid = {{9,1,7}, {8,9,2}, {3,4,6}};
    solution s;
    vector<int> ans = s.findMissingAndRepeatingValues(grid);

    cout << "Repeating: " << ans[0] << ", Missing: " << ans[1] << endl;

    return 0;
}

// time complexity O(n^2)
