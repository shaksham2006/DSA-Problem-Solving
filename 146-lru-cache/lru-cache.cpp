

class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node *next, *prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    // Dummy head and tail to simplify list operations
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int limit;
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void delNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* resNode = m[key];
            int res = resNode->val;
            m.erase(key);
            delNode(resNode);
            addNode(resNode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int val) {
        // 1. If key exists, delete the old version
        if (m.find(key) != m.end()) {
            Node* oldNode = m[key];
            m.erase(key);
            delNode(oldNode);
        }

        // 2. If at capacity, remove the LRU (tail->prev)
        if (m.size() == limit) {
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }

        // 3. Insert new node at the head (Most Recently Used)
        addNode(new Node(key, val));
        m[key] = head->next;
    }
};
