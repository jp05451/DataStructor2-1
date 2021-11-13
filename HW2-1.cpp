#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdio.h>

#define MAX 100000
using namespace std;

//BSTree
//template <typename T>
typedef int T;
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

    void printNode()
    {
        // cout << data;
        // cout << "(";
        printf("%d(", data);
        if (nextNode[0] != nullptr)
        {
            nextNode[0]->printNode();
        }
        //cout << ")(";
        printf(")(");
        if (nextNode[1] != nullptr)
        {
            nextNode[1]->printNode();
        }
        //cout << ")";
        printf(")");
    }

    // void add(T input)
    // {
    //     if (input <= data)
    //     {
    //         if (nextNode[0] == nullptr)
    //         {
    //             treeNode *newNode = new treeNode(this, input);
    //             nextNode[0] = newNode;
    //         }
    //         else
    //         {
    //             nextNode[0]->add(input);
    //         }
    //         return;
    //     }
    //     if (input > data)
    //     {
    //         if (nextNode[1] == nullptr)
    //         {
    //             treeNode *newNode = new treeNode(this, input);
    //             nextNode[1] = newNode;
    //             return;
    //         }
    //         else
    //         {
    //             nextNode[1]->add(input);
    //         }
    //     }
    // }

    void add(T inputData)
    {
        treeNode *preNode = this;
        treeNode *lastNode = this;
        //while (lastNode != nullptr)
        while (lastNode != nullptr)
        {
            if (inputData <= preNode->data)
            {
                lastNode = preNode->nextNode[0];
            }
            else
            {
                lastNode = preNode->nextNode[1];
            }
            if (lastNode == nullptr)
            {
                break;
            }
            else
            {
                preNode = lastNode;
            }
        }
        if (inputData <= preNode->data)
        {
            preNode->nextNode[0] = new treeNode(preNode, inputData);
        }
        else
        {
            preNode->nextNode[1] = new treeNode(preNode, inputData);
        }
    }

    // void removeNode(T deleteData)
    // {
    //     int remove;
    //     treeNode *deleteNode;

    //     //find the deleteNode
    //     if (deleteData <= data)
    //     {
    //         remove = 0;
    //         deleteNode = nextNode[0];
    //     }
    //     else
    //     {
    //         remove = 1;
    //         deleteNode = nextNode[1];
    //     }

    //     //delete Node
    //     if (deleteNode->nextNode[0] == nullptr && deleteNode->nextNode[1] == nullptr)
    //     //have no child node
    //     {
    //         delete deleteNode;
    //         nextNode[remove] = nullptr;
    //         return;
    //     }
    //     else if (deleteNode->nextNode[0] != nullptr && deleteNode->nextNode[1] != nullptr)
    //     //have two child node
    //     {
    //         if (deleteNode->nextNode[0]->nextNode[1] == nullptr)
    //         //don't have left child's right child
    //         {
    //             deleteNode->data = deleteNode->nextNode[0]->data;
    //             deleteNode->removeNode(deleteNode->data);
    //         }
    //         else
    //         //have left child's right child
    //         {
    //             treeNode *finalNode = deleteNode->nextNode[0]->findRightLeaf();
    //             deleteNode->data = finalNode->nextNode[1]->data;
    //             finalNode->removeNode(finalNode->nextNode[1]->data);
    //         }
    //         return;
    //     }
    //     else
    //     // only have one child
    //     {
    //         if (deleteNode->nextNode[0] != nullptr)
    //         //have left child
    //         {
    //             //deletNode->data = deletNode->nextNode[0]->data;
    //             nextNode[remove] = deleteNode->nextNode[0];
    //             // deleteNode->removeNode(deleteNode->nextNode[0]->data);
    //         }
    //         else
    //         //have right child
    //         {
    //             nextNode[remove] = deleteNode->nextNode[1];
    //         }
    //         delete deleteNode;
    //     }
    // }

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

    // treeNode *findParent(T searchData)
    // {
    //     if (searchData <= data)
    //     {
    //         if (nextNode[0] != nullptr)
    //         {
    //             if (nextNode[0]->data == searchData)
    //             {
    //                 return this;
    //             }
    //             else
    //             {
    //                 return nextNode[0]->findParent(searchData);
    //             }
    //         }
    //         else
    //         {
    //             return nullptr;
    //         }
    //     }
    //     else
    //     {
    //         if (nextNode[1] != nullptr)
    //         {
    //             if (nextNode[1]->data == searchData)
    //             {
    //                 return this;
    //             }
    //             else
    //             {
    //                 return nextNode[1]->findParent(searchData);
    //             }
    //         }
    //         else
    //         {
    //             return nullptr;
    //         }
    //     }
    // }

    treeNode *findParent(T searchData)
    {
        treeNode *tempNode = this;
        while (tempNode != nullptr)
        {
            if (searchData <= tempNode->data)
            {
                if (tempNode->nextNode[0] != nullptr)
                {
                    if (tempNode->nextNode[0]->data == searchData)
                    {
                        return tempNode;
                    }
                    else
                    {
                        tempNode = tempNode->nextNode[0];
                    }
                }
                else
                {
                    return nullptr;
                }
            }
            else
            {
                if (tempNode->nextNode[1] != nullptr)
                {
                    if (tempNode->nextNode[1]->data == searchData)
                    {
                        return tempNode;
                    }
                    else
                    {
                        tempNode = tempNode->nextNode[1];
                    }
                }
                else
                {
                    return nullptr;
                }
            }
        }
    }

    // treeNode *findRightLeaf()
    // {
    //     if (nextNode[1]->nextNode[1] == nullptr)
    //     {
    //         return this;
    //     }
    //     return nextNode[1]->findRightLeaf();
    // }

    treeNode *findRightLeaf()
    {
        treeNode *tempNode = this;
        while (tempNode->nextNode[1]->nextNode[1] != nullptr)
        {
            tempNode = tempNode->nextNode[1];
        }
        return tempNode;
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

//template <typename T>
typedef int I;
class tree
{
    typedef treeNode NODE;

public:
    void Insert(I inputData)
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
        //nodeList.push(inputData);
        nodeList[cursor] = inputData;
        sorting = 1;
        maximent += inputData;
        cursor++;
    }

    void print()
    {
        if (treeRoot != nullptr)
        {
            treeRoot->printNode();
        }
        cout << endl;
    }

    void remove(I deleteData)
    {
        if (treeRoot == nullptr)
            return;
        NODE *targetNode = treeRoot->findParent(deleteData);
        if (targetNode==nullptr)
            return;
        targetNode->removeNode(deleteData);
        int *p;
        p = find(nodeList, nodeList + MAX, deleteData);
        if (p != nodeList + MAX)
        {
            cursor--;
            maximent -= deleteData;
            *p = 0;
            swap(*p, nodeList[cursor]);
            sorting = 0;
        }
        //nodeList.pop(deleteData);
    }

    int leastNode(int input)
    {

        //sort thd list
        //power down
        if (sorting)
        {
            // for (int i = 1; i < cursor; i++)
            // {
            //     for (int j = 0; j < i; j++)
            //     {
            //         if (nodeList[i] > nodeList[j])
            //         {
            //             //swap(nodeList[i], nodeList[j]);
            //             I temp;
            //             temp = nodeList[i];
            //             nodeList[i] = nodeList[j];
            //             nodeList[j] = temp;
            //         }
            //     }
            // }
            sort(nodeList, nodeList + cursor,greater<int>());
            sorting = 0;
            sortWay = 1; //power down
        }

        //revert
        if (!sortWay)
        {
            for (int i = 0; i < cursor / 2; i++)
            {
                int temp;
                temp = nodeList[i];
                nodeList[i] = nodeList[cursor - 1 - i];
                nodeList[cursor - 1 - i] = temp;
            }
            sortWay = 1;
        }

        //input too big
        if (input > maximent)
        {
            return 0;
        }

        //special case
        if (input <= nodeList[cursor - 1])
        {
            if (input < nodeList[cursor - 1])
                return cursor - 1;
            else
                return cursor - 1;
        }

        int temp = maximent;
        int count = 0;

        for (count = 0; count < cursor; count++)
        {
            if (temp - nodeList[count] <= input)
            {
                count++;
                break;
            }
            temp -= nodeList[count];
        }
        return count;
    }

    int maxNode(int input)
    {

        //sort list
        //power up
        if (sorting)
        {
        //     for (int i = 1; i < cursor; i++)
        //     {
        //         for (int j = 0; j < i; j++)
        //         {
        //             if (nodeList[i] < nodeList[j])
        //             {
        //                 //swap(nodeList[i], nodeList[j]);
        //                 I temp;
        //                 temp = nodeList[i];
        //                 nodeList[i] = nodeList[j];
        //                 nodeList[j] = temp;
        //             }
        //         }
        //     }
        sort(nodeList, nodeList + cursor);
        sorting = 0;
        sortWay = 0; //power up
        }

        //revert
        if (sortWay)
        {
            for (int i = 0; i < cursor / 2; i++)
            {
                int temp;
                temp = nodeList[i];
                nodeList[i] = nodeList[cursor - 1 - i];
                nodeList[cursor - 1 - i] = temp;
            }
            sortWay = 0;
        }

        //input too big
        if (input > maximent)
        {
            return 0;
        }

        //special case
        if (input <= nodeList[0])
        {
            if (input < nodeList[0])
                return cursor - 1;
            else
                return cursor - 2;
        }

        //find the max node
        int count = 0;
        int temp = maximent;
        for (count = 0; count < cursor; count++)
        {
            if (temp - nodeList[count] < input)
            {
                //count++;
                break;
            }
            temp -= nodeList[count];
        }
        return count;
    }

    void begin(char command)
    {
        int input;
        switch (command)
        {
        case 'I':
            cin >> input;
            //scanf("%d", &input);
            Insert(input);
            break;
        case 'D':
            cin >> input;
            // scanf("%d", &input);
            remove(input);
            break;
        case 'P':
            print();
            break;
        case 'L':
            cin >> input;
            //scanf("%d", &input);
            printf("%d\n", leastNode(input));
            break;
        case 'M':
            cin >> input;
            //scanf("%d", &input);
            printf("%d\n", maxNode(input));
            //cout << sortWay << endl;
            break;
        }
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
    bool sorting = 1; //need to sort
    bool sortWay = 0; //0 = power up; 1 = power down

    int maximent = 0;
    int nodeList[MAX] = {0};
    int cursor = 0;
};

int main()
{

    int times;
    int initialValue;
    //ss << in;
    tree T;
    //ss >> times;
    cin >> times;
    for (int i = 0; i < times; i++)
    {
        cin >> initialValue;
        T.Insert(initialValue);
    }
    char command = '\0';
    while (cin >> command)
    {
        T.begin(command);
    }
}