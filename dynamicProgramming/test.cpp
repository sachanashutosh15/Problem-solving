#include <iostream>
#include <vector>
using namespace std;

int countWays(int* ar, int n, int k) {
    // Base cases
    if (k == 0) {
        return 1;  // There is one way to achieve sum 0 (by selecting empty subset)
    }
    if (n == 0) {
        return 0;  // If no elements are left and k is not 0, no way to achieve sum k
    }

    // Recursive cases
    // Exclude the current element ar[n-1]
    int exclude = countWays(ar, n - 1, k);
    
    // Include the current element ar[n-1] if it does not exceed k
    int include = 0;
    if (ar[n - 1] <= k) {
        include = countWays(ar, n - 1, k - ar[n - 1]);
    }
    
    // Total ways are the sum of ways including and excluding the current element
    return exclude + include;
}

int main() {
    int n, k;
    cin >> n >> k;

    int ar[n];
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }

    int ways = countWays(ar, n, k);
    cout << ways << endl;

    return 0;
}
