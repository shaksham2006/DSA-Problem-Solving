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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* l = head;
        ListNode* r = head;
        ListNode* lprev = NULL;
        for(int i = 1; i < left; i++) {
            lprev = l;
            l = l->next;
        }
        for(int i = 1; i < right; i++) {
            r = r->next;
        }
        ListNode* rnext = r->next;
        ListNode* temp = l;
        ListNode* next = NULL;
        ListNode* prev = lprev;
        while(temp != rnext) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        if(lprev != NULL) {
            lprev->next = prev;
        }
        else {
            head = prev;
        }
        l->next = rnext;
        return head;
    }
};