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


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

class Solution {
public:
    void traverse(TreeNode* root,int count,int &sum){
        if(!root)return;
        count*=10;
        count+=root->val;
        if(!root->right and !root->left){
            sum+=count;
            return;
        }
        traverse(root->left,count,sum);
        traverse(root->right,count,sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        traverse(root,0,sum);
        return sum;
    }
};
