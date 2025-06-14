#include<iostream> 
#include<vector> 
#include<queue>
#include<unordered_set>
#include<numeric> 
#include<algorithm> 
using namespace std;

class Solution {
public:
    int racecar(int target) {
        queue<vector<int>> q;
        q.push({0, 0, 1});
        while (!q.empty()) {
            
            vector<int> item = q.front();
            q.pop();
            
            int moves = item[0];
            int pos = item[1];
            int vel = item[2];
            
            if (pos == target) return moves;
            
            
            if (abs(pos) > 2 * target) continue;
            
          
            q.push({moves + 1, pos + vel, 2 * vel});
            
             
            if ((pos + vel > target && vel > 0) || (pos + vel < target && vel < 0)) {
                q.push({moves + 1, pos, (vel > 0) ? -1 : 1});
            }
        }
        
        return 0;
    }
};