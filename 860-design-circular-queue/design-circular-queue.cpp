
class MyCircularQueue {
    int *arr;          // Pointer to dynamically allocated array
    int front, rear;   // Indices of first and last elements
    int n;             // Maximum capacity of queue

public:
    // Constructor: initialize an empty circular queue
    MyCircularQueue(int k) {
        n = k;
        arr = new int[n];      // Allocate an array of size k
        front = rear = -1;     // -1 means queue is empty
    }

    // Insert an element at the rear
    bool enQueue(int value) {
        if (isFull()) return false;  // Cannot insert if full

        if (isEmpty()) {
            front = rear = 0;        // First element
        } else {
            rear = (rear + 1) % n;   // Move rear circularly
        }

        arr[rear] = value;           // Store the element
        return true;
    }

    // Remove the front element
    bool deQueue() {
        if (isEmpty()) return false; // Nothing to remove

        if (front == rear) {
            // Only one element existed; queue becomes empty
            front = rear = -1;
        } else {
            front = (front + 1) % n; // Move front circularly
        }

        return true;
    }

    // Return the front element without removing it
    int Front() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    // Return the rear element without removing it
    int Rear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if the circular queue is full
    bool isFull() {
        return (rear + 1) % n == front;
    }
};
