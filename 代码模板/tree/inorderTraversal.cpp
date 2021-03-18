// recursive solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        return ans;
    }
private:
    vector<int> ans;
    void solve(TreeNode *root){
        if(root == nullptr) return;
        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);
    }
};

// iterative solution --recommend
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        stack<TreeNode *> stk;
        stk.push(root);
        while(stk.size()){
            auto node = stk.top();
            if(node->left) stk.push(node->left), node->left = nullptr;
            else{
                ans.push_back(node->val);
                stk.pop();
                if(node->right) stk.push(node->right);
            }
        }
        return ans;
    }
};

// iterative solution --typical
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        while (root || s.size()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
};