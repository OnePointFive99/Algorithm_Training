
v1.0:通过这道题才算是真正理解了cur与cur->next的区别！
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *cur = dummyHead;
        while(cur->next&&cur->next->next){
            ListNode *tmp1 = cur->next->next->next;//3号
            ListNode *tmp2 = cur->next->next;//2号
            cur->next->next->next =  cur->next;//2号指向1号
            cur->next->next = tmp1;//1号指向3号
            cur->next = tmp2;//cur指向2号
            cur= cur->next->next;//cur移动到交换后的1号 
        }
        return dummyHead->next;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    ListNode* dummyHead = new ListNode();
    dummyHead->next = head;
    ListNode* pre = dummyHead;
    
    while (pre->next&&pre->next->next)
    {
        ListNode* left = pre->next;
        ListNode* right = pre->next->next;
        pre->next = right;
        left->next = right->next;
        right->next = left;
        pre = left;
    }
    return dummyHead->next;
}
};