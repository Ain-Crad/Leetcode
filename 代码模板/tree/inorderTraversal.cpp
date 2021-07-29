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

// iterative solution  -- recommend
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        unordered_set<TreeNode*> vis;
        vector<int> ans;
        stack<TreeNode*> stk;
        stk.push(root);
        while(stk.size()){
            auto node = stk.top();
            if(node->left && vis.find(node->left) == vis.end()) {
                stk.push(node->left);
                vis.insert(node->left);
            }
            else {
                ans.push_back(node->val);
                stk.pop();
                if(node->right) stk.push(node->right);
            }
        }
        return ans;
    }
};

// iterative solution 2
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(cur || stk.size()){
            while(cur){
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            ans.push_back(cur->val);

            cur = cur->right;
        }
        return ans;
    }
};

// iterative solution 3
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // 指针来访问节点，访问到最底层
                st.push(cur); // 将访问的节点放进栈
                cur = cur->left;                // 左
            } else {
                cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
                st.pop();
                result.push_back(cur->val);     // 中
                cur = cur->right;               // 右
            }
        }
        return result;
    }
};

