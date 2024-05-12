v1.0 这道题很巧妙，是看了随想录的讲解才做出来的
1. 判断有无环:定义快慢指针，快指针一次走两个节点，慢指针走一个，快指针追上慢指针说明有环
2. 追上时需要纸笔列下式子，此时快慢指针走过的节点数量，然后要求的是从开始节点到进入环的节点的长度
3. 具体推导可以看随想录，总之就是需要列一下式子就可以找出关系了~
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *aux = head;
        while(fast&&fast->next){
            fast= fast->next->next;
            slow = slow->next;
            if(fast==slow){
                while(aux!=slow){
                    slow=slow->next;
                    aux=aux->next;
                }
                return aux;
            }
        }
        return nullptr;
        
    }
};

哈希表方法
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
    ListNode* detectCycle(ListNode* head) {
    unordered_set<ListNode*> visited;
    ListNode* cur = head;
    while (cur)
    {
        if (visited.count(cur))
        {
            return cur;
        }
        visited.insert(cur);
        cur = cur->next;
    }
    return nullptr;
}
};