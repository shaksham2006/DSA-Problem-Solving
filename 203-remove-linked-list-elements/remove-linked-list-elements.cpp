class Solution {
public:
    ListNode* removeElements(ListNode* head, int va) {

        while (head != NULL && head->val == va) {
            ListNode* del = head;
            head = head->next;
            delete del;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            if (temp->val == va) {
                prev->next = temp->next;
                ListNode* del = temp;
                temp = temp->next;
                delete del;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};