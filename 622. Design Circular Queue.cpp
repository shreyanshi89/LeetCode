class MyCircularQueue {
public:
    vector<int> q;
    int rear = -1;
    int front = -1;
    int size = 0;
    
    MyCircularQueue(int k) {
        q.resize(k);
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        rear = (rear + 1) % size;
        if(front == -1)
            front = 0;
        q[rear] = value;
        return true;       
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        else if(front == rear){
            rear = -1;
            front = -1;
        }
        else
            front = (front+1) % size;
        return true;
    }
    
    int Front() {
        return isEmpty()? -1:q[front];
    }
    
    int Rear() {
        return isEmpty()? -1:q[rear];
    }
    
    bool isEmpty() {
        if(rear == -1)
            return true;
        return false;
    }
    
    bool isFull() {
        if((rear + 1) % size == front)
            return true;
        return false;
    }
};
