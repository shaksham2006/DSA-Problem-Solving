/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) {
            return head;
        }

        Node* curr = head;
        while (curr != NULL) {
            if (curr->child != NULL) {
                // Store the current next node to reconnect later
                Node* nextNode = curr->next;

                // 1. Flatten the child nodes
                Node* childHead = flatten(curr->child);

                // 2. Attach current to the child head
                curr->next = childHead;
                childHead->prev = curr;
                curr->child = NULL; // Important: Clear the child pointer

                // 3. Find the tail of the flattened child list
                Node* tail = childHead;
                while (tail->next != NULL) {
                    tail = tail->next;
                }

                // 4. Attach tail to the original next node
                tail->next = nextNode;
                if (nextNode != NULL) {
                    nextNode->prev = tail;
                }
            }
            // Move to the next node
            curr = curr->next;
        }
        return head;
    }

    
};