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
    // Function to find the number of connected components (provinces) in the graph
    int findCircleNum(vector<vector<int>>& graph) {
        int n = graph.size();               // Number of nodes in the graph
        vector<bool> visited(n, false);     // Keep track of visited nodes
        int count = 0;                      // To count the number of provinces
        
        // Check each node
        for (int node = 0; node < n; ++node) {
            // If this node hasn't been visited yet, it means a new province found
            if (!visited[node]) {
                bfsExplore(node, graph, visited);  // Explore all connected nodes using BFS
                ++count;                           // Increase count for each new province found
            }
        }
        
        return count;  // Return total number of provinces
    }
    
private:
    // BFS function to explore all nodes connected to 'startNode'
    void bfsExplore(int startNode, vector<vector<int>>& graph, vector<bool>& visited) {
        queue<int> q;                   // Queue to help with BFS traversal
        q.push(startNode);              // Start from the given node
        visited[startNode] = true;     // Mark the start node as visited
        
        while (!q.empty()) {
            int current = q.front();   // Get the front node from queue
            q.pop();                   // Remove it from queue
            
            // Look at every neighbor of the current node
            for (int neighbor = 0; neighbor < graph.size(); ++neighbor) {
                // If there is a connection and neighbor is not visited yet
                if (graph[current][neighbor] == 1 && !visited[neighbor]) {
                    visited[neighbor] = true;  // Mark neighbor as visited
                    q.push(neighbor);          // Add neighbor to queue for further exploration
                }
            }
        }
    }
};
