/**
 * Design Front Middle Back Queue
 * 
 * Design a queue that supports `push` and `pop` operations in the front, middle, and back.
 * 
 * Implement the FrontMiddleBack class:
 * 
 * FrontMiddleBack() Initializes the queue.
 * void pushFront(int val) Adds val to the front of the queue.
 * void pushMiddle(int val) Adds val to the middle of the queue.
 * void pushBack(int val) Adds val to the back of the queue.
 * int popFront() Removes the front element of the queue and returns it. If the queue is empty, return -1.
 * int popMiddle() Removes the middle element of the queue and returns it. If the queue is empty, return -1.
 * int popBack() Removes the back element of the queue and returns it. If the queue is empty, return -1.
 * 
 */

#include<iostream>
#include<vector>

using namespace std; 

class Node {
    public:
    int val;
    Node *next, *pre;
    
    Node(int val = 0, Node *next = nullptr, Node *pre = nullptr) : val(val), next(next), pre(pre) {}
    
    void insertPre(Node *p) {
        p->pre = pre;
        p->next = this;
        if(this->pre) { 
            this->pre->next = p;
            }
        this->next = p;
        return ;
    }

    void insertNext(Node *p) {
        p->pre = this;
        p->next = this->next;
        if(this->next){
            this->next->pre = p;
        }
        this->next = p;
        return;
    }

    void deletePre() {
        if(this->pre == nullptr) { return ;}
        Node *p = this->pre;
        this->pre = p->pre;
        if(p->pre) { p->pre->next = this; }
        /*delete p; */
        return;
    }

    void deleteNext() {
        if(this->next == nullptr) return;
        Node *p = this->next;
        this->next = p->next;
        if(p->next) { p->next->pre = this;}
        /*delete p;*/
        return;
    }
};

class Queue{
    public:
    Node head, tail;
    int cnt;

    Queue() : cnt(0) {
        head.next = &tail;
        head.pre = nullptr;
        tail.next = nullptr;
        tail.pre = &head;
    }

    void pushBack(int val) {
        tail.insertPre(new Node(val));
        cnt += 1;
        return;
    }

    void pushFront(int val) {
        head.insertNext(new Node(val));
        cnt += 1;
        return;
    }

    int popBack() {
        if(isEmpty()) { return -1; }
        int ret = tail.pre->val;
        tail.deletePre();
        cnt -= 1;
        return ret;
    }

    int popFront() {
        if(isEmpty()) { return -1; }
        int ret = head.next->val;
        head.deleteNext();
        cnt -= 1;
        return ret;
    }

    int frontIndex() {
        return head.next->val;
    }

    int tailIndex() {
        return tail.pre->val;
    }

    bool isEmpty() {
        return head.next == &tail;
    }

    int queueSize() {
        return cnt;
     }

};

class FrontMiddleBackQueue {
public:
    Queue q1, q2;

    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) {
        q1.pushFront(val);
        update();
        return;
    }
    
    void pushMiddle(int val) {
        if(q1.queueSize() > q2.queueSize()) {
            q2.pushFront(q1.tailIndex());
            q1.popBack();
        }
        q1.pushBack(val);
        update();
        return ;
    }
    
    void pushBack(int val) {
        q2.pushBack(val);
        update();
        return;
    }
    
    int popFront() {
        if(isEmpty()) { return -1; }
        int ret = q1.popFront();
        update();
        return ret;
    }
    
    int popMiddle() {
        if (isEmpty()) { return -1; }
        int ret = q1.popBack();
        update();
        return ret;
        
    }
    
    int popBack() {
        if(isEmpty()) return -1;
        int ret;
        if (q2.isEmpty()) {
            ret = q1.popBack();
            } else {
                ret = q2.popBack();
            }
        update();
        return ret;
    }

    bool isEmpty(){
        return q1.queueSize() + q2.queueSize() == 0;
    }

    void update() {
        if(q1.queueSize() < q2.queueSize()) {
            q1.pushBack(q2.frontIndex());
            q2.popFront();
        }
        if(q1.queueSize() == q2.queueSize() + 2) {
            q2.pushFront(q1.tailIndex());
            q1.popBack();
        }
        return;
    }
};
