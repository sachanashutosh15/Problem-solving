#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> generateAllUniqueSubsets(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> subset; 
    sort(nums.begin(), nums.end());
    unordered_set<string> used;
    helper(nums, subset, 0, result, used);
    return result;
  }

private:
  void helper(vector<int> &nums, vector<int> subset, int idx, vector<vector<int>> &result, unordered_set<string> &used) {
    string setKey = "";
    for(auto num: subset) {
      setKey += to_string(num);
    }
    if (idx == nums.size()) {
      used.insert(setKey);
      result.push_back(subset);
      return;
    }
    if (used.find(setKey) == used.end()) {
      helper(nums, subset, idx + 1, result, used);
      subset.push_back(nums[idx]);
      helper(nums, subset, idx + 1, result, used);
    }
  }
};

int main() {
  vector<int> nums = {1, 2, 3};
  Solution solution;
  vector<vector<int>> result = solution.generateAllUniqueSubsets(nums);
  for (auto v1: result) {
    cout << "( ";
    for (auto num: v1) {
      cout << num << " ";
    }
    cout << ")" << endl;
  }
}
