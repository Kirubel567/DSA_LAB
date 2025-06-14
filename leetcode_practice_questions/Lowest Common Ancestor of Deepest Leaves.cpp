#include<iostream> 
#include<vector> 
#include<queue>
#include<utility> 
#include<unordered_set>
#include<string>
#include<numeric> 
#include<algorithm> 
#include<unordered_map>
#include<map>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    // Finds the lowest common ancestor of the deepest leaves starting at currentDepth
    TreeNode* findAncestor(TreeNode* node, int currentDepth, int maxDepth) {
        if (!node) return nullptr;

        if (currentDepth == maxDepth - 1) {
            // At one level above deepest leaves, return this node
            return node;
        }

        TreeNode* leftSide = findAncestor(node->left, currentDepth + 1, maxDepth);
        TreeNode* rightSide = findAncestor(node->right, currentDepth + 1, maxDepth);

        if (leftSide && rightSide) {
            // Both sides have deepest leaves, then current node is their common ancestor
            return node;
        }

        // Return whichever subtree contains deepest leaves
        return leftSide ? leftSide : rightSide;
    }

    // Calculate tree height by going down to leaf nodes
    int getTreeHeight(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = getTreeHeight(root->left);
        int rightHeight = getTreeHeight(root->right);
        return 1 + max(leftHeight, rightHeight);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int height = getTreeHeight(root);
        return findAncestor(root, 0, height);
    }
};
