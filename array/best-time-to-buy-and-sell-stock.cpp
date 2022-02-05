class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int minSofar = prices[0];
    int profit = 0;
    int n = prices.size();
    for (int i = 1; i < n; i++)
    {
      minSofar = min(minSofar, prices[i]);
      if (prices[i] - minSofar > profit)
        profit = prices[i] - minSofar;
    }
    return profit;
  }
};