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

void addLast(Ref &head, Ref &tail, int k)
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

void cleanUp(Ref &head)
{
	while (head != nullptr)
	{
		Ref temp = head;
		head = head->next;
		delete temp;
	}
}

Ref calcSumEle(Ref head)
{
	if (head == nullptr) return nullptr;
	Ref newHead = nullptr;
	Ref newTail = nullptr;
	int s = 0;
	while (head != nullptr)
	{
		s += head->key;
		Ref p = getNode(s);
		if (newHead == nullptr)
		{
			newHead = p;
			newTail = p;
		}
		else
		{
			newTail->next = p;
			newTail = p;
		}
		head = head->next;
	}
	return newHead;
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
	Ref newHead = calcSumEle(head);
	cout << "New linked list: ";
	printList(newHead);
	fileOutput.open("output.txt");
	for (Ref p = head; p != nullptr; p = p->next) fileOutput << p->key << " ";
	fileOutput.close();

	cleanUp(head);
	cleanUp(newHead);
	system("pause");
	return 0;
}