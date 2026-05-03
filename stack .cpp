#include<iostream>
using namespace std;

// Node class 
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Stack class - LIFO (Last In First Out) 
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // add new data to the top
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    // remove data at the top
    void pop() {
        if(top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // check Top element without remove
    int peek() {
        if(top == NULL) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    // print complete stack
    void display() {
        Node* temp = top;
        if(temp == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    // Data insert 
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Initial Stack: ";
    s.display();

    // Peek check 
    cout << "Current Top Element: " << s.peek() << endl;

    // Data remove 
    s.pop();
    cout << "After Pop, New Top: " << s.peek() << endl;
    
    cout << "Final Stack: ";
    s.display();

    return 0;
}
