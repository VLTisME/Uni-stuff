#include <iostream>

using namespace std;

struct Stack
{
	int* data;
	int top;
	int capacity;
};

void init(Stack& s, int capacity)
{
	s.data = new int[capacity];
	s.top = -1;
	s.capacity = capacity;
}

void push(Stack& s, int x)
{
	if (s.top >= s.capacity - 1)
	{
		cout << "Stack is full \n";
		return;
	}
	s.data[++s.top] = x;
	cout << "Pushed " << x << " into stack \n";
}

void pop(Stack& s)
{
	if (s.top == -1)
	{
		cout << "Stack is empty \n";
		return;
	}
	cout << s.data[s.top] << "\n";
	s.top--;
}

void isEmpty(Stack s)
{
	if (s.top == -1) cout << "Stack is empty \n";
	else cout << "Stack is not empty \n";
}

void empty(Stack& s)
{
	delete[] s.data;
}

void size(Stack& s)
{
	cout << s.top + 1 << "\n";
}

void print(Stack s)
{
	for (int i = 0; i <= s.top; ++i) cout << s.data[i] << " ";
	cout << "\n \n";
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
					empty(s);
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