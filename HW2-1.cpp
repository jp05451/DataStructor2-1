#include <iostream>

using namespace std;

template <typename T>
class treeNode
{
public:
    treeNode *parentNode = nullptr;
    T data;
    treeNode *nextNode[2] = {nullptr};

    treeNode(T inputData) { data = inputData; }
    treeNode(treeNode *parent, T input)
    {
        parentNode = parent;
        data = input;
    }
    // ~treeNode()
    // {
    //     //destroyNode();
    // }

    void printNode()
    {
        cout << data;
        cout << "(";
        if (nextNode[0] != nullptr)
        {
            nextNode[0]->printNode();
        }
        cout << ")(";
        if (nextNode[1] != nullptr)
        {
            nextNode[1]->printNode();
        }
        cout << ")";
    }

    void add(T input)
    {
        if (input <= data)
        {
            if (nextNode[0] == nullptr)
            {
                treeNode *newNode = new treeNode(this, input);
                nextNode[0] = newNode;
            }
            else
            {
                nextNode[0]->add(input);
            }
            return;
        }
        if (input > data)
        {
            if (nextNode[1] == nullptr)
            {
                treeNode *newNode = new treeNode(this, input);
                nextNode[1] = newNode;
                return;
            }
            else
            {
                nextNode[1]->add(input);
            }
        }
    }

    void removeNode(T deleteData)
    {
        int remove;
        treeNode *deleteNode;

        //find the deleteNode
        if (deleteData <= data)
        {
            remove = 0;
            deleteNode = nextNode[0];
        }
        else
        {
            remove = 1;
            deleteNode = nextNode[1];
        }

        //delete Node
        if (deleteNode->nextNode[0] == nullptr && deleteNode->nextNode[1] == nullptr)
        //have no child node
        {
            delete deleteNode;
            nextNode[remove] = nullptr;
            return;
        }
        else if (deleteNode->nextNode[0] != nullptr && deleteNode->nextNode[1] != nullptr)
        //have two child node
        {
            if (deleteNode->nextNode[0]->nextNode[1] == nullptr)
            //don't have left child's right child
            {
                deleteNode->data = deleteNode->nextNode[0]->data;
                deleteNode->removeNode(deleteNode->data);
            }
            else
            //have left child's right child
            {
                treeNode *finalNode = deleteNode->nextNode[0]->findRightLeaf();
                deleteNode->data = finalNode->nextNode[1]->data;
                finalNode->removeNode(finalNode->nextNode[1]->data);
            }
            return;
        }
        else
        // only have one child
        {
            if (deleteNode->nextNode[0] != nullptr)
            //have left child
            {
                //deletNode->data = deletNode->nextNode[0]->data;
                nextNode[remove] = deleteNode->nextNode[0];
                // deleteNode->removeNode(deleteNode->nextNode[0]->data);
            }
            else
            //have right child
            {
                nextNode[remove] = deleteNode->nextNode[1];
            }
            delete deleteNode;
        }
    }

    treeNode *findParent(T searchData)
    {
        if (searchData <= data)
        {
            if (nextNode[0] != nullptr)
            {
                if (nextNode[0]->data == searchData)
                {
                    return this;
                }
                else
                {
                    return nextNode[0]->findParent(searchData);
                }
            }
            else
            {
                return nullptr;
            }
        }
        else
        {
            if (nextNode[1] != nullptr)
            {
                if (nextNode[1]->data == searchData)
                {
                    return this;
                }
                else
                {
                    return nextNode[1]->findParent(searchData);
                }
            }
            else
            {
                return nullptr;
            }
        }
    }
    treeNode *findRightLeaf()
    {
        if (nextNode[1]->nextNode[1] == nullptr)
        {
            return this;
        }
        return nextNode[1]->findRightLeaf();
    }

    void destroyNode()
    {
        for (int i = 0; i < 2; i++)
        {
            if (nextNode[i] != nullptr)
            {
                if (nextNode[i]->nextNode[0] != nullptr || nextNode[i]->nextNode[1] != nullptr)
                {
                    nextNode[i]->destroyNode();
                }
                if (nextNode[i]->nextNode[0] == nullptr && nextNode[i]->nextNode[1] == nullptr)
                //last Node of the tree
                {
                    delete nextNode[i];
                    nextNode[i] = nullptr;
                }
            }
        }
    }
};

template <typename T>
class tree
{
    typedef treeNode<T> NODE;

public:
    void Insert(T inputData)
    {
        if (treeRoot == nullptr)
        {
            NODE *newNode = new NODE(treeRoot, inputData);
            treeRoot = newNode;
        }
        else
        {
            treeRoot->add(inputData);
        }
    }

    void begin(char command)
    {
        switch (command)
        {
        case 'I':
            T insertData;
            cin >> insertData;
            treeRoot->add(insertData);
            break;
        case 'D':
            T deleteData;
            cin >> deleteData;
            //treeRoot->removeNode(deleteData);
            remove(deleteData);
            break;
        case 'P':
            print();
            break;
        }
    }

    void print()
    {
        if (treeRoot != nullptr)
        {
            treeRoot->printNode();
        }
        cout << endl;
    }

    void remove(T deleteData)
    {
        if (treeRoot == nullptr)
            return;
        NODE *targetNode = treeRoot->findParent(deleteData);
        targetNode->removeNode(deleteData);
    }
    ~tree()
    {
        if (treeRoot == nullptr)
            return;

        treeRoot->destroyNode();
        delete treeRoot;
        treeRoot = nullptr;
    }

private:
    NODE *treeRoot = nullptr;
    T nodeList = 0;
};

int main()
{
    int times;
    int initialValue;
    tree<int> T;
    cin >> times;
    for (int i = 0; i < times; i++)
    {
        cin >> initialValue;
        T.Insert(initialValue);
    }
    //T.print();
    char command;
    while (cin >> command)
    {
        T.begin(command);
    }
    //T.begin()
}