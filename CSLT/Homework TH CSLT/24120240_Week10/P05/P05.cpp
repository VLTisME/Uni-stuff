#include <iostream>  
#include <fstream>  

#define Ref Node*  

using namespace std;

struct Node
{
    int key;
    Ref next;
};

ifstream fileInput;
ofstream fileOutput;

Ref getNode(int k)
{
    Ref p = new Node;
    if (p == nullptr) return nullptr;
    p->key = k;
    p->next = nullptr;
    return p;
}

void addLast(Ref& head, Ref& tail, int k)
{
    Ref p = getNode(k);
    if (head == nullptr)
    {
        head = tail = p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
}

void printList(Ref head)
{
    for (Ref p = head; p != nullptr; p = p->next)
    {
        cout << p->key << " ";
        fileOutput << p->key << " ";
    }
    cout << "\n";
}

void cleanUp(Ref& head)
{
    while (head != nullptr)
    {
        Ref temp = head;
        head = head->next;
        delete temp;
    }
}

void insertSortedList(Ref& head, int x)
{
    Ref p = getNode(x);
    if (!p) return;

    if (!head || head->key > x)
    {
        p->next = head;
        head = p;
        return;
    }

    Ref ptrCurrent = head;
    while (ptrCurrent->next && ptrCurrent->next->key < x)
    {
        ptrCurrent = ptrCurrent->next;
    }

    p->next = ptrCurrent->next;
    ptrCurrent->next = p;
}

int main()
{
    int x, t;
    Ref head = nullptr;
    Ref tail = nullptr;

    fileInput.open("input.txt");
    if (!fileInput.is_open())
    {
        cout << "Can't open input.txt \n";
        system("pause");
        return 0;
    }

    fileInput >> x;
    while (true)
    {
        fileInput >> t;
        addLast(head, tail, t);
        if (t == 0) break;
    }
    fileInput.close();

    // Open fileOutput before using it  
    fileOutput.open("output.txt");

    cout << "Old linked list: ";
    printList(head);
    cout << "Number that needs to be inserted: " << x << "\n";
    insertSortedList(head, x);
    cout << "New linked list: ";
    printList(head);

    fileOutput.close();

    cleanUp(head);
    system("pause");
    return 0;
}