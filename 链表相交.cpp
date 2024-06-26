
v1.0：感觉使用了虚拟头节点之后很顺利，直接模拟就可以写出来，不过就是感觉写的有点长？
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *dummyHeadA = new ListNode(0);
        ListNode *dummyHeadB = new ListNode(0);
        int lengthA = 0, lengthB = 0;
        dummyHeadA->next = headA;
        dummyHeadB->next = headB;
        ListNode *lna = dummyHeadA;
        ListNode *lnb = dummyHeadB;
        while(lna){
            lengthA++;
            lna = lna->next;
        }
        while(lnb){
            lengthB++;
            lnb = lnb->next;
        }
        int steps = 0;
        lna = dummyHeadA;
        lnb = dummyHeadB;
        if(lengthA>=lengthB){
            steps = lengthA - lengthB;
            while(steps--){
                lna = lna->next;
            }
            while(lna->next!=lnb->next){
                lna = lna->next;
                lnb = lnb->next;
            }
            if(lna->next==nullptr){
                return nullptr;
                }
            else{
                return lna->next;
            }
        }else{
            steps = lengthB - lengthA;
            while(steps--){
                lnb = lnb->next;
            }
            while(lna->next!=lnb->next){
                lna = lna->next;
                lnb = lnb->next;
            }
            if(lna->next==nullptr){
                return nullptr;
                }
            else{
                return lna->next;
            }

        }
    }
};


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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* dummyHeadA = new ListNode();
    ListNode* dummyHeadB = new ListNode();
    dummyHeadA->next = headA;
    dummyHeadB->next = headB;
    ListNode* cur = dummyHeadA;
    int lenA = 0, lenB = 0;
    while (cur)
    {
        cur = cur->next;
        lenA++;
    }
    cur = dummyHeadB;
    while (cur)
    {
        cur = cur->next;
        lenB++;
    }

    int delta = lenA - lenB;
    cur = dummyHeadA;
    ListNode* curB = dummyHeadB;
    if (delta > 0)//A比B长
    {
        while (delta--)
        {
            cur = cur->next;
        }
        while (cur != curB)
        {
            cur = cur->next;
            curB = curB->next;
        }
        return cur;
    }
    else
    {
        delta = -delta;
        while (delta--)
        {
            curB = curB->next;
        }
        while (cur != curB)
        {
            cur = cur->next;
            curB = curB->next;
        }
        return cur;
    }

    return nullptr;


}
};