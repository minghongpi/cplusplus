struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* res = new ListNode(-1);
        ListNode* cur = res;
        while (l1 || l2)
        {
            int num1 = l1 ? l1->val : 0;
            if (l1) l1 = l1->next;
            int num2 = l2 ? l2->val : 0;
            if (l2) l2 = l2->next;
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }
        if (carry > 0)
        {
            cur->next = new ListNode(carry);
        }
        return res->next;
    }
};
