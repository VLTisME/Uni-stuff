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

int func(Ref head, int n)
{
	int r = 0;
	for (Ref p = head; p != nullptr; p = p->next)
	{
		n--;
		if (p->key != 0) r += p->key * pow(10, n);
		//cout << r << " " << p->key << "\n";
	}
	return r;
}

int main()
{
	int x, n = 0, res = 0;;
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
		if (x == -1) break;
		n++;
		addLast(head, tail, x);
	}
	fileInput.close();
	cout << "Old linked list: ";
	printList(head);
	res = func(head, n);
	cout << "Number merged from linked list: ";
	cout << res << "\n";
	fileOutput.open("output.txt");
	fileOutput << res;
	fileOutput.close();

	cleanUp(head);
	system("pause");
	return 0;
}