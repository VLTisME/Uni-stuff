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

void insertEvenNumber(Ref& head)
{
    int val = 2; // Start from 2  
    Ref ptrCurrent = head;
    Ref ptrBefore = nullptr;
    while (ptrCurrent != nullptr && ptrCurrent->key != 0)
    {
        Ref temp = getNode(val);
        val += 2; // Increment by 2 for each insertion  
        temp->next = ptrCurrent;

        if (ptrBefore != nullptr)
        {
            ptrBefore->next = temp;
        }
        else
        {
            head = temp;
        }
        ptrBefore = ptrCurrent;
        ptrCurrent = ptrCurrent->next;
    }
}

int main()
{
    int x;
    Ref head = nullptr;
    Ref tail = nullptr;
    fileInput.open("input.txt");
    if (!fileInput.is_open())
    {
        cout << "Can't open input.txt \n";
        system("pause");
        return 0;
    }

    while (true)
    {
        fileInput >> x;
        addLast(head, tail, x);
        if (x == 0) break;
    }
    fileInput.close();

    // Open fileOutput before writing  
    fileOutput.open("output.txt");

    cout << "Input linked list: ";
    printList(head);

    cout << "New linked list: ";
    insertEvenNumber(head);
    printList(head);

    fileOutput.close();

    cleanUp(head);
    system("pause");
    return 0;
}