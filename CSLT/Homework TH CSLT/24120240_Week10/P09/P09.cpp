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

Ref mergeLinkedLists(Ref list1, Ref list2)
{
	if (!list1) return list2;

	Ref temp = list1;
	while (temp->next) temp = temp->next;

	temp->next = list2;
	return list1;
}

int main()
{
	int x;
	Ref list1Head = nullptr;
	Ref list1Tail = nullptr;
	Ref list2Head = nullptr;
	Ref list2Tail = nullptr;
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
		if (x == 0) break;
		addLast(list1Head, list1Tail, x);
	}
	while (true)
	{
		fileInput >> x;
		addLast(list2Head, list2Tail, x);
		if (x == 0) break;
	}
	fileInput.close();
	cout << "First linked list: ";
	printList(list1Head);
	cout << "Second linked list: ";
	printList(list2Head);
	head = mergeLinkedLists(list1Head, list2Head);
	cout << "New linked list: ";
	printList(head);
	fileOutput.open("output.txt");
	for (Ref p = head; p != nullptr; p = p->next) fileOutput << p->key << " ";
	fileOutput.close();

	cleanUp(head);
	system("pause");
	return 0;
}