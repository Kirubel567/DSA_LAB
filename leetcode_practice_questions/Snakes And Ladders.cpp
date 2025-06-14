#include<iostream> 
#include<vector> 
#include<queue>
#include<unordered_set>
#include<numeric> 
#include<algorithm> 
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& gameBoard) {
        int boardSize = gameBoard.size();  // number of rows/columns 
        int totalSquares = boardSize * boardSize;

        // This will hold the positions
        vector<pair<int, int>> squareLabelToCoordinates(totalSquares + 1);
        int currentPositionLabel = 1;

        // This vector will help us go left-to-right or right-to-left per row
        vector<int> columnIndexes(boardSize);
        for (int idx = 0; idx < boardSize; ++idx) {
            columnIndexes[idx] = idx;
        }

        // Fill the squareLabelToCoordinates map by simulating the snaking pattern
        for (int boardRow = boardSize - 1; boardRow >= 0; --boardRow) {
            for (int boardCol : columnIndexes) {
                squareLabelToCoordinates[currentPositionLabel] = {boardRow, boardCol};
                ++currentPositionLabel;
            }
            reverse(columnIndexes.begin(), columnIndexes.end());  // flip direction every row
        }

        // This will track the minimum number of moves needed to get to each square
        vector<int> minMovesToSquare(totalSquares + 1, -1);
        queue<int> bfsQueue;
        bfsQueue.push(1);  //start from square 1
        minMovesToSquare[1] = 0;

        while (!bfsQueue.empty()) {
            int currentSquare = bfsQueue.front();
            bfsQueue.pop();

            // Try all dice outcomes (1 to 6)
            for (int diceRoll = 1; diceRoll <= 6; ++diceRoll) {
                int nextSquare = currentSquare + diceRoll;

                if (nextSquare > totalSquares) continue;

                // Get the coordinates of the square we might land on
                int row = squareLabelToCoordinates[nextSquare].first;
                int col = squareLabelToCoordinates[nextSquare].second;

                // Now check if there's a snake or ladder
                int actualLandingSquare;
                if (gameBoard[row][col] == -1) {
                    actualLandingSquare = nextSquare;  // normal square
                } else {
                    actualLandingSquare = gameBoard[row][col];  // go to snake/ladder
                }

                // If we haven't visited this square yet, add it to queue
                if (minMovesToSquare[actualLandingSquare] == -1) {
                    minMovesToSquare[actualLandingSquare] = minMovesToSquare[currentSquare] + 1;
                    bfsQueue.push(actualLandingSquare);
                }
            }
        }

        // Check if we were able to reach the final square
        if (minMovesToSquare[totalSquares] == -1) {
            return -1;  // unreachable
        } else {
            return minMovesToSquare[totalSquares];
        }
    }
};
