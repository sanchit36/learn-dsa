// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
/*
Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int t)
  {
    int f = bs(nums, t, true);
    int l = bs(nums, t, false);
    return {f, l};
  }

private:
  int bs(vector<int> &nums, int t, bool isF)
  {
    int s = 0, e = nums.size() - 1;
    int ans = -1;
    while (s <= e)
    {
      int mid = s + (e - s) / 2;
      if (t == nums[mid])
      {
        ans = mid;
        if (isF)
        {
          e = mid - 1;
        }
        else
        {
          s = mid + 1;
        }
      }
      else if (t < nums[mid])
      {
        e = mid - 1;
      }
      else
      {
        s = mid + 1;
      }
    }
    return ans;
  }
};

int main()
{
  Solution solution;
  vector<int> nums = {5, 7, 7, 8, 8, 10};
  int target = 8;
  vector<int> ans = solution.searchRange(nums, target);
  for (int a : ans)
  {
    cout << a << ",";
  }
  return 0;
}