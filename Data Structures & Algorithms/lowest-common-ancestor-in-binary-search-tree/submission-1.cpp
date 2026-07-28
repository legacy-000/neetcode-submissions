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
    TreeNode * lowest=new TreeNode(INT_MAX);
    TreeNode * maxi=new TreeNode(INT_MAX);
    bool find(TreeNode* root, TreeNode* node){
        if(!root && !node){
            return true;
        }
        if(root && !node){
            return true;
        }
        if(!root && node){
            return false;
        }
        return root->val==node->val||find(root->left, node)|| find(root->right, node);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool m1=find(root ,p);
        bool m2=find(root ,q);
        if(m1 && m2){
            bool a= find(root->left ,p);
            bool b=find(root->left,q);
            bool c=find(root->right, p);
            bool d=find(root->right, q);
            
            if(a && b){
                if(root->val<lowest->val){
                    lowest=root;
                    return lowestCommonAncestor(root->left, p, q);
                }
            }
            if(c && d){
                if(root->val<lowest->val){
                    lowest=root;
                    return lowestCommonAncestor(root->right,p, q);
                }
            }
            if(a && d || c && b){
                if(root->val<lowest->val){
                    lowest=root;
                    return lowest;
                }
            }
            
        }
    }
};
