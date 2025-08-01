#include<iostream>
#include<vector>
using namespace std;

class Solution{
public: 
    vector<vector<int>> setZeroes(vector<vector<int>>& matrix){
        int n = matrix.size(), m = matrix[0].size();
        // int col[m] = {0}; -> matrix[0][..]
        // int row[n] = {0}; -> matrix[..][0]
        
        int col0 = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    // mart the i-th row
                    matrix[i][0] = 0;
                    // mark the j-th row
                    if(j != 0)
                        matrix[0][j] = 0;
                    else 
                        col0 = 0;
                }
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] != 0){
                    // check for col & row
                    if(matrix[0][j] == 0 || matrix[i][0] == 0){
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int j=0; j<m; j++)  matrix[0][j] = 0;
        }
        if(col0 == 0){
            for(int i = 0; i<n; i++) matrix[i][0] = 0;
        }
        return matrix;
    }  
};

void printMatrix(const vector<vector<int>>& matrix){
    for(const auto& row : matrix){
        for(int val : row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout<<"Orginal Matrix: "<<endl;
    printMatrix(matrix);

    Solution sol;
    sol.setZeroes(matrix);

    cout<<"\nMatrix after setting zeroes:"<<endl;
    printMatrix(matrix);
    return 0;
}
