#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> generateUniqueSubsets(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> current;
    helper(nums, 0, current, result);
    return result;
  }

private:
  void helper(vector<int> &nums, int idx, vector<int> &current, vector<vector<int>> &result) {
    result.push_back(current);

    for (int i = idx; i < nums.size(); ++i) {
      if (i > idx && nums[i] == nums[i - 1]) continue;
      current.push_back(nums[i]);
      cout << "i = " << i << " ( ";
      for (int j = 0; j < current.size(); j++) {
        cout << current[j] << " ";
      }
      cout << ")";
      cout <<" calling helper(" << "idx = " << i + 1 << ")" << endl;
      helper(nums, i + 1, current, result);
      current.pop_back();
    }
  }
};

int main() {
  vector<int> nums = {1, 2, 1};
  Solution solution;
  vector<vector<int>> result = solution.generateUniqueSubsets(nums);
  // for (const auto &subset : result) {
  //   cout << "[ ";
  //   for (int num : subset) {
  //     cout << num << " ";
  //   }
  //   cout << "]" << endl;
  // }
}
