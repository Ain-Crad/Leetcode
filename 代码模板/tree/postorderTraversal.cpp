
//recursive solution
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        solve(root);
        return ans;
    }
    
private:
    vector<int> ans;
    void solve(TreeNode *root){
        if(root == nullptr) return;
        solve(root->left);
        solve(root->right);
        ans.push_back(root->val);
    }
};

//iterative solution -- recommend
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        stack<TreeNode*> stk;
        stk.push(root);
        while(stk.size()){
            auto node = stk.top();
            if(!node->left && !node->right) ans.push_back(node->val), stk.pop();
            if(node->right) stk.push(node->right), node->right = nullptr;
            if(node->left) stk.push(node->left), node->left = nullptr;
        }
        return ans;
    }
};