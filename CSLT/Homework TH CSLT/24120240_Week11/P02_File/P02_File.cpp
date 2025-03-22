#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int N = 1e3 + 7;

struct Date
{
	int day;
	int month;
	int year;
};

ifstream binInput;
ofstream binOutput;

bool compareDate(Date a, Date b)
{
	if (a.year != b.year) return a.year > b.year;
	if (a.month != b.month) return a.month > b.month;
	return a.day > b.day;
}

void writeBinaryFile(string fileName)
{
	int n;
	cout << "Enter number of dates: ";
	cin >> n;
	Date date[N];
	for (int i = 0; i < n; ++i)
	{
		cout << "Enter date " << i + 1<< " as dd mm yyyy: ";
		cin >> date[i].day >> date[i].month >> date[i].year;
	}

	binOutput.open(fileName, ios::binary);
	binOutput.write((char*)&n, sizeof(n));
	binOutput.write((char*)date, n * sizeof(Date));
	binOutput.close();

	cout << "Write file successfully. \n";
}

void readBinaryFile(string fileName)
{
	binInput.open(fileName, ios::binary);
	if (!binInput.is_open())
	{
		cout << "Cannot open file " << fileName << "\n";
		return;
	}
	int n = 0;
	binInput.read((char*)&n, sizeof(n));
	Date date[N];
	binInput.read((char*)date, n * sizeof(Date));
	binInput.close();

	for (int i = 0; i < n; ++i)
	{
		cout << "Date " << i + 1 << ": ";
		cout << date[i].day << "/" << date[i].month << "/" << date[i].year << "\n";
	}

	sort(date, date + n, compareDate);
	cout << "Newest date: " << date[0].day << "/" << date[0].month << "/" << date[0].year << "\n";
}

int main()
{
	while (true)
	{
		system("cls");
		string menu[2] = {
			"[1] Write binary file",
			"[2] Read binary file"
		};
		int choice = -1;
		string fileName;
		for (int i = 0; i < 2; ++i) cout << menu[i] << "\n";
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter file name: ";
			cin >> fileName;
			writeBinaryFile(fileName);
			break;
		case 2:
			cout << "Enter file name: ";
			cin >> fileName;
			readBinaryFile(fileName);
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