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
    void exploreChain(unordered_map<int, vector<int>>& graph, int start, int& count, vector<int>& visited) {
        visited[start] = 1;

        for (auto neighbor : graph[start]) {
            if (!visited[neighbor]) {
                count++;
                exploreChain(graph, neighbor, count, visited);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int, vector<int>> graph;

        int n = bombs.size();

        // Build graph edges
        for (int i = 0; i < n; i++) {
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            int r1 = bombs[i][2];

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int x2 = bombs[j][0];
                int y2 = bombs[j][1];

                long long dx = (long long)x1 - x2;
                long long dy = (long long)y1 - y2;

                long long distSquared = dx * dx + dy * dy;
                // Check if bomb j lies within the explosion radius of bomb i
                if ((long long)r1 * r1 >= distSquared) {
                    graph[i].push_back(j);
                }
            }
        }

        int maxDetonated = 0;

        // Try detonating each bomb as the initial trigger and find max reachable bombs
        for (int i = 0; i < n; i++) {
            vector<int> visited(n, 0);
            int count = 1;  //Start with the current bomb counted

            exploreChain(graph, i, count, visited);
            maxDetonated = max(maxDetonated, count);
        }

        return maxDetonated;
    }
};
