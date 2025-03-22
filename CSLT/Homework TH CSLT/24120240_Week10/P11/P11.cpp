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
	if (head == nullptr) head = tail = p;
	else
	{
		Ref temp = head;
		while (temp->next != nullptr) temp = temp->next;
		temp->next = p;
	}
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

Ref func(int n)
{
	Ref head = nullptr;

	while (n > 0)
	{
		int t = n % 10;
		n /= 10;
		addLast(head, head, t);
	}

	return head;
}

Ref reverseLinkedList(Ref head)
{
	Ref ptrBefore = nullptr;
	Ref ptrCurrent = head;
	Ref ptrAfter = nullptr;

	while (ptrCurrent)
	{
		ptrAfter = ptrCurrent->next;
		ptrCurrent->next = ptrBefore;
		ptrBefore = ptrCurrent;
		ptrCurrent = ptrAfter;
	}
	addLast(ptrBefore, ptrBefore, -1);

	return ptrBefore;
}

int main()
{
	int x;
	Ref head = nullptr;
	fileInput.open("input.txt");
	if (!fileInput.is_open())
	{
		cout << "Can't open input.txt \n";
		system("pause");
		return 0;
	}
	fileInput >> x;
	fileInput.close();
	cout << "Old number: ";
	cout << x << "\n";
	head = func(x);
	head = reverseLinkedList(head);
	cout << "New linked list: ";
	printList(head);
	fileOutput.open("output.txt");
	for (Ref p = head; p != nullptr; p = p->next) fileOutput << p->key << " ";
	fileOutput.close();

	cleanUp(head);
	system("pause");
	return 0;
}