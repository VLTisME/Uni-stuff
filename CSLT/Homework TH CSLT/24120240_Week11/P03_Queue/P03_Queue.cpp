#include <iostream>

using namespace std;

struct Queue
{
	int* data;
	int in;
	int out;
	int capacity;
};

void init(Queue& q, int n)
{
	q.data = new int[n];
	q.in = 0;
	q.out = 0;
	q.capacity = n;
}

bool enqueue(Queue& q, int x)
{
	if ((q.in + 1) % q.capacity == q.out)	return false;
	q.data[q.in] = x;
	q.in = (q.in + 1) % q.capacity;
	return true;
}

bool dequeue(Queue& q, int& x)
{
	if (q.in == q.out)
	{
		if (q.in == 0) q.in = q.out = 0;
		return false;
	}
	x = q.data[q.out];
	q.out = (q.out + 1) % q.capacity;
	return true;
}

bool isEmpty(Queue& q)
{
	return q.in == q.out;
}

void empty(Queue& q)
{
	q.in = q.out = 0;
}

int size(Queue& q)
{
	return q.in - q.out;
}

void print(Queue q)
{
	for (int i = q.out; i < q.in; ++i) cout << q.data[i] << " ";
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
					delete[] q.data;
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