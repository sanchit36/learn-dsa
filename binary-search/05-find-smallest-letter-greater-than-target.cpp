// https://leetcode.com/problems/find-smallest-letter-greater-than-target/
/*
Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"
Example 3:

Input: letters = ["c","f","j"], target = "d"
Output: "f"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  char nextGreatestLetter(vector<char> &letters, char target)
  {
    int s = 0, e = letters.size() - 1;
    if (target >= letters[e])
      return letters[0];
    while (s <= e)
    {
      int mid = s + (e - s) / 2;
      if (target < letters[mid])
      {
        e = mid - 1;
      }
      else
      {
        s = mid + 1;
      }
    }
    return letters[s];
  }
};

int main()
{

  Solution solution;
  vector<char> letters = {'c', 'f', 'j'};
  char target = 'a';
  char ans = solution.nextGreatestLetter(letters, target);
  cout << ans << endl;
  return 0;
}