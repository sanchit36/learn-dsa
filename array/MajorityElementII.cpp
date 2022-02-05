#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> majorityElement(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = 1, i = 1;
    int max = n / 3;
    vector<int> ans;

    for (i = 1; i < n; i++)
    {
      if (nums[i] == nums[i - 1])
      {
        count++;
      }
      else
      {
        if (count > max)
        {
          ans.push_back(nums[i - 1]);
        }
        count = 1;
      }
    }

    if (count > max)
    {
      ans.push_back(nums[i - 1]);
    }

    return ans;
  }
};

// TODO: Moore's Voting Algorithm

int main()
{

  return 0;
}
