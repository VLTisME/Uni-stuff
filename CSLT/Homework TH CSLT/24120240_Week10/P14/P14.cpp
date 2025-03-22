#include <iostream>  
#include <string>  
#include <limits> // For std::numeric_limits  

#define Ref Node*  

using namespace std;

struct Node
{
    string title;
    string isbn;
    string author;
    string language;
    int year;
    double price;
    int stock;
    Ref next;
};

Ref getNode(string title, string isbn, string author, string language, int year, double price, int stock)
{
    Ref p = new Node;
    if (p == nullptr) return nullptr;
    p->title = title;
    p->isbn = isbn;
    p->author = author;
    p->language = language;
    p->year = year;
    p->price = price;
    p->stock = stock;
    p->next = nullptr;
    return p;
}

// Modified addLast to use the tail pointer efficiently  
void addLast(Ref& head, Ref& tail, string title, string isbn, string author, string language, int year, double price, int stock)
{
    Ref p = getNode(title, isbn, author, language, year, price, stock);
    if (head == nullptr)
    {
        head = tail = p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
}

bool isValid(Ref head, string isbn)
{
    for (Ref p = head; p != nullptr; p = p->next)
        if (p->isbn == isbn) return true;
    return false;
}

void inputBook(Ref& head, Ref& tail)
{
    cout << "Inputting a book... \n";

    // Clear the input buffer before reading lines  
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    string title, isbn, author, language;
    int year;
    double price;

    cout << "Enter title: ";
    getline(cin, title);

    cout << "Enter ISBN: ";
    getline(cin, isbn);

    cout << "Enter author: ";
    getline(cin, author);

    cout << "Enter language: ";
    getline(cin, language);

    cout << "Enter year: ";
    cin >> year;

    cout << "Enter price: ";
    cin >> price;

    // Clear the input buffer again in case there's leftover input  
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (isValid(head, isbn))
    {
        for (Ref p = head; p != nullptr; p = p->next)
            if (p->isbn == isbn)
            {
                cout << "Increased stock for book \"" << p->title << "\" with ISBN: " << isbn << "\n";
                p->stock += 1;
                return;
            }
    }
    else
    {
        cout << "Added book \"" << title << "\" with ISBN: " << isbn << "\n";
        addLast(head, tail, title, isbn, author, language, year, price, 1); // Stock starts at 1  
    }
}

void sellBook(Ref& head)
{
    if (head == nullptr)
    {
        cout << "No books are available!\n";
        return;
    }

    // Display all books with their stock levels  
    for (Ref p = head; p != nullptr; p = p->next)
    {
        cout << "Book \"" << p->title << "\" with ISBN: " << p->isbn << "\n";
        cout << "Stock: " << p->stock << "\n";
        cout << "-----\n";
    }

    string isbn;
    cout << "Enter book's ISBN: ";
    cin >> isbn;

    if (isValid(head, isbn))
    {
        for (Ref p = head; p != nullptr; p = p->next)
            if (p->isbn == isbn)
            {
                if (p->stock >= 1)
                {
                    cout << "Sold a book named \"" << p->title << "\" with ISBN: " << p->isbn << "\n";
                    p->stock -= 1;
                    cout << "Remaining stock: " << p->stock << "\n";
                }
                else
                {
                    cout << "OUT OF STOCK! \n";
                }
                return;
            }
    }
    else
    {
        cout << "No book matches this ISBN: " << isbn << "\n";
    }
}

void findBook(Ref head)
{
    if (head == nullptr)
    {
        cout << "No books are available!\n";
        return;
    }

    for (Ref p = head; p != nullptr; p = p->next)
        cout << "Book \"" << p->title << "\" with ISBN: " << p->isbn << "\n";

    string isbn;
    cout << "\nEnter ISBN: ";
    cin >> isbn;

    for (Ref p = head; p != nullptr; p = p->next)
        if (p->isbn == isbn)
        {
            cout << "Title: " << p->title << "\n";
            cout << "ISBN: " << p->isbn << "\n";
            cout << "Author: " << p->author << "\n";
            cout << "Language: " << p->language << "\n";
            cout << "Year: " << p->year << "\n";
            cout << "Price: " << p->price << "\n";
            cout << "Stock: " << p->stock << "\n";
            return;
        }

    cout << "No book with ISBN: " << isbn << " found \n";
}

void removeBook(Ref& head, Ref& tail, int stockThreshold)
{
    if (head == nullptr)
    {
        tail = nullptr;
        cout << "No books found! \n";
        return;
    }

    int stock;
    if (stockThreshold != -1)
    {
        stock = stockThreshold;
    }
    else
    {
        cout << "Enter stock threshold: ";
        cin >> stock;
    }

    Ref ptrCurrent = head;
    Ref ptrBefore = nullptr;

    while (ptrCurrent != nullptr)
    {
        if (ptrCurrent->stock < stock)
        {
            cout << "Book \"" << ptrCurrent->title << "\" with ISBN: " << ptrCurrent->isbn << " has been removed!\n";

            if (ptrCurrent == head)
            {
                head = ptrCurrent->next;
                if (ptrCurrent == tail)
                    tail = nullptr;
                delete ptrCurrent;
                ptrCurrent = head;
            }
            else
            {
                if (ptrCurrent == tail)
                    tail = ptrBefore;

                ptrBefore->next = ptrCurrent->next;
                delete ptrCurrent;
                ptrCurrent = ptrBefore->next;
            }
        }
        else
        {
            ptrBefore = ptrCurrent;
            ptrCurrent = ptrCurrent->next;
        }
    }
}

void listAllBook(Ref head)
{
    if (head == nullptr)
    {
        cout << "No books are available! \n";
        return;
    }

    int i = 0;
    for (Ref p = head; p != nullptr; p = p->next)
    {
        i++;
        cout << "Book " << i << ": \n";
        cout << "Title: " << p->title << "\n";
        cout << "ISBN: " << p->isbn << "\n";
        cout << "Author: " << p->author << "\n";
        cout << "Language: " << p->language << "\n";
        cout << "Year: " << p->year << "\n";
        cout << "Price: " << p->price << "\n";
        cout << "Stock: " << p->stock << "\n";
        cout << "-----\n";
    }
}

int main()
{
    Ref head = nullptr;
    Ref tail = nullptr;

    string menu[4] = {
        "[1] Add a new or already existing book",
        "[2] Sell a book",
        "[3] Find a book",
        "[4] Remove all book's data if its stock lower than a number"
    };

    while (true)
    {
        listAllBook(head);
        int choice = -1;
        for (int i = 0; i < 4; ++i)
            cout << menu[i] << "\n";
        cout << "\n[0] Exit \n\nEnter your choice as a number: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            inputBook(head, tail);
            break;
        case 2:
            sellBook(head);
            break;
        case 3:
            findBook(head);
            break;
        case 4:
            removeBook(head, tail, -1);
            break;
        case 0:
            removeBook(head, tail, INT_MAX); // Clean up before exiting  
            cout << "Exiting the program...\n";
            return 0;
        default:
            cout << "Invalid choice! \n";
            char ch;
            do
            {
                cout << "Exit? Y/N: ";
                cin >> ch;
                ch = toupper(ch);
                if (ch == 'Y')
                {
                    removeBook(head, tail, INT_MAX); // Clean up before exiting  
                    cout << "Exiting the program...\n";
                    return 0;
                }
                else if (ch == 'N')
                {
                    break;
                }
                else
                {
                    cout << "Invalid input! Please enter 'Y' or 'N'.\n";
                }
            } while (true);
            break;
        }

        cout << "\nPress [Enter] to continue...";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get(); // Wait for Enter key  
    }

    removeBook(head, tail, INT_MAX); // Clean up before exiting  
    return 0;
}
