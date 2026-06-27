class Solution {
public:
    ListNode* removeElements(ListNode* head, int va) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != NULL) {
            if (curr->val == va) {
                prev->next = curr->next;
                ListNode* del = curr;
                curr = curr->next;
                delete del;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};