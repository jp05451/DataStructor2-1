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

        //finde the removed leaf
        int removedNode;
        if (deleteData == nextNode[0]->data)
        {
            removedNode = 0;
        }
        else // if(deleteData==nextNode[1]->data)
        {
            removedNode = 1;
        }
        // else
        // {
        //     if(deleteData<data)
        //     {
        //         nextNode[0]->removeNode(deleteData);
        //     }
        //     else
        //     {
        //         nextNode[1]->removeNode(deleteData);
        //     }
        // }
        }
    treeNode *findParent(T searchData)
    {
        if (searchData <= data)
        {
            if (nextNode[0] != nullptr)
            {
                if (nextNode[0]->data = searchData)
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
                if (nextNode[1]->data = searchData)
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
    treeNode *findLeftLeaf()
    {
        if (nextNode[1]->nextNode[1] == nullptr)
        {
            return nextNode[1];
        }
        else
        {
            return findLeftLeaf();
        }
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
            treeRoot->removeNode(deleteData);
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
        treeRoot->removeNode(deleteData);
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
    T nodeList;
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
    T.print();
    //T.begin()
}