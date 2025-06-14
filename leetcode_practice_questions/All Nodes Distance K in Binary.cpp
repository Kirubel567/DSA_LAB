#include<iostream> 
#include<vector> 
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<set> 
using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //make a map for parent nodes
        unordered_map<TreeNode*, TreeNode*> par;
        findParentRefs(root, par); // build it

        set<TreeNode*> seen; // just to not repeat nodes
        queue<TreeNode*> q1;
        q1.push(target);
        seen.insert(target);
        
        int dist = 0;

        while (!q1.empty()) {
            if (dist == k) break;
            int loopSize = q1.size();
            for (int j = 0; j < loopSize; j++) {
                TreeNode* cur = q1.front();
                q1.pop();

                // move left if not seen
                if (cur->left != NULL && seen.find(cur->left) == seen.end()) {
                    q1.push(cur->left);
                    seen.insert(cur->left);
                }

                // move right
                if (cur->right && seen.count(cur->right) == 0) {
                    q1.push(cur->right);
                    seen.insert(cur->right);
                }

                // move up to parent
                TreeNode* p = par[cur]; // use from map
                if (p && !seen.count(p)) {
                    q1.push(p);
                    seen.insert(p);
                }
            }
            dist++;
        }

        vector<int> resSet;
        while (!q1.empty()) {
            TreeNode* node = q1.front(); q1.pop();
            resSet.push_back(node->val); // collect value
        }

        return resSet;
    }

    // grab each node's parent
    void findParentRefs(TreeNode* n, unordered_map<TreeNode*, TreeNode*>& mapz) {
        queue<TreeNode*> qqq;
        qqq.push(n);
        while (!qqq.empty()) {
            TreeNode* now = qqq.front(); qqq.pop();
            if (now->left != NULL) {
                mapz[now->left] = now;
                qqq.push(now->left);
            }
            if (now->right) {
                mapz[now->right] = now;
                qqq.push(now->right);
            }

        }
    }
};
