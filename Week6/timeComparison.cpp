#include <iostream>
#include <chrono> 
#define MAX_SIZE 100

using namespace std;

class StackArray {
    private:
        int top;
        int arr[MAX_SIZE];
    public:
        StackArray() {
            top = -1;
        }
        void push(int val) {
            if(top == MAX_SIZE-1) {
                cout<<"Stack Overflow"<<endl;
                return;
            }
            top++;
            arr[top] = val;
        }
        void pop() {
            if(top == -1) {
                cout<<"Stack Underflow"<<endl;
                return;
            }
            top--;
        }
        int topElement() {
            return arr[top];
        }
        bool isEmpty() {
            if(top == -1)
                return true;
            else
                return false;
        }
        void display() {
            cout<<"Elements in the stack are: ";
            for(int i=0;i<=top;i++) {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};


class Node {
public:
    int data;
    Node* next;
};

class StackList {
    Node* top;
public:
    StackList() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int stackTop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements are: ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    // create a stack object
    StackArray stack1;
    auto start1 = chrono::high_resolution_clock::now(); // start measuring time

    // perform stack operations
    stack1.push(8);
    stack1.push(10);
    stack1.push(5);
    stack1.push(11);
    stack1.push(15);
    stack1.push(23);
    stack1.push(6);
    stack1.push(18);
    stack1.push(20);
    stack1.push(17);
    stack1.display();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.display();
    stack1.push(4);
    stack1.push(30);
    stack1.push(3);
    stack1.push(1);
    stack1.display();

    auto end1 = chrono::high_resolution_clock::now(); // end measuring time
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1); // calculate duration
    cout << "Time taken by the program using array: " << duration1.count() << " microseconds" << endl;

    StackList stack2;
    auto start2 = chrono::high_resolution_clock::now(); // start measuring time

    // perform stack operations
    stack2.push(8);
    stack2.push(10);
    stack2.push(5);
    stack2.push(11);
    stack2.push(15);
    stack2.push(23);
    stack2.push(6);
    stack2.push(18);
    stack2.push(20);
    stack2.push(17);
    stack2.display();
    stack2.pop();
    stack2.pop();
    stack2.pop();
    stack2.pop();
    stack2.pop();
    stack2.display();
    stack2.push(4);
    stack2.push(30);
    stack2.push(3);
    stack2.push(1);
    stack2.display();

    auto end2 = chrono::high_resolution_clock::now(); // end measuring time
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2); // calculate duration
    cout << "Time taken by the program using linked lists: " << duration2.count() << " microseconds" << endl;
    return 0;
}
