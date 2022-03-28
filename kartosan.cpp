//Solves the task described in http://olimps.lio.lv/uzdevumi.php?show=471 using binary tree.
#include <iostream>
#include <fstream>
#include <string>
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
            if (data >= tmp->data)
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
    void inOrderPrint()
    {
        ofstream MyWriteFile("kartosan.rez"); 
        inOrderPrint(root, MyWriteFile);
        MyWriteFile.close();
    }
    void inOrderPrint(Node* pt, ofstream& file)
    {
        if (!pt)return;
        inOrderPrint(pt->left, file);
        file << pt->data << endl;
        inOrderPrint(pt->right, file);
    }
};
int main()
{
    string myText;
    BinaryTree bt = BinaryTree();
    ifstream MyReadFile("kartosan.dat");
    int x = 0;
    int N;
    while (getline(MyReadFile, myText))
    { 
        if (x == 0)
        {
            N = atoi(myText.c_str());
            x++;
        }
        else if(x <= N)
        {
            bt.insert(atoi(myText.c_str()));
            x++;
        }
        else if (N == x) break;    
    }
    bt.inOrderPrint();
    MyReadFile.close();
}

