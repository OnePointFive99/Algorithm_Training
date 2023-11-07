v1.0:
跟移除链表节点很相似，不同的是链表节点值可能会重复，
需要将链表遍历完，并且需要考虑连续重复的情况
然后头节点因为没有前置节点，删除时需要特殊处理，除非使用虚拟头节点，可以看随想录的讲解
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode * node = dummyHead;
        while(node&&node->next){
            while(node->next&&node->next->val==val){
                node->next=node->next->next;
            }
            node = node->next;
        }
        return dummyHead->next;

    }
};

v2.0:添加了对节点的delete
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode * node = dummyHead;
        while(node&&node->next){
            while(node->next&&node->next->val==val){
                ListNode *tmp = node->next;
                node->next=node->next->next;
                delete tmp;//专门声明一个指针用来delete指定节点
            }
            node = node->next;
        }
        head = dummyHead->next;
        delete dummyHead;//删除申请的dummyHead
        return head;

    }
};

