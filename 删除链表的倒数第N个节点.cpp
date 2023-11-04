注意使用虚拟头节点，可以避免对头节点的判断，防止各种复杂情况
v1.0(未通过：错误原因是没有对头节点进行判断):
if(head->next==nullptr)return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(n--&&fast!=nullptr){
            fast = fast->next;
        }
        fast = fast->next;
        while(fast){
            slow = slow->next;
            fast = fast->next;
        
        }
            slow->next= slow->next->next;

        
        return head;
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
v2.0：虚拟头节点实在是太好用啦！！！
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        while(n--&&fast){
            fast = fast->next;
        }
        fast = fast->next;
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummyHead->next;



    }
};