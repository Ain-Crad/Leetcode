
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

//iterative solution --recommend1
// space: O(n)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};

        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        unordered_set<TreeNode*> vis;

        while(cur || stk.size()){
            while(cur){
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top();
            if(cur->right && !vis.count(cur->right)){
                vis.insert(cur->right);
                cur = cur->right;
            }else{
                ans.push_back(cur->val);
                stk.pop();
                cur = nullptr;
            }
        }

        return ans;
    }
};

//iterative solution --recommend2
// space: O(1)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};

        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;

        while(cur || stk.size()){
            while(cur){
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top();
            if(cur->right && cur->right != pre){
                cur = cur->right;
            }else{
                ans.push_back(cur->val);
                stk.pop();
                pre = cur;
                cur = nullptr;
            }
        }

        return ans;
    }
};

//iterative solution
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