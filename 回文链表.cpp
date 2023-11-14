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
    bool isPalindrome(ListNode* head) {
        vector<int> result;
        ListNode *cur = head;
        while(cur){
            result.push_back(cur->val);
            cur = cur->next;
        }
        for(int i = 0, j = result.size()-1;i<=j;i++,j--){
            if(result[i]!=result[j])return false;
        }
        return true;
    }
};



1