#include <iostream>  
#include <fstream>  

#define Ref Node*  

using namespace std;

struct Node
{
    int key;
    Ref next;
};

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
        cout << p->key << " ";
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

bool FloydCycleDetection(Ref head)
{
    Ref slow = head;
    Ref fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main()
{
    int x;
    Ref head = nullptr;
    Ref tail = nullptr;

    ifstream fileInput("input.txt");
    if (!fileInput.is_open())
    {
        cout << "Can't open input.txt\n";
        return 1;
    }

    while (fileInput >> x)
    {
        addLast(head, tail, x);
        if (x == 0) break;
    }
    fileInput.close();

    cout << "Linked list: ";
    printList(head);

    // Optional: Create a loop in the linked list for testing  
    // Uncomment the following code block to introduce a loop  
    /*
    if (tail != nullptr && head != nullptr)
    {
        tail->next = head->next; // Creates a loop for testing
    }
    */

    ofstream fileOutput("output.txt");
    if (!fileOutput.is_open())
    {
        cout << "Can't open output.txt\n";
        cleanUp(head);
        return 1;
    }

    if (FloydCycleDetection(head))
    {
        cout << "Loop detected";
        fileOutput << "Loop detected";
    }
    else
    {
        cout << "Loop not detected";
        fileOutput << "Loop not detected";
    }
    fileOutput.close();

    // If a loop was created, break it before cleanup to prevent infinite loops  
    /*
    if (tail != nullptr)
    {
        tail->next = nullptr;
    }
    */

    cleanUp(head);
    cout << "\n";
    return 0;
}