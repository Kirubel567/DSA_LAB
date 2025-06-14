#include<iostream> 
#include<vector> 
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<bool>> path(m, vector<bool>(n, true));
    queue<pair<int, int>> q;

    int steps = 0;
    q.push({entrance[0], entrance[1]});
    path[entrance[0]][entrance[1]] = false; // mark entrance as visited

    while (!q.empty()) {
        int positionNeedTravers = q.size();
        steps++;

        for (int i = 0; i < positionNeedTravers; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // Up
            if (x - 1 >= 0 && maze[x - 1][y] == '.' && path[x - 1][y]) {
                if (x - 1 == 0 || x - 1 == m - 1 || y == 0 || y == n - 1)
                    return steps;
                q.push({x - 1, y});
                path[x - 1][y] = false;
            }

            // Down
            if (x + 1 < m && maze[x + 1][y] == '.' && path[x + 1][y]) {
                if (x + 1 == 0 || x + 1 == m - 1 || y == 0 || y == n - 1)
                    return steps;
                q.push({x + 1, y});
                path[x + 1][y] = false;
            }

            // Left
            if (y - 1 >= 0 && maze[x][y - 1] == '.' && path[x][y - 1]) {
                if (x == 0 || x == m - 1 || y - 1 == 0 || y - 1 == n - 1)
                    return steps;
                q.push({x, y - 1});
                path[x][y - 1] = false;
            }

            // Right
            if (y + 1 < n && maze[x][y + 1] == '.' && path[x][y + 1]) {
                if (x == 0 || x == m - 1 || y + 1 == 0 || y + 1 == n - 1)
                    return steps;
                q.push({x, y + 1});
                path[x][y + 1] = false;
            }
        }
    }

    return -1;
}

};