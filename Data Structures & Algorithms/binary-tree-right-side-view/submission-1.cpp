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
    void bfs(TreeNode* root, vector<int>& ans, vector<int>& current){
        queue<TreeNode*> q;
        if(!root){
            return ;
        }
        q.push(root);
        ans.push_back(root->val);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* top=q.front();
                q.pop();
                if(top->left){
                    current.push_back(top->left->val);
                    q.push(top->left);
                }
                if(top->right){
                    current.push_back(top->right->val);
                    q.push(top->right);
                }
            }
            if(!current.empty()){
            ans.push_back(current.back());
            }
            current.clear();
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        vector<int> current;
        bfs(root, ans, current);
        return ans;
    }
};
