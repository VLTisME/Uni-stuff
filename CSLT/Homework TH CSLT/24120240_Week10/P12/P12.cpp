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

pair<int, int> findNode(Ref list1, Ref list2)
{
	int i, j;
	i = j = 0;
	for (Ref p = list1; p != nullptr; p = p->next)
	{
		i++;
		for (Ref q = list2; q != nullptr; q = q->next)
		{
			j++;
			if (p->key == q->key) return { i, j };
		} 
	}
	return { -1, -1 };
}

int main()
{
	int x;
	Ref list1Head = nullptr;
	Ref list1Tail = nullptr;
	Ref list2Head = nullptr;
	Ref list2Tail = nullptr;
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
	pair<int, int> res = findNode(list1Head, list2Head);
	fileOutput.open("output.txt");
	if (res.first == -1 || res.second == -1)
	{
		cout << "Linked list A & B won't joined";
		fileOutput << "Linked list A & B won't joined";
	}
	else
	{
		cout << "Linked list A has node " << res.first << " joined with node " << res.second << " in linked list B";
		fileOutput << "Linked list A has node " << res.first << " joined with node " << res.second << " in linked list B";
	}
	fileOutput.close();

	cleanUp(list1Head);
	cleanUp(list2Head);
	cout << "\n";
	system("pause");
	return 0;
}