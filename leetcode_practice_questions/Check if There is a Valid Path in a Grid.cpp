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
    unordered_map<int, pair<int, int>> streetEntry = {
        {1, {0, -1}}, {2, {-1, 0}}, {3, {0, -1}},
        {4, {0, 1}},  {5, {0, -1}}, {6, {0, 1}}
    };
    unordered_map<int, pair<int, int>> streetExit = {
        {1, {0, 1}},  {2, {1, 0}},  {3, {1, 0}},
        {4, {1, 0}},  {5, {-1, 0}}, {6, {-1, 0}}
    };

    //check if grid is inside or not 
    bool insideGrid(const vector<vector<int>>& grid, int r, int c) {
        return r >= 0 && c >= 0 && r < (int)grid.size() && c < (int)grid[0].size();
    }

    // DFS helper
    bool walkPath(const vector<vector<int>>& grid, vector<vector<bool>>& seen, int r, int c) {
        if (r == (int)grid.size() - 1 && c == (int)grid[0].size() - 1) 
            return true;  // reached bottom-right

        seen[r][c] = true;
        int currStreet = grid[r][c];

        // Lambda neighbours 
        auto canMoveTo = [&](int nr, int nc) {
            if (!insideGrid(grid, nr, nc) || seen[nr][nc]) return false;
            
            int nextStreet = grid[nr][nc];

            // The next cell must connect back to current cell either via entry or exit
            pair<int, int> backViaEntry = {nr + streetEntry[nextStreet].first, nc + streetEntry[nextStreet].second};
            pair<int, int> backViaExit = {nr + streetExit[nextStreet].first, nc + streetExit[nextStreet].second};

            return (backViaEntry.first == r && backViaEntry.second == c) || 
                   (backViaExit.first == r && backViaExit.second == c);
        };

        // try entering the neighbour cells 
        int nr = r + streetEntry[currStreet].first;
        int nc = c + streetEntry[currStreet].second;
        if (canMoveTo(nr, nc) && walkPath(grid, seen, nr, nc)) 
            return true;

        nr = r + streetExit[currStreet].first;
        nc = c + streetExit[currStreet].second;
        if (canMoveTo(nr, nc) && walkPath(grid, seen, nr, nc))
            return true;

        return false; // no valid path, so return 
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return false;

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        return walkPath(grid, visited, 0, 0);
    }
};
