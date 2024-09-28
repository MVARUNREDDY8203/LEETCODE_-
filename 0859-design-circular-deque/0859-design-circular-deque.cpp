class MyCircularDeque {
public:
    struct Node {
        int val;
        Node* prev;
        Node* next;

        Node (int val): val(0), prev(nullptr), next(nullptr) {}
        Node (int v, Node* p, Node* n): val(v), prev(p), next(n) {} 
    };
    int size;
    int curr_size;
    Node* start;
    Node* end;
    MyCircularDeque(int k) {
        size = k;
        curr_size = 0;
        start = new Node(0);
        end = new Node(0);
        start->next = end;
        end->prev = start;
    }
    
    bool insertFront(int value) {
        if (curr_size == size) return false;

        Node* start_next = start->next;
        start->next = new Node(value, start, start_next);
        start_next->prev = start->next;
        curr_size++;

        return true;
    }
    
    bool insertLast(int value) {
        if (curr_size == size) return false;

        Node* end_prev = end->prev;
        end->prev = new Node(value, end_prev, end);
        end_prev->next = end->prev;
        curr_size++;

        return true;
    }
    
    bool deleteFront() {
        if (curr_size > 0) {
            Node* start_next_next = start->next->next;
            start->next = start_next_next;
            start_next_next->prev = start;
            curr_size--;
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if (curr_size > 0) {
            Node* end_prev_prev = end->prev->prev;
            end->prev = end_prev_prev;
            end_prev_prev->next = end;
            curr_size--;
            return true;
        }
        return false;
    }
    
    int getFront() {
        if (curr_size > 0) {
            return start->next->val;
        }
        return -1;
    }
    
    int getRear() {
        if (curr_size > 0) {
            return end->prev->val;
        }
        return -1;
    }
    
    bool isEmpty() {
        return curr_size == 0;
    }
    
    bool isFull() {
        return curr_size == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */