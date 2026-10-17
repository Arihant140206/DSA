
class MyCircularDeque {
    int* arr;          // Pointer to dynamically allocated array
    int front, rear;   // Indices of first and last elements
    int n;             // Maximum capacity

public:
    // Constructor: initialize an empty deque
    MyCircularDeque(int k) {
        n = k;
        arr = new int[n];      // Allocate array of size k
        front = rear = -1;     // -1 means deque is empty
    }

    // Insert an element at the front
    bool insertFront(int value) {
        if (isFull()) return false;  // Cannot insert if full

        if (isEmpty()) {
            front = rear = 0;        // First element
        } else {
            // Move front one position backward circularly
            front = (front - 1 + n) % n;
        }

        arr[front] = value;
        return true;
    }

    // Insert an element at the rear
    bool insertLast(int value) {
        if (isFull()) return false;  // Cannot insert if full

        if (isEmpty()) {
            front = rear = 0;        // First element
        } else {
            // Move rear one position forward circularly
            rear = (rear + 1) % n;
        }

        arr[rear] = value;
        return true;
    }

    // Delete the front element
    bool deleteFront() {
        if (isEmpty()) return false; // Nothing to delete

        if (front == rear) {
            // Only one element; deque becomes empty
            front = rear = -1;
        } else {
            // Move front one position forward circularly
            front = (front + 1) % n;
        }

        return true;
    }

    // Delete the rear element
    bool deleteLast() {
        if (isEmpty()) return false; // Nothing to delete

        if (front == rear) {
            // Only one element; deque becomes empty
            front = rear = -1;
        } else {
            // Move rear one position backward circularly
            rear = (rear - 1 + n) % n;
        }

        return true;
    }

    // Return the front element without removing it
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    // Return the rear element without removing it
    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    // Check whether the deque is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check whether the deque is full
    bool isFull() {
        return (rear + 1) % n == front;
    }
};
