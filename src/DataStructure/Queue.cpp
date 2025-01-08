#include <vector>

using namespace std;

class Queue{
    public:
        Queue(int n = 10) : arr(n) {}
        void push(int x) {
            if (isEmpty()) {
                cout << "queue is full" << endl;
                return ;
            }
            
            arr[tail] = x;
            tail += 1;
            return ;
        }

        void pop() {
            if (isEmpty()) {
                return; 
            }
            head += 1;
        }

        bool isEmpty() {
            return head == tail;
        }

        int searchHead() {
            return arr[head];
        }

        int countElement() {
            return tail - head;
        }

        void showElement() {
            cout << "Queue: ";
            for (int i = head; i < tail; i ++){
                cout << arr[i] <<" ";
            }
            cout << endl;
            return ;
        }
    private:
        int head, tail;
        vector<int> arr;

};

int main(){
    string op;
    int val;
    Queue que(5);
    while (cin >> op){
        if(op == "insert"){
            cin >> val;
            que.push(value);
        } else if (op == "front") {
            cout << "front element :" << que.searchHead() << endl;
        } else if (op == "pop") {
            que.pop();
        } else if (op == "size") {
            cout << "Queue size: " << que.countElement() << endl;
        }
        que.showElement();
    }
    return 0;
    
}