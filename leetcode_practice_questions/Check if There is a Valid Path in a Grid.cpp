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
    unordered_map<int, pair<int, int>> hashIn = {{1, {0, -1}}, {2, {-1, 0}}, {3, {0, -1}}, {4, {0, 1}}, {5, {0, -1}}, {6, {0, 1}}};
    unordered_map<int, pair<int, int>> hashOut = {{1, {0, 1}}, {2, {1, 0}}, {3, {1, 0}}, {4, {1, 0}}, {5, {-1, 0}}, {6, {-1, 0}}};
    bool isInGrid(vector<vector<int>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        return !(i<0||j<0||i>=n||j>=m);
    }
    bool solve(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i==n-1&&j==m-1) return true;
        int dir = grid[i][j];
        visited[i][j] = true;
        pair<int, int> possibleIndex = {i + hashIn[dir].first, j + hashIn[dir].second};
        if(isInGrid(grid, possibleIndex.first, possibleIndex.second) && !visited[possibleIndex.first][possibleIndex.second]){
            int dirNext = grid[possibleIndex.first][possibleIndex.second];
            pair<int, int> predictedIndex = {possibleIndex.first + hashIn[dirNext].first, possibleIndex.second + hashIn[dirNext].second};
            if(predictedIndex.first==i&&predictedIndex.second==j){
                if(solve(grid, visited, possibleIndex.first, possibleIndex.second)) return true;
            }
            predictedIndex = {possibleIndex.first + hashOut[dirNext].first, possibleIndex.second + hashOut[dirNext].second};
            if(predictedIndex.first==i&&predictedIndex.second==j){
                if(solve(grid, visited, possibleIndex.first, possibleIndex.second)) return true;
            }
        }
        possibleIndex = {i+hashOut[dir].first, j+hashOut[dir].second};
        if(isInGrid(grid, possibleIndex.first, possibleIndex.second) && !visited[possibleIndex.first][possibleIndex.second]){
            int dirNext = grid[possibleIndex.first][possibleIndex.second];
            pair<int, int> predictedIndex = {possibleIndex.first + hashIn[dirNext].first, possibleIndex.second + hashIn[dirNext].second};
            if(predictedIndex.first==i&&predictedIndex.second==j){
                if(solve(grid, visited, possibleIndex.first, possibleIndex.second)) return true;
            }
            predictedIndex = {possibleIndex.first + hashOut[dirNext].first, possibleIndex.second + hashOut[dirNext].second};
            if(predictedIndex.first==i&&predictedIndex.second==j){
                if(solve(grid, visited, possibleIndex.first, possibleIndex.second)) return true;
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        return solve(grid, visited, 0, 0);
    }
};