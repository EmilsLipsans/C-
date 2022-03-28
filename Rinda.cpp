#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int newdata=0)
    {
        data = newdata;
        next = NULL;
    }
};

class queue
{

private:
    node* front, * rear;

public:
    queue()
    {
        front = NULL;
        rear = NULL;
    }

    bool isempty()
    {
        return(front==NULL);
    }

    bool enqueue(int value)
    {
        if (rear != NULL) {
            node* newnode = new node(value);
            rear->next = newnode;
            rear = rear->next;
        }
        else {
            node* newnode = new node(value);
            rear = front = newnode;
        }
        return true;
    }
    bool dequeue(int& data) //nepilns
    {
        if (front != NULL) {
            data = front->data;
            front = front->next;
            return true;
        }
        else return false;
    }

    void displayqueue()
    {
        node* p = front;
        if (p == NULL) cout << "empty" << endl;
        cout << "(front)";
        while (p!= NULL)
        {
            cout << p->data << " - ";
            p = p->next;
        }
        cout << "(rear)" << endl;
    }
    
};

int main()
{
    queue myq;
    int tmp;

    cout << "queue is empty: " << (myq.isempty() ? "true" : "false") << endl;

    // try to dequeue from empty
    if (myq.dequeue(tmp))
    {
        cout << "got " << tmp << "from empty queue" << endl;
    }
    else
    {
        cout << "queue is empty" << endl;
    }

    // add 10 elements
    for (int i = 0; i < 10; i++)
    {
        if (myq.enqueue(i))
        {
            cout << "added " << i << "to queue" << endl;
        }
        else
        {
            cout << "failed to add " << i << "to queue" << endl;
        }
    }

    myq.displayqueue();

    cout << "queue is empty: " << (myq.isempty() ? "true" : "false") << endl;

    // dequeue until empty
    while (myq.dequeue(tmp))
    {
        cout << "removed" << tmp << "from queue" << endl;
    }

    myq.displayqueue();

    cout << "queue should be empty: " << (myq.isempty() ? "true" : "false") << endl;

    return 0;
}



