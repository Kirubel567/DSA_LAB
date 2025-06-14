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
    void dfs(const string& current, const string& target, map<string, double>& rates, 
             map<string, vector<string>>& graph, double& result, map<string, bool>& visited, bool& found) {
        visited[current] = true;

        if (found) return;

        for (const auto& neighbor : graph[current]) {
            if (!visited[neighbor]) {
                result *= rates[current + "->" + neighbor];
                
                if (neighbor == target) {
                    found = true;
                    return;
                }

                dfs(neighbor, target, rates, graph, result, visited, found);

                if (found) return;
                else result /= rates[current + "->" + neighbor]; // backtrack
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> answers;
        map<string, double> rates;
        map<string, vector<string>> graph;

        // Build graph and rate mappings
        for (int i = 0; i < equations.size(); ++i) {
            string from = equations[i][0];
            string to = equations[i][1];

            rates[from + "->" + to] = values[i];
            rates[to + "->" + from] = 1.0 / values[i];

            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        for (const auto& query : queries) {
            const string& start = query[0];
            const string& end = query[1];

            if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
                answers.push_back(-1.0);
                continue;
            }

            if (start == end) {
                answers.push_back(1.0);
                continue;
            }

            double value = 1.0;
            map<string, bool> visited;
            bool found = false;

            dfs(start, end, rates, graph, value, visited, found);

            answers.push_back(found ? value : -1.0);
        }

        return answers;
    }
};
