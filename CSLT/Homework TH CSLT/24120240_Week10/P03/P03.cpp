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

void reverse(Ref head)
{
    if (head == nullptr) return;
    reverse(head->next);
    cout << head->key << " ";
    fileOutput << head->key << " ";
}

void printList(Ref head)
{
    for (Ref p = head; p != nullptr; p = p->next) cout << p->key << " ";
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
    cout << "Received linked list: ";
    printList(head);

    cout << "Reversed linked list: ";
    fileOutput.open("output.txt");
    reverse(head);
    fileOutput.close();

    cout << "\n";
    cleanUp(head);
    system("pause");
    return 0;
}