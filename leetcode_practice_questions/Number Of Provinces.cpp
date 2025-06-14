#include<iostream> 
#include<vector> 
#include<queue>
#include<unordered_set>
#include<numeric> 
#include<algorithm> 
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int,bool> visited;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!visited[i])
                bfs(i,n,isConnected,visited,cnt);
        }

        return cnt;
    }

    void bfs(int i,int n,vector<vector<int>>& isConnected,unordered_map<int,bool>& visited,int &cnt){
        cnt++;

        queue<int> q;
        q.push(i);

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(int j=0;j<n;j++){
                int temp = isConnected[front][j];
                if(temp == 1 && !visited[j]){
                    q.push(j);
                }
            } 
            visited[front]=true;
        }
    }
};