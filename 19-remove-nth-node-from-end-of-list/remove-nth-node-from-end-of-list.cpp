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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;
        while(temp!=0){
            count++;
            temp = temp->next;
        }
        int pos = count - n + 1;
        if(pos == 1){
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(pos>1){
            prev = curr;
            curr = curr->next;
            pos--;
        }
        prev->next = curr->next;
        delete curr;
        return head;
    }
};