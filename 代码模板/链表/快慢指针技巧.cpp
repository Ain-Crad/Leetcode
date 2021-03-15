// 快慢指针技巧 one pass求链表中点
// 注意设置pre也是技巧之一

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head && head->next == nullptr) return new TreeNode(head->val);
        
        ListNode *pre = nullptr, *slow = head, *fast = head;
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};