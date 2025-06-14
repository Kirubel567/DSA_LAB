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
    // Function to compute the shortest path (word ladder)
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (beginWord == endWord) return 1;

        int steps = 1; // start at 1 since we include the start word

        unordered_set<string> frontSet = {beginWord}; // BFS from this side
        unordered_set<string> backSet = {endWord};    // BFS from the end
        unordered_set<string> dict = wordList;

        // Early check if the end word isn't in dictionary at all
        if (!dict.count(endWord)) return 0;

        // Start two-ended BFS
        while (!frontSet.empty() && !backSet.empty()) {
            steps++;

            // Always expand from the smaller side for performance
            if (frontSet.size() > backSet.size()) {
                swap(frontSet, backSet);
            }

            unordered_set<string> nextLevel;

            // Remove all current level words from the dictionary
            for (const auto& word : frontSet) {
                dict.erase(word);
            }

            for (const string& word : frontSet) {
                string current = word;
                for (int i = 0; i < current.length(); i++) {
                    char originalChar = current[i];

                    // Try replacing each character with 'a' to 'z'
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == originalChar) continue; // Skip same character

                        current[i] = ch;

                        if (backSet.count(current)) return steps;

                        if (dict.count(current)) {
                            nextLevel.insert(current);
                        }
                    }

                    // Restore the original character before moving to next index
                    current[i] = originalChar;
                }
            }

            // Move to the next level
            frontSet = move(nextLevel);
        }

        return 0; // If no connection found
    }
};
