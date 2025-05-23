class MyCircularQueue {
public:
    vector<int> q;
    int f, r, n;

    MyCircularQueue(int k) {
        n = k + 1;
        q.resize(n);
        f = r = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        q[r] = value;
        r = (r + 1) % n;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        f = (f + 1) % n;
        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;
        return q[f];
    }

    int Rear() {
        if (isEmpty())
            return -1;
        return q[(r - 1 + n) % n];
    }

    bool isEmpty() { return f == r; }

    bool isFull() { return (r + 1) % n == f; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */