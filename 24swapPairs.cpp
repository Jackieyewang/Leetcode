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
    ListNode* swapPairs(ListNode* head) {
        ListNode* pro = new ListNode(-1),*curr = pro, *tmp;
        pro->next = head;
        while(curr->next&&curr->next->next){
            tmp = curr->next->next;
            curr->next->next = tmp->next;
            tmp->next = curr->next;
            curr->next = tmp;
            curr = tmp->next;
        }
        return pro->next;
    }
};