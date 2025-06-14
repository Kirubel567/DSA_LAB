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
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
    TreeNode* first_wrong = nullptr;
    TreeNode* second_wrong = nullptr;
    TreeNode* prev_node = nullptr;

    void inorder_fix(TreeNode* node) {
        if (!node) return;

        inorder_fix(node->left);

        // Check if current node breaks the ascending order expected in BST inorder
        if (prev_node && prev_node->val > node->val) {
            if (!first_wrong) {
                first_wrong = prev_node;
            }
            second_wrong = node;  // Always update second wrong node
        }

        prev_node = node;  // Move forward in traversal

        inorder_fix(node->right);
    }

public:
    void recoverTree(TreeNode* root) {
        inorder_fix(root);

        if (first_wrong && second_wrong) {
            // Swap the values to fix the tree
            int temp_val = first_wrong->val;
            first_wrong->val = second_wrong->val;
            second_wrong->val = temp_val;
        }
    }
};
