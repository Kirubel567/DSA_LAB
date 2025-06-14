#include<iostream> 
#include<vector> 
#include<queue>
#include<unordered_set>
#include<string>
#include<numeric> 
#include<algorithm> 
#include<unordered_map>
#include<map>
using namespace std;

class Solution {
public:
    // This function does a DFS flood fill from a given cell
    void paintFromEdge(vector<vector<char>>& board, int r, int c, char mark) {
        // out of bounds or not an 'O' — just back out
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return;
        if (board[r][c] != 'O') return;

        board[r][c] = mark; // temporarily mark as visited (safe)

        // go all 4 ways
        paintFromEdge(board, r + 1, c, mark); // down
        paintFromEdge(board, r - 1, c, mark); // up
        paintFromEdge(board, r, c + 1, mark); // right
        paintFromEdge(board, r, c - 1, mark); // left
    }

    void solve(vector<vector<char>>& board) {
        // handle corner case when board is just empty
        if (board.empty() || board[0].size() == 0) return;

        int rows = board.size();
        int cols = board[0].size();

        // Step 1: paint all 'O's on the border + anything connected to them
        for (int i = 0; i < rows; i++) {
            // first col and last col
            if (board[i][0] == 'O') {
                paintFromEdge(board, i, 0, '#');
            }
            if (board[i][cols - 1] == 'O') {
                paintFromEdge(board, i, cols - 1, '#');
            }
        }

        for (int j = 0; j < cols; ++j) {
            // top row and bottom row
            if (board[0][j] == 'O') {
                paintFromEdge(board, 0, j, '#');
            }
            if (board[rows - 1][j] == 'O') {
                paintFromEdge(board, rows - 1, j, '#');
            }
        }

        // Step 2: convert the rest of the 'O's to 'X'
        // and turn all '#' (safe ones) back to 'O'
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // surrounded 'O' turns to 'X'
                }
                else if (board[i][j] == '#') {
                    board[i][j] = 'O'; // restore back the safe ones
                }
                // no else needed
            }
        }
    }
};
