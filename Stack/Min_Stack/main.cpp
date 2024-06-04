struct Node {
    int val;
    int minNode;
    Node *next;
    Node *prev;

    Node () {
        val = INT_MIN;
        next = nullptr;
        prev = nullptr;
    }
};

class MinStack {
public:
    MinStack() {
        Node *newNode = new Node;
        topNode = newNode;
    }

    void push(int val) {
        if (topNode->val == (INT_MIN) && topNode->next == nullptr && topNode->prev == nullptr) {
            topNode->val = val;
            topNode->minNode = val;
            return;
        }

        Node *newNode = new Node;
        newNode->val = val;

        if (newNode->val < topNode->minNode) {
            newNode->minNode = val;
        }
        else {
            newNode->minNode = topNode->minNode;
        }
        topNode->next = newNode;
        newNode->prev = topNode;
        topNode = newNode;

    }

    void pop() {
        if (topNode->prev == nullptr) {
            delete topNode;
            topNode = new Node;
            return;
        }
        topNode = topNode->prev;

    }

    int top() {
        return topNode->val;
    }

    int getMin() {
        return topNode->minNode;
    }

private:
    Node *topNode;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */