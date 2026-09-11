class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;

        node->val = temp->val;
        node->next = temp->next;

        delete temp;
    }
};
// temp = node->next;       // save next

// node->val = temp->val;   // make current look like next

// node->next = temp->next; // skip next

// delete temp;             // remove old next