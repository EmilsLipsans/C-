#include <iostream>

using namespace std;

// A double linked list node
struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
};

bool checkList(Node* head)
{
    if (head == NULL)
    {
        return true;
    }

    if (head->prev != NULL)
    {
        return false;
    }

    while (head->next != NULL)
    {
        if (head->next->prev != head || head->next == head)
        {
            return false;
        }
        head = head->next;
    }
    return true;
}

// display linked list contents
void displayList(struct Node* head)
{
    if (!checkList(head))
    {
        cout << "List is not correct!" << endl;
        return;
    }

    cout << "List is correct: null ";
    // traverse the list to display each node
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "null" << endl;
}

// display linked list contents
void displayList(Node* head, Node* current)
{
    if (!checkList(head))
    {
        cout << "List is not correct!" << endl;
        return;
    }

    cout << "List is correct: null ";
    // traverse the list to display each node
    while (head != NULL)
    {
        if (head == current)
        {
            cout << "[" << head->data << "] ";
        }
        else
        {
            cout << head->data << " ";
        }
        head = head->next;
    }
    cout << "null" << endl;
}
// Add element to the end of list
void append(Node** head, Node* newNode)
{
    struct Node* last = *head;

    // new node is the last node , so set next of new node to null
    newNode->next = NULL;

    // check if list is empty, if yes make new node the head of list
    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    // otherwise traverse the list to go to last node
    while (last->next != NULL)
    {
        last = last->next;
    }

    // set next of last to new node
    last->next = newNode;

    // set last to prev of new node
    newNode->prev = last;

    return;
}

// Adds the node to the list as first element
void push(Node** head, Node* newNode)
{
    // new node is head and previous is null, since we are adding at the front
    newNode->next = (*head);
    newNode->prev = NULL;

    // previous of head is new node
    if ((*head) != NULL)
    {
        (*head)->prev = newNode;
    }

    // head points to new node
    (*head) = newNode;
}

// Adds new node after prev
void InsertAfter(Node* prev, Node* newNode)
{
    // Set next of newnode to next of prev node
    newNode->next = prev->next;

    // Set next of prev node to new node
    prev->next = newNode;

    // Now set prev of newnode to prev node
    newNode->prev = prev;

    // Set prev of new node's next to new node
    if (newNode->next != NULL)
    {
        newNode->next->prev = newNode;
    }
}

// Count the elements of linked list
int lenght(Node* head)
{
    int count = 0;

    while (head != NULL)
    {
        head = head->next;
        count++;
    }

    return count;
}

// Reverse the doubly linked list
void reverseList(Node** head)
{
    Node* left = *head, * right = *head;
    Node tmp;

    // Set right to Tail
    while (right->next != NULL)
    {
        right = right->next;
    }

    {
        /*
        L       R
        1 2 3 4 5
          L   R
        5 2 3 4 1
            X
        5 4 3 2 1

        L     R
        1 2 3 4

          L R
        4 2 3 1
        */
    }
    // Swap left and right data by moving them towards each other till they meet or cross
    while (left != right && left->prev != right)
    {
        // Swap left and right pointer data
        tmp.data = left->data;
        left->data = right->data;
        right->data = tmp.data;

        // Advance left pointer
        left = left->next;

        // Advance right pointer
        right = right->prev;
    }
}

void deleteAfter(Node* node)
{
    if (node == NULL || node->next == NULL)
    {
        return;
    }

    if (node->next->next == NULL)
    {
        delete node->next;
        node->next = NULL;
    }
    else
    {
        Node* tmp = node->next;
        tmp->next->prev = node;
        node->next = tmp->next;
        delete tmp;
    }
}

class DoubleLinkedList
{
private:
    Node* head;
    Node* current;

public:
    DoubleLinkedList();

    void goToHead()
    {
        current = head;
    }

    void goToTail()
    {
        while (moveForward())
            ;
    }

    bool moveForward()
    {
        if (current && current->next)
        {
            current = current->next;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool moveBackward()
    {
        if (current && current->prev)
        {
            current = current->prev;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool getCurrentValue(int& data)
    {
        if (current)
        {
            data = current->data;
            return true;
        }
        else
        {
            return false;
        }
    }

    void addAfter(int value)
    {
        Node* tmp = new Node();
        tmp->data = value;
        if (!head)
        {
            tmp->next = NULL;
            tmp->prev = NULL;
            head = current = tmp;
            return;
        }
        tmp->next = current->next;
        tmp->prev = current;
        if (tmp->next)
        {
            tmp->next->prev = tmp;
        }
        current->next = tmp;
    }
    void addBefore(int value)
    {
        Node* tmp = new Node();
        tmp->data = value;
        if (!head)
        {
            tmp->next = NULL;
            tmp->prev = NULL;
            head = current = tmp;
            return;
        }
        tmp->next = current;
        tmp->prev = current->prev;
        // check if current is head
        if (tmp->prev)
        {
            tmp->prev->next = tmp;
        }
        else
        {  

            // We are inserting new head!
            head = tmp;
        }
        current->prev = tmp;
    }
    bool deleteCurrentValue(int& data) {
        if(current->next == NULL)

        if (current) {
            data = current->data;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            current = current->next;
            return true;
        }
        else {
            return false;
        }
    }

    void print()
    {
        displayList(head, current);
    }
};

DoubleLinkedList::DoubleLinkedList()
{
    head = new Node();
    head->prev = NULL;
    head->data = 1;

    head->next = new Node();
    head->next->prev = head;
    head->next->data = 2;

    head->next->next = new Node();
    head->next->next->prev = head->next;
    head->next->next->data = 3;
    head->next->next->next = NULL;

    current = head;
    // current = NULL;
}

int main()
{
    DoubleLinkedList dll = DoubleLinkedList();

    dll.print();
    dll.goToTail();
    dll.print();
    dll.goToHead();
    dll.print();
    dll.moveForward();
    dll.print();
    int value = 0;

    if (dll.getCurrentValue(value))
    {
        cout << "I'm at " << value << endl;
    }
    else
    {
        cout << "I'm lost!" << endl;
    }

    return 0;

    Node* head = NULL;

    head = new Node();
    head->prev = NULL;
    head->data = 1;
    head->next = NULL;

    head->next = new Node();
    head->next->prev = head;
    head->next->data = 2;
    head->next->next = NULL;

    head->next->next = new Node();
    head->next->next->prev = head->next;
    head->next->next->data = 3;
    head->next->next->next = NULL;

    displayList(head);

    Node* tmp = new Node();
    tmp->data = 4;
    append(&head, tmp);
    displayList(head);

    tmp = new Node();
    tmp->data = 0;
    push(&head, tmp);
    displayList(head);

    tmp = new Node();
    tmp->data = 99;
    InsertAfter(head->next->next, tmp);
    displayList(head);

    cout << "Reversing" << endl;
    reverseList(&head);
    displayList(head);

    tmp = new Node();
    tmp->data = -99;
    push(&head, tmp);
    displayList(head);

    cout << "Reversing" << endl;
    reverseList(&head);
    displayList(head);
    cout << "Linked list has " << lenght(head) << " elements" << endl;

    deleteAfter(head->next->next);
    displayList(head);
}