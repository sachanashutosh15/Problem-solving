#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void Escape(int n, int **arr)
  {
    int pathCount = 0;
    pair<int, int> currLoc = {0, 0};
    if (arr[0][0] != 0 && arr[n - 1][n - 1] != 0)
    {
      countEscapePaths(n, arr, pathCount, currLoc);
    }
    cout << pathCount << endl;
  }

private:
  pair<int, int> movements[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

  bool isMovementValid(int n, pair<int, int> nextLoc, int **arr)
  {
    int x = nextLoc.first;
    int y = nextLoc.second;
    return x >= 0 && x < n && y >= 0 && y < n && arr[y][x];
  }

  void countEscapePaths(int n, int **arr, int &pathCount, pair<int, int> currLoc)
  {
    if (currLoc.first == n - 1 && currLoc.second == n - 1)
    {
      pathCount++;
    }
    for (int i = 0; i < 4; i++)
    {
      pair<int, int> nextLoc = {currLoc.first + movements[i].first, currLoc.second + movements[i].second};
      if (isMovementValid(n, nextLoc, arr))
      {
        arr[currLoc.second][currLoc.first] = 0;
        countEscapePaths(n, arr, pathCount, nextLoc);
        arr[currLoc.second][currLoc.first] = 1;
      }
    }
  }
};

int main()
{
  int n = 3;
  int **arr = new int *[n];
  arr[0] = new int[n]{1, 1, 1};
  arr[1] = new int[n]{1, 1, 1};
  arr[2] = new int[n]{1, 1, 1};
  Solution solution;
  solution.Escape(n, arr);
  for (int i = 0; i < n; i++)
  {
    delete[] arr[i];
  }
  delete[] arr;
  return 0;
}
