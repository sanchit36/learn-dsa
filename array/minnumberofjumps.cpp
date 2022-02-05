#include <bits/stdc++.h>
using namespace std;

// T -> O(n) S -> O(1)
int jump(vector<int> &nums)
{
  int res = 0;
  int l = 0, r = 0;
  int n = nums.size();
  while (r < n - 1)
  {
    int far = 0;
    for (int i = l; i <= r; i++)
    {
      far = max(far, i + nums[i]);
    }
    l = r + 1;
    r = far;
    res += 1;
  }
  return res;
}

int main()
{
  vector<int> arr = {2, 3, 1, 1, 4};
  cout << jump(arr) << endl;
  return 0;
}