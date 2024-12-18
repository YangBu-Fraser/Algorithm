#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

/* Linklist version 1
struct Node{
    Node(int data) : data(data), next(NULL) {}
    int data;
    Node *next;
};

int main(){
    Node *head = NULL;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    Node *p = head;
    while(p != NULL){
        printf("%d->", p -> data);
        p = p->next;
    }
    printf("\n");
    
    return 0;
};
*/

int data[10];
int next[10];

void add(int ind, int p, int val){
    next[ind] = p;
    data[p] = val;
    return ;
}

Node *reverse(Node *p, int n) {
    if (n = 1) return head;
    Node *tail = head -> next, *p = reverse(head -> next, n - 1);
    head -> next = tail -> next;
    tail -> next = head;
    return p;
}

int main(){
    int head = 3;
    int data[3] = 0;

    add(3,5,1);
    add(5,2,2);
    add(2,7,3);
    add(7,9,100);
    
    int p = head;
    while (p!=0)
    {
        printf("%d->", data[p]);
        p = next[p];
    }
    printf("\n");
    return 0;
}