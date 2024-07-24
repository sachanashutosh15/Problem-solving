#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &arr, int ele) {
  if (arr.size() == 0 || arr[arr.size() - 1] <= ele) {
    arr.push_back(ele);
    return;
  }
  int lastEle = arr[arr.size() - 1];
  arr.pop_back();
  insert(arr, ele);
  arr.push_back(lastEle);
}

void sort(vector<int> &arr) {
  if (arr.size() == 1) {
    return;
  } 
  int lastEle = arr[arr.size() - 1];
  arr.pop_back();
  sort(arr);
  insert(arr, lastEle);
}

int main() {
  vector<int> arr = {1, 0, 5, 2};
  sort(arr);
  for (int num: arr) {
    cout << num << " ";
  }
  cout << endl;
}
