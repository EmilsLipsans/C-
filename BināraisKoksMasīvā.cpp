#include <iostream>

using namespace std;

#define TREE_SIZE 12
#define FREE_SPACE -1

class BinaryTree
{
    int tree[TREE_SIZE];

public:
    BinaryTree() 
    {
        for (int i = 0; i < TREE_SIZE; i++) {
            tree[i] = FREE_SPACE;
        }
    }

    // Insert data to build a binary search tree
    bool insert(int data)
    {
        int i = 0;
        while (i < TREE_SIZE && tree[i] != FREE_SPACE)
        {
            if (data < tree[i])
            {
                i = 2 * i + 1;
            }
            else
            {
                i = 2 * i + 2;
            }                    
        }
        if (i < TREE_SIZE)
        {
            tree[i] = data;
            return true;
        }
        else return false;
    }

    // Check if the binary tree is complete
    bool isComplete()
    {
        if (tree[0] == -1)return false;
        for (int i = 1; i + 1 < TREE_SIZE; i += 2)
        {
            if ((tree[i] != -1 && tree[i + 1] == -1) || (tree[i] == -1 && tree[i + 1] != -1)) return false;
        }
        return true;
    }

    // Check if the binary tree is empty
    bool isEmpty()
    {
        if (tree[0] == FREE_SPACE)return true;
        else return false;
    }

    // The order of inOrder traversal is left->root->right
    void inOrderPrint()
    {
        inOrderPrint(0);
        cout << endl;
    }
    void inOrderPrint(int index)
    {
        if (index >= TREE_SIZE)return;
        inOrderPrint(index * 2 + 1);
        if (tree[index] != FREE_SPACE)
            cout << " " << tree[index];
        inOrderPrint(index * 2 + 2);
    }

    // The order of preorder traversal is root->left->right
    void preOrderPrint()
    {
    }

    // The order of traversal is left->right->root
    void postOrderPrint()
    {
    }

    // Print the tree array
    void easyPrint()
    {
        int SONL = 1;
        for (int i = 0; i < TREE_SIZE; i++)
        {
            if (i == SONL)
            {
                cout << endl;
                SONL = (SONL * 2) + 1;
            }
            cout << tree[i] << " ";
        }
    }
};

int main()
{
    BinaryTree bt = BinaryTree();

    /* initialize random seed: */
    srand(time(NULL));

    cout << "Binary tree is complete: " << (bt.isComplete() ? "True" : "False") << endl;
    bt.insert(20);
    cout << "Binary tree is complete: " << (bt.isComplete() ? "True" : "False") << endl;
    bt.insert(10);
    cout << "Binary tree is complete: " << (bt.isComplete() ? "True" : "False") << endl;
    bt.insert(40);
    cout << "Binary tree is complete: " << (bt.isComplete() ? "True" : "False") << endl;
    bt.insert(5);
    cout << "Binary tree is complete: " << (bt.isComplete() ? "True" : "False") << endl;
    bt.insert(15);
    cout << "Binary tree is complete: " << (bt.isComplete() ? "True" : "False") << endl;
    bt.insert(17);
    cout << "Binary tree is complete: " << (bt.isComplete() ? "True" : "False") << endl;
    bt.insert(16);
    cout << "Binary tree is complete: " << (bt.isComplete() ? "True" : "False") << endl;
    bt.insert(35);
    cout << "Binary tree is complete: " << (bt.isComplete() ? "True" : "False") << endl;
    bt.insert(45);
    cout << "Binary tree is complete: " << (bt.isComplete() ? "True" : "False") << endl;
    bt.inOrderPrint();

    // Add from 5 to 15 elements
    // Change to constant for easier debugging if necessary
    for (int i = 0, r = rand() % 50; i < rand() % 10 + 5; i++, r = rand() % 50)
    {
        bt.insert(r);
        cout << "Inserted " << r << ": binary tree is complete: " << (bt.isComplete() ? "True" : "False") << endl;
        bt.inOrderPrint();
    }

    bt.inOrderPrint();
    bt.preOrderPrint();
    bt.postOrderPrint();
    bt.easyPrint();

    return 0;
}