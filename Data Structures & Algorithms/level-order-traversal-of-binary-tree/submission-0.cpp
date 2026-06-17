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
    void bfs(TreeNode* root, vector<int>& current , vector<vector<int>>& ans){
        queue<TreeNode*> q;
        if(!root){
            return;
        }
        q.push(root);
        current.push_back(root->val);
        ans.push_back(current);
        current.clear();
        while(!q.empty()){
            
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* top=q.front();
                q.pop();
                if(top->left){
                    q.push(top->left);
                    current.push_back(top->left->val);
                }
                if(top->right){
                    q.push(top->right);
                    current.push_back(top->right->val);
                }   
               
            }
            if(!current.empty()){
            ans.push_back(current);}
             current.clear();
        }

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> current;
        bfs(root, current , ans);
        return ans;
    }
};
