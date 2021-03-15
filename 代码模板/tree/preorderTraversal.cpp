//recursive solution
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        solve(root);
        return ans;
    }
private:
    vector<int> ans;
    void solve(TreeNode *root){
        if(root == nullptr) return;
        ans.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }
};

//iterative solution -- recommend
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode *> stk;
        stk.push(root);
        while(stk.size()){
            auto node = stk.top();
            stk.pop();
            ans.push_back(node->val);
            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left);
        }
        return ans;
    }
};