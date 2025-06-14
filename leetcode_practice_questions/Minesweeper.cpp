#include<iostream> 
#include<vector> 
#include<queue>
#include<utility> 
#include<unordered_set>
#include<string>
#include<numeric> 
#include<algorithm> 
#include<unordered_map>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int rows = board.size();
        int cols = board[0].size();

        // Directions to explore all 8 surrounding cells
        int dirX[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dirY[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

        int startX = click[0], startY = click[1];

        if (board[startX][startY] == 'M') {
            board[startX][startY] = 'X';
            return board;
        }

        queue<pair<int, int>> toExplore;
        toExplore.push({startX, startY});

        while (!toExplore.empty()) {
            auto [x, y] = toExplore.front();
            toExplore.pop();

            //If not an empty cell, skip
            if (board[x][y] != 'E') continue;

            int adjacentMines = 0;

            // Count mines around the current cell
            for (int d = 0; d < 8; ++d) {
                int nx = x + dirX[d];
                int ny = y + dirY[d];
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    if (board[nx][ny] == 'M') {
                        ++adjacentMines;
                    }
                }
            }

            if (adjacentMines > 0) {
                board[x][y] = '0' + adjacentMines;
            } else {
                // No adjacent mine
                board[x][y] = 'B';
                for (int d = 0; d < 8; ++d) {
                    int nx = x + dirX[d];
                    int ny = y + dirY[d];
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && board[nx][ny] == 'E') {
                        toExplore.push({nx, ny});
                    }
                }
            }
        }

        return board;
    }
};
