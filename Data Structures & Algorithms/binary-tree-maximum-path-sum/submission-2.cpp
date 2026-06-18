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
int maxsum=INT_MIN;
    int PathSum(TreeNode* root){
        if(!root){
            return 0;
        }
        int leftpathsum=root->val+max(0,PathSum(root->left));
        int rightpathsum=root->val+max(0,PathSum(root->right));
        return max(leftpathsum, rightpathsum);
    }
    void maxPath(TreeNode* root){
        if(!root){
            return ;
        }
        int rootpath=root->val+max(0,PathSum(root->left))+max(0,PathSum(root->right));
        maxsum=max(maxsum,rootpath);
        maxPath(root->left);
        maxPath(root->right);
    }
    int maxPathSum(TreeNode* root){
        maxPath(root);
        return maxsum;
    }
};
