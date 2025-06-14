#include<iostream> 
#include<vector> 
#include<queue>
#include<unordered_set>
using namespace std; 

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set <string> dead(deadends.begin(),deadends.end());
        unordered_set <string> visited;

        queue <string> q;
        q.push("0000");
        if (dead.count("0000")) return -1;
        visited.insert("0000");
        int cnt= 0 ;
        while (!q.empty()){
            int sss = q.size();
            for (int i = 0; i<sss; i++){
                string g = q.front();
                q.pop();
                if (g==target) return cnt;
                for (int j = 0; j<4; j++){
                    for (int dir = -1; dir<=1; dir+=2){
                        string next = g;
                        next[j] = (next[j] - '0' + dir + 10) % 10 + '0';

                        if (!dead.count(next) && !visited.count(next)) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }

            cnt++;
        }

        return -1;

    }
};