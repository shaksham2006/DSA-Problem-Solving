class MyLinkedList {
    struct Node{
        public:
            int data;
            Node* next;
            Node* prev;

            Node(int val){
                data = val;
                next = NULL;
                prev = NULL;
            }
    };
public:
    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
        head = tail = NULL;
        size = 0;
    }

    int getlength(){
        return size;
    }

    int get(int index) {
        if(index < 0 || index >= size) return -1;

        if(index == 0) return head->data;
        if(index == size-1) return tail->data;

        if(index < size/2){
            int count = 0;
            Node* temp = head;

            while(temp != NULL){
                if(count == index) return temp->data;
                count++;
                temp = temp->next;
            }
        }
        else{
            int count = size-1;
            Node* temp = tail;

            while(temp != NULL){
                if(count == index) return temp->data;
                count--;
                temp = temp->prev;
            }
        }

        return -1;
    }
    
    void addAtHead(int val) {
        Node* temp = new Node(val);

        if(head == NULL){
            head = tail = temp;
        }
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }

        size++;
    }
    
    void addAtTail(int val) {
        Node* temp = new Node(val);

        if(tail == NULL){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }

        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;

        if(index == 0){
            addAtHead(val);
            return;
        }

        if(index == size){
            addAtTail(val);
            return;
        }

        if(index < size/2){
            int count = 0;
            Node* temp1 = head;

            while(temp1 != NULL){
                if(count == index-1){
                    Node* temp = new Node(val);

                    temp->next = temp1->next;
                    temp->prev = temp1;

                    temp1->next->prev = temp;
                    temp1->next = temp;

                    size++;
                    break;
                }

                count++;
                temp1 = temp1->next;
            }
        }
        else{
            int count = size-1;
            Node* temp1 = tail;

            while(temp1 != NULL){
                if(count == index){
                    Node* temp = new Node(val);

                    temp->next = temp1;
                    temp->prev = temp1->prev;

                    temp1->prev->next = temp;
                    temp1->prev = temp;

                    size++;
                    break;
                }

                count--;
                temp1 = temp1->prev;
            }
        }
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;

        if(index == 0){
            Node* temp = head;

            head = head->next;

            if(head != NULL)
                head->prev = NULL;
            else
                tail = NULL;

            delete temp;
            size--;
            return;
        }

        if(index == size-1){
            Node* temp = tail;

            tail = tail->prev;

            if(tail != NULL)
                tail->next = NULL;
            else
                head = NULL;

            delete temp;
            size--;
            return;
        }

        if(index < size/2){
            int count = 0;
            Node* temp = head;

            while(temp != NULL){
                if(count == index){
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;

                    delete temp;
                    size--;
                    return;
                }

                count++;
                temp = temp->next;
            }
        }
        else{
            int count = size-1;
            Node* temp = tail;

            while(temp != NULL){
                if(count == index){
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;

                    delete temp;
                    size--;
                    return;
                }

                count--;
                temp = temp->prev;
            }
        }
    }
};