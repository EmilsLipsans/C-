#include <iostream>

using namespace std;

class BinaryTree
{
    class Node
    {
        public:
            int data;
            Node* left;
            Node* right;
            Node(int newData)
            {
                data = newData;
                left = right = NULL;
            }
    };

    Node* root;

public:
    BinaryTree()
    {
        root = NULL;
    }

    // Insert data to build a complete binary tree
    // The lowest level that is filled from left to right
    void insert(int data)
    {
        if (!root)
        {
            root = new Node(data);
            return;

        }

        Node* tmp = root;
        
        while (tmp != NULL)
        {
            if (data >=tmp->data)
            {
                if (tmp->right)
                {
                    tmp = tmp->right;
                }
                else
                {
                    tmp->right = new Node(data);
                    return;
                }

            }
            else {
                if (tmp->left)
                {
                    tmp = tmp->left;
                }
                else
                {
                    tmp->left = new Node(data);
                    return;
                }
            }

        }

            
    }

    // Check if the binary tree is complete
    bool isComplete()
    {
        return isSubTreeComplete(root);
    }
    bool isSubTreeComplete(Node* node)
    {
        if (node == NULL || (node->left == NULL && node->right == NULL)) return true;
        if (node->left && node->right)
            return isSubTreeComplete(node->left) && isSubTreeComplete(node->right);
        return false;

    }
    // The order of inOrder traversal is left->root->right
    void inOrderPrint()
    {
        cout << "In order traversal: ";
        inOrderPrint(root);
        cout << endl;
    }
    void inOrderPrint(Node* pt)
    {
        if (!pt)return;
        inOrderPrint(pt->left);
        cout << pt->data << " ";
        inOrderPrint(pt->right);

    }

    // The order of preorder traversal is root->left->right
    void preOrderPrint()
    {
        cout << "Pre order traversal: ";
        preOrderPrint(root);
        cout << endl;
    }
    void preOrderPrint(Node* pt)
    {
        if (!pt)return;
        cout << pt->data << " ";
        preOrderPrint(pt->left);
        preOrderPrint(pt->right);
    }

    // The order of traversal is left->right->root
    void postOrderPrint()
    {
        cout << "Post order traversal: ";
        postOrderPrint(root);
        cout << endl;
    }
    void postOrderPrint(Node* pt)
    {
        if (!pt)return;
        postOrderPrint(pt->left);
        postOrderPrint(pt->right);
        cout << pt->data << " ";
    }
};
int main()
{
    BinaryTree bt = BinaryTree();

    /* initialize random seed: */
    srand(time(NULL));

   /* cout << "Binary tree is complete: " << (bt.isComplete() ? "True" : "False") << endl;*/

    // Add from 5 to 15 elements
    // Change to constant for easier debugging if necessary
    /*for (int i = 0; i < rand() % 10 + 5; i++)
    {
        bt.insert(i);
        cout << "Inserted " << i << ": binary tree is complete:" << (bt.isComplete() ? "True" : "False") << endl;

    }*/
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
    cout << "Binary tree is complete: " << (bt.isComplete() ? "True" : "False") << endl; bt.insert(35);
    cout << "Binary tree is complete: " << (bt.isComplete() ? "True" : "False") << endl;
    bt.insert(45);
    cout << "Binary tree is complete: " << (bt.isComplete() ? "True" : "False") << endl;

    bt.inOrderPrint();
    bt.preOrderPrint();
    bt.postOrderPrint();

    return 0;
}