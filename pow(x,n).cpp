#include <iostream> 
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;

        long long exp = n;
        if (n < 0) {
            x = 1 / x;
            exp = -static_cast<long long>(n);  // Use long long to avoid overflow for INT_MIN
        }

        double result = 1.0;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result *= x;
            }
            x *= x;
            exp /= 2;
        }

        return result;
    }
};

int main() {
    double number = 2;
    int power = 10;

    Solution sol;
    cout << sol.myPow(number, power) << endl;
    return 0;
}
