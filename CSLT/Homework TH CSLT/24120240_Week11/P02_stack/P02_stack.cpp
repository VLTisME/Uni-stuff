#include <iostream>

#define Ref Node*

using namespace std;

struct Node
{
	int data;
	Ref next;
};

struct Stack
{
	Ref head;
	int capacity;
};

Ref getNode(int x)
{
	Ref p = new Node;
	if (p == nullptr) return nullptr;
	p->data = x;
	p->next = nullptr;
	return p;
}

void init(Stack& s, int n)
{
	s.head = nullptr;
	s.capacity = n;
}

void push(Stack& s, int x)
{
	if (s.capacity == 0)
	{
		cout << "Stack is full \n";
		return;
	}
	Ref p = getNode(x);
	s.head = p;
	s.capacity--;
	cout << "Pushed " << x << " into stack \n";
}

void pop(Stack& s)
{
	if (s.head == nullptr)
	{
		cout << "Stack is empty \n";
		return;
	}
	Ref p = s.head;
	s.head = p->next;
	delete p;
	cout << "Poped \n";
}

void isEmpty(Stack s)
{
	if (s.head == nullptr) cout << "Stack is empty \n";
	else cout << "Stack is not empty \n";
}

void empty(Stack& s)
{
	while (s.head != nullptr)
	{
		Ref p = s.head;
		s.head = p->next;
		delete p;
	}
	cout << "Stack is empty \n";
}

void size(Stack s)
{
	int count = 0;
	Ref p = s.head;
	while (p != nullptr)
	{
		count++;
		p = p->next;
	}
	cout << "Size of stack is " << count << "\n";
}

void print(Stack s)
{
	Ref p = s.head;
	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << "\n";
}


int main()
{
	Stack s;
	int n;
	cout << "Enter stack's size: ";
	cin >> n;
	init(s, n);

	while (true)
	{
		system("cls");
		cout << "Current stack: ";
		print(s);
		string menu[5] = {
			"[1] Push new value",
			"[2] Pop an element",
			"[3] Check if stack is empty or not",
			"[4] Empty the stack",
			"[5] Get size of stack"
		};
		int choice = -1;
		for (int i = 0; i <= 4; ++i) cout << menu[i] << "\n";
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			int x;
			cout << "Enter new value: ";
			cin >> x;
			push(s, x);
			break;
		case 2:
			pop(s);
			break;
		case 3:
			isEmpty(s);
			break;
		case 4:
			empty(s);
			break;
		case 5:
			size(s);
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