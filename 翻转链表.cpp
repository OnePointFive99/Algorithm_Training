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