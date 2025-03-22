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

void splitLinkedList(Ref head, Ref& even, Ref& odd)
{
	Ref oddTail = nullptr;
	Ref evenTail = nullptr;

	int index = 0;
	while (head)
	{
		index++;
		if (index % 2 != 0)
		{
			if (!odd)
			{
				odd = head;
				oddTail = head;
			}
			else
			{
				oddTail->next = head;
				oddTail = head;
			}
		}
		else
		{
			if (!even)
			{
				even = head;
				evenTail = head;
			}
			else
			{
				evenTail->next = head;
				evenTail = head;
			}
		}
		head = head->next;
	}

	if (oddTail) oddTail->next = nullptr;
	if (evenTail) evenTail->next = nullptr;

	if (oddTail->key != 0)
	{
		Ref p = getNode(0);
		oddTail->next = p;
		oddTail = p;
	}
	if (evenTail->key != 0)
	{
		Ref p = getNode(0);
		evenTail->next = p;
		evenTail = p;
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
	cout << "Old linked list: ";
	printList(head);
	Ref even = nullptr;
	Ref odd = nullptr;
	splitLinkedList(head, even, odd);
	cout << "Even linked list: ";
	printList(even);
	cout << "Odd linked list: ";
	printList(odd);
	fileOutput.open("output.txt");
	fileOutput << "Even linked list: ";
	for (Ref p = even; p != nullptr; p = p->next) fileOutput << p->key << " ";
	fileOutput << "\n";
	fileOutput << "Odd linked list: ";
	for (Ref p = odd; p != nullptr; p = p->next) fileOutput << p->key << " ";
	fileOutput.close();

	cleanUp(even);
	cleanUp(odd);
	system("pause");
	return 0;
}