#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &maze, int row, int col, vector<vector<int>> &visited, string ans, vector<string> &allPaths)
{
  if (row < 0 || col < 0 || row == maze.size() || col == maze[0].size() || maze[row][col] == 0 || visited[row][col] == 1)
  {
    return;
  }
  if (row == maze.size() - 1 && col == maze.size() - 1)
  {
    allPaths.push_back(ans);
    return;
  }
  visited[row][col] = 1;
  helper(maze, row + 1, col, visited, ans + "D", allPaths);
  helper(maze, row, col - 1, visited, ans + "L", allPaths);
  helper(maze, row, col + 1, visited, ans + "R", allPaths);
  helper(maze, row - 1, col, visited, ans + "U", allPaths);
  visited[row][col] = 0;
}

vector<string> ratInMaze(vector<vector<int>> &maze)
{
  vector<vector<int>> visited(maze.size(), vector<int>(maze.size()));
  vector<string> allPaths;
  helper(maze, 0, 0, visited, "", allPaths);
  return allPaths;
}

int main()
{
  int n = 4;
  vector<vector<int>> maze = {{1, 0, 0, 0},
                              {1, 1, 0, 1},
                              {1, 1, 0, 0},
                              {0, 1, 1, 1}};
  vector<string> ans = ratInMaze(maze);

  for (auto path : ans)
  {
    cout << path << endl;
  }
  return 0;
}