第一次尝试链表题，感觉思路很简单，主要是有些内容需要注意：
1. 用指针定义的结构体或类的成员用->访问，cur->next等价于(*cur).next
2. 链表双指针重要的是指针朝向的更新，循环条件看看是不是快指针，但是返回的指针注意不要是指向null的
3. 指针的结构体：
struct LinkedList{
    int val;
    LinkedList* next;
};
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
    ListNode* reverseList(ListNode* head) {
        ListNode* tmp;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;

    }
};

v2.0:使用虚拟头节点来做这道题，可见虚拟头节点并不是必要的
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
struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x), next(next){}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *slow = nullptr;
        ListNode *fast = head;
        ListNode *tmp;
        while(fast){
            tmp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = tmp;
        }
        // delete dummyHead;
        dummyHead = nullptr;
        return slow;

    }
};

v3.0:写反转链表完全不需要虚拟头节点，把nullptr"作为"头节点即可
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* left = nullptr;
        ListNode* right = head;
        while (right)
        {
            ListNode* tmp = right->next;
            right->next = left;
            left = right;
            right = tmp;
        }

        return left;
    }
};