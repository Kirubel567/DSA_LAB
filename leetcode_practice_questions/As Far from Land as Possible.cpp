#include<iostream> 
#include<vector> 
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<pair<int,int>> dist = {{0,1},{0,-1},{1,0},{-1,0}};
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q ;
        int n = grid.size();
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ;j<n; j++){
                if(grid[i][j]){
                    q.push({i,j});
                }
            }
        }
        if(q.size() == (n*n) || !q.size() ){
            return -1 ;
        }
       int ans = 0 ; 
       while(!q.empty()){
        int sz = q.size();
        while(sz--){
            auto current = q.front(); q.pop();
            int x = current.first ; 
            int y = current.second ; 
            for(auto d : dist){
                int x1 = x + d.first ; 
                int y1 = y +  d.second ; 
                if(x1 >= 0 && y1 >= 0 && x1<n && y1 < n && !grid[x1][y1]){
                    grid[x1][y1] = 1 + grid[x][y];
                    q.push({x1,y1});
                    ans = max(ans,grid[x1][y1]);
                }
            }
        }
       }
        return ans - 1;
    }
};