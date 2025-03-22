#include <iostream>  
#include <fstream>  

using namespace std;

struct Node {
    int key;
    Node* next;
};

Node* createNode(int k) {
    Node* newNode = new Node;
    newNode->key = k;
    newNode->next = nullptr;
    return newNode;
}

void addLast(Node*& head, Node*& tail, int k) {
    Node* p = createNode(k);
    if (head == nullptr) {
        head = tail = p;
    }
    else {
        tail->next = p;
        tail = p;
    }
}

void removeDuplicates(Node* head) {
    ofstream fileOutput("output.txt");
    const int MAX_SIZE = 10000;
    bool* visited = new bool[MAX_SIZE]();
    Node* p = head;
    while (p != nullptr) {
        int index = p->key;
        if (index >= 0 && index < MAX_SIZE) {
            if (!visited[index]) {
                cout << p->key << " ";
                fileOutput << p->key << " ";
                visited[index] = true;
            }
        }
        p = p->next;
    }
    delete[] visited;
    fileOutput.close();
}

void printList(Node* head) {
    Node* p = head;
    while (p != nullptr) {
        cout << p->key << " ";
        p = p->next;
    }
    cout << "\n";
}

void cleanUp(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int x;
    Node* head = nullptr;
    Node* tail = nullptr;
    ifstream fileInput("input.txt");
    if (!fileInput.is_open()) {
        cout << "Can't open input.txt\n";
        return 0;
    }
    while (true) {
        fileInput >> x;
        addLast(head, tail, x);
        if (x == 0) break;
    }
    fileInput.close();
    cout << "Old linked list: ";
    printList(head);
    cout << "Removed duplicate elements linked list: ";
    removeDuplicates(head);
    cout << "\n";
    cleanUp(head);
    return 0;
}