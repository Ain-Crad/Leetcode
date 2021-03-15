// leetcode-236. Lowest Common Ancestor of a Binary Tree

// solution1: recursion
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
    
private:
    TreeNode* ans = nullptr;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr) return false;
        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);
        
        if(left && right) ans = root;
        if((root == p || root == q) && (left || right)) ans = root;
        
        return (root == p || root == q) || left || right;
    }
};

// solution2: record parent node
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        parent[root] = nullptr;
        GetParent(root);
        
        unordered_set<TreeNode*> rec;
        TreeNode* node = p;
        while(node){
            rec.insert(node);
            node = parent[node];
        }
        node = q;
        while(node){
            if(rec.count(node)) return node;
            node = parent[node];
        }
        return nullptr;
    }
    
private:
    unordered_map<TreeNode*, TreeNode*> parent;
    void GetParent(TreeNode* root){
        if(root->left){
            parent[root->left] = root;
            GetParent(root->left);
        }
        if(root->right){
            parent[root->right] = root;
            GetParent(root->right);
        }
    }
};