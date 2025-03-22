#include <iostream>

#define Ref Node*

using namespace std;

struct Node
{
	int data;
	Ref next;
};

struct Queue
{
	Ref head;
	Ref tail;
	int capacity;
};

void init(Queue &q, int n)
{
	q.head = nullptr;
	q.tail = nullptr;
	q.capacity = n;
}

bool enqueue(Queue& q, int x)
{
	Ref p = new Node;
	if (p == nullptr) return false;
	p->data = x;
	p->next = nullptr;
	if (q.head == nullptr) q.head = q.tail = p;
	else
	{
		Ref temp = q.head;
		while (temp->next != nullptr) temp = temp->next;
		temp->next = p;
	}
}

bool dequeue(Queue& q, int& x)
{
	if (q.head == nullptr) return false;
	x = q.head->data;
	Ref temp = q.head;
	q.head = q.head->next;
	delete temp;
	return true;
}

bool isEmpty(Queue& q)
{
	return q.head == nullptr;
}

void empty(Queue& q)
{
	Ref temp;
	while (q.head != nullptr)
	{
		temp = q.head;
		q.head = q.head->next;
		delete temp;
	}
}

int size(Queue& q)
{
	int count = 0;
	Ref temp = q.head;
	while (temp != nullptr)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void print(Queue q)
{
	for (Ref p = q.head; p != nullptr; p = p->next) cout << p->data << " ";
	cout << "\n";
}

int main()
{
	Queue q;
	int n;
	cout << "Enter queue's size: ";
	cin >> n;
	init(q, n);

	while (true)
	{
		system("cls");
		cout << "Current stack: ";
		print(q);
		string menu[5] = {
			"[1] Enqueue new value",
			"[2] Dequeue the first element",
			"[3] Check if queue is empty or not",
			"[4] Empty the queue",
			"[5] Get size of queue"
		};
		int choice = -1, x = 0;
		for (int i = 0; i <= 4; ++i) cout << menu[i] << "\n";
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter new value: ";
			cin >> x;
			enqueue(q, x);
			break;
		case 2:
			dequeue(q, x);
			cout << "Dequeued value: " << x;
			break;
		case 3:
			isEmpty(q) ? cout << "Queue is empty" : cout << "Queue is not empty";
			break;
		case 4:
			empty(q);
			cout << "Queue is now empty \n";
			break;
		case 5:
			cout << "Queue's size: " << size(q);
			break;
		default:
			cout << "Invalid choice \n";
			while (true)
			{
				cout << "Exit? Y/N: ";
				char ch;
				cin >> ch;
				if (ch == 'y' || ch - 32 == 'y')
				{
					system("pause");
					return 0;
				}
				else if (ch == 'n' || ch - 32 == 'n') break;
				else cout << "Invalid choice! \n";
			}
			break;
		}
		cout << "\nPress [Enter] to continue...";
		cin.ignore();
		cin.ignore();
	}

	system("pause");
	return 0;
}