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

    void dfs(unordered_map<int,vector<int>>&adj, int u, int&temp, vector<int>&vis){
        vis[u]=1;

        for(auto v: adj[u]){
            if(!vis[v]){
                temp++;
                dfs(adj,v,temp,vis);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int,vector<int>>adj;

        for(int i=0; i<bombs.size();i++){
            for(int j=0; j<bombs.size();j++){
                if(i==j)continue;

                int x1= bombs[i][0];
                int y1= bombs[i][1];
                int r1= bombs[i][2];

                int x2= bombs[j][0]; 
                int y2= bombs[j][1];
                int r2= bombs[j][2];

                long long dx = (long long)x1 - x2;
                long long dy = (long long)y1 - y2;
                long long distSq = dx * dx + dy * dy;
                
                // Compare squared values to avoid using sqrt.
                if ((long long)r1 * r1 >= distSq) {
                    adj[i].push_back(j);
                }
            }
        }   

        int ans=0;
        
        for(int i=0; i<bombs.size();i++){
            vector<int>vis(bombs.size(),0);
            int temp=1;
            dfs(adj,i,temp,vis);
            ans= max(ans,temp);
            
        }

        return ans;
    }
};