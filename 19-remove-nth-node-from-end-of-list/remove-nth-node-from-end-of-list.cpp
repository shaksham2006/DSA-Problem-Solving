class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;

        while(temp != NULL) {
            count++;
            temp = temp->next;
        }

        int pos = count - n + 1;

        // Delete head
        if(pos == 1) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;

        for(int i = 1; i < pos; i++) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        delete curr;

        return head;
    }
};