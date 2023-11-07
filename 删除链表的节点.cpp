/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val)return head->next;
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *ln = dummyHead;
        while(ln){
            if(ln->next->val==val){
                ln->next = ln->next->next;
                return dummyHead->next;//这句很关键，题目中节点值互不相同
//说明只要找到了就可以返回，大大减少遍历时间！
            }
            ln = ln->next;
        }
        return dummyHead->next;
    }
};