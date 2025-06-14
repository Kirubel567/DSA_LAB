#include<iostream> 
#include<vector> 
#include<queue>
using namespace std; 

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.empty() or grid[0][0]!=0)
        {
            return -1;
        }
        
        int size1 =grid.size();
        int size2 =grid[0].size();
        if(grid[0][0]==0 and size1==1 and size2==1)
        {
            return 1;
        }
        vector<int> dir{0,1,0,-1,0,1,1,-1,-1,1};
        int steps{0};
        queue<pair<int,int>>queue;
        queue.push(make_pair(0,0));
        grid[0][0]=1;
        while(!queue.empty())
        {
            steps++;
            int size=queue.size();
            for(int i=0;i<size;i++)
            {
                auto coord=queue.front();
                queue.pop();
                for(int i=0;i<9;i++)
                {
                    int row=coord.first+dir[i];
                    int col=coord.second+dir[i+1];
                    if(row<size1 and row>=0 and col<size2 and col>=0 and grid[row][col]!=1)
                    {
                        if(row==size1-1 and col==size2-1)
                            return steps+1;
                        queue.push(make_pair(row,col));
                        grid[row][col]=1;
                    }
                }
            }
        }
        return -1;
    }
};