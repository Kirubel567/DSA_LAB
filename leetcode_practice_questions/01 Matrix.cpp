#include<iostream> 
#include<vector> 
#include<queue>
#include<unordered_set>
using namespace std; 

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int R = mat.size(), C = mat[0].size();
        vector<vector<int>> ans(R, vector<int>(C, -1));
        queue<pair<int,int>> q;

        // manually check 0s and push them
        for(int a=0; a<R; ++a){
            for(int b=0; b<C; ++b){
                if(mat[a][b]==0){
                    q.push({a,b});
                    ans[a][b]=0;
                }
            }
        }

        // just trying directions here
        int dr[4]={-1,1,0,0}, dc[4]={0,0,-1,1};
        
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            int x = cur.first, y = cur.second;
            for(int i=0;i<4;++i){
                int nx = x + dr[i];
                int ny = y + dc[i];
                if(nx>=0 && ny>=0 && nx<R && ny<C){
                    if(ans[nx][ny]==-1){
                        ans[nx][ny] = ans[x][y]+1;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }

        return ans;
    }
};
