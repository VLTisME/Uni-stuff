#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream binInput;
ofstream binOutput;

void writeBinaryFile(string fileName, int n, int* arr)
{
	binOutput.open(fileName, ios::binary);

	binOutput.write((char*)&n, sizeof(n));
	binOutput.write((char*)arr, n * sizeof(int));

	binOutput.close();
}

int readBinaryFile(string fileName)
{
	binInput.open(fileName, ios::binary);
	if (!binInput.is_open())
	{
		cout << "Cannot open file " << fileName << "\n";
		return -1;
	}

	int n = 0;
	binInput.read((char*)&n, sizeof(n));
	int arr[1000];
	binInput.read((char*)arr, n * sizeof(int));

	binInput.close();

	sort(arr, arr + n);
	if (n % 2 == 0) return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
	return arr[n / 2];
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
			int n;
			cout << "Enter file name: ";
			cin >> fileName;
			cout << "Enter number of elements: ";
			cin >> n;
			int arr[1000];
			cout << "Enter elements: ";
			for (int i = 0; i < n; ++i) cin >> arr[i];
			writeBinaryFile(fileName, n, arr);
			break;
		case 2:
			cout << "Enter file name: ";
			cin >> fileName;
			cout << "Median: " << readBinaryFile(fileName);
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