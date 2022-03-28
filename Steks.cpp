#include <iostream>
using namespace std;

#define MAX 50 // max size for stack
//
//class Stack
//{
//    int top;
//    int myStack[MAX];
//
//public:
//    Stack(){};
//    bool push(int item);
//    bool pop(int& data);
//    bool isEmpty();
//    bool isFull();
//};
//
//Stack::Stack() {
//    top = -1;
//    for (int i = 0; i < MAX; i++) {
//        myStack[i] = 0;
//    }
//}
//bool Stack::push(int item) {
//    if (isFull()) return false;
//    else {
//        myStack[top + 1] = item;
//        top++;
//        return true;
//    }
//}
//
//
//// Pops element out of the stack
//bool Stack::pop(int& item)
//{
//    if (isFull()) return false;
//    else {
//        item = myStack[top];
//        top--;
//        return true;
//    }
//}
//
//// Check if stack is empty
//bool Stack::isEmpty()
//{
//    if (top < 0)return true;
//    else return false;
//}
//
//// Check if stack is full
//bool Stack::isFull()
//{
//    if (top >= MAX - 1)return true;
//    else return false;
//}
//
//// main program to demonstrate stack functions
//int main()
//{
//    class Stack stack;
//
//    cout << "Pushing in the stack:" << endl;
//    for (int i = 0; i < 10; i += 2)
//    {
//        if (stack.push(i))
//        {
//            cout << "\tAdded " << i << endl;
//        }
//        else
//        {
//            cout << "\tStack Overflow!!!" << endl;
//        }
//    }
//
//    int data = 0;
//
//    cout << "Poping from the stack: " << endl;
//    while (!stack.isEmpty())
//    {
//        if (stack.pop(data))
//        {
//            cout << "\tGot " << data << endl;
//        }
//        else
//        {
//            cout << "\tStack Underflow!!" << endl;
//        }
//    }
//
//    return 0;
//}

class Stack
{
    struct StackNode
    {
        int data;
        StackNode* next;      
    };

    StackNode* top;
    

public:
    Stack();
    bool push(int item);
    bool pop(int& data);
    bool isEmpty();
    bool isFull();
};
Stack::Stack() {
    top = NULL;
}
// Push new element on to the stack
bool Stack::push(int item)
{
    StackNode *temp = new StackNode();
    temp->data = item;
    temp -> next = top;
    top = temp;
    return true;
}

// Pops element out of the stack
bool Stack::pop(int& item)
{
    if(isEmpty())return false;
    StackNode* temp = top;
    item = top->data;
    top = top->next;
    delete temp;
    return true;

}

// Check if stack is empty
bool Stack::isEmpty()
{
    return top == NULL;
}

// Check if stack is full
bool Stack::isFull()
{
    return false;
}

// main program to demonstrate stack functions
int main()
{
    class Stack stack;

    cout << "Pushing in the stack:" << endl;
    for (int i = 0; i < 10; i += 2)
    {
        if (stack.push(i))
        {
            cout << "\tAdded " << i << endl;
        }
        else
        {
            cout << "\tStack Overflow!!!" << endl;
        }
    }

    int data = 0;

    cout << "Poping from the stack: " << endl;
    while (!stack.isEmpty())
    {
        if (stack.pop(data))
        {
            cout << "\tGot " << data << endl;
        }
        else
        {
            cout << "\tStack Underflow!!" << endl;
        }
    }

    return 0;
}