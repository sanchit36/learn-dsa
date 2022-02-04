#include <bits/stdc++.h>
using namespace std;

//function to display the 2-d array
void display(vector<vector<int>> &chess)
{
  for (int i = 0; i < chess.size(); i++)
  {
    for (int j = 0; j < chess.size(); j++)
    {
      cout << chess[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

bool isSafe(vector<vector<int>> &chess, int n, int r, int c)
{
  if (r < 0 || c < 0 || r >= n || c >= n || chess[r][c] > 0)
  {
    return false;
  }
  return true;
}

vector<pair<int, int>> dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

void printKnightsTour(vector<vector<int>> &chess, int n, int r, int c, int upcomingMove)
{

  if (!isSafe(chess, n, r, c))
  {
    return;
  }

  if (upcomingMove == n * n)
  {
    chess[r][c] = upcomingMove;
    display(chess);
    chess[r][c] = 0;
    return;
  }

  chess[r][c] = upcomingMove;
  for (auto dir : dirs)
  {
    printKnightsTour(chess, n, r + dir.first, c + dir.second, upcomingMove + 1);
  }
  chess[r][c] = 0;
}

int main()
{
  int n, r, c;
  cin >> n >> r >> c;
  vector<vector<int>> chess(n, vector<int>(n, 0));
  printKnightsTour(chess, n, r, c, 1);
}