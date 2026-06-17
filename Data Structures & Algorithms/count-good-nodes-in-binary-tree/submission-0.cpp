/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    
    int count=0;
    void countgoodnodes(TreeNode* root, int big){
        if(!root){
            return;
        }
        if(root->val>big){
            big=root->val;
        }
        if(root->val==big){
            count=count+1;
        }
        countgoodnodes(root->left, big);
        countgoodnodes(root->right, big);
    }
    int goodNodes(TreeNode* root) {
        int big=INT_MIN;
        countgoodnodes(root, big);
        return count;
    }
};
