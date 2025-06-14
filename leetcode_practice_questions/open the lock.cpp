#include<iostream> 
#include<vector> 
#include<queue>
#include<unordered_set>
using namespace std; 

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadSet(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;

        string start = "0000";
        if (deadSet.count(start)) return -1;

        q.push(start);
        visited.insert(start);
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();

                if (cur == target) return steps;

                for (int pos = 0; pos < 4; pos++) {
                    for (int move = -1; move <= 1; move += 2) {
                        string next = cur;
                        // Change digit at position pos
                        int digit = (next[pos] - '0' + move + 10) % 10;
                        next[pos] = digit + '0';

                        if (deadSet.count(next) == 0 && visited.count(next) == 0) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
