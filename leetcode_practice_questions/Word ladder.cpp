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
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int res = 1;
        unordered_set<string> set1 {beginWord};
        unordered_set<string> set2 {endWord};
        
        while (set1.size()) {
            res++;
            unordered_set<string> set;
            for (auto word : set1) wordList.erase(word);
            for (auto word :set1) {
                for (size_t i = 0; i < word.size(); ++i) {
                    string next = word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        next[i] = c;
                        if (wordList.find(next) == wordList.end()) continue;
                        if (set2.find(next) != set2.end()) return res;
                        set.insert(next);
                    }
                }
            }
            set1 = set.size() < set2.size() ? set : set2;
            set2 = set.size() < set2.size() ? set2 : set;
        }
        
        return 0;
    }
};