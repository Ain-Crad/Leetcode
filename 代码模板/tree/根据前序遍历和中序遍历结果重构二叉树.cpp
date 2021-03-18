// leetcode-105. Construct Binary Tree from Preorder and Inorder Traversal
// 只适用于不包含重复元素的条件下

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 0) return nullptr;

        for(int i = 0; i < n; ++i) val_idx[inorder[i]] = i;

        return build(preorder, 0, n - 1, inorder, 0, n - 1);
    }

private:
    unordered_map<int, int> val_idx;
    TreeNode* build(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir){
        if(pl > pr) return nullptr;
        if(pl == pr) return new TreeNode(preorder[pl]);

        TreeNode *node = new TreeNode(preorder[pl]);

        int v = preorder[pl], mid = val_idx[v];

        int left_sz = mid - il, right_sz = ir - mid;
        node->left = build(preorder, pl + 1, pl + left_sz, inorder, il, mid - 1);
        node->right = build(preorder, pl + left_sz + 1, pr, inorder, mid + 1, ir);

        return node;
    }
};