#include <iostream>  
#include <iomanip>  
#include <vector>  
#include <string>  

using namespace std;

const int ROWS = 15;   // Total number of rows  
const int SEATS = 30;  // Total number of seats in each row  

void displaySeatingChart(const vector<vector<bool>>& seats, const vector<double>& prices) {
    cout << "\nSeats\n";
    cout << "Row  ";
    for (int i = 1; i <= SEATS; ++i) {
        cout << i % 10; // Print seat number  
    }
    cout << endl;

    for (int i = 0; i < ROWS; ++i) {
        cout << "Row " << (i + 1) << " ";
        for (int j = 0; j < SEATS; ++j) {
            cout << (seats[i][j] ? '#' : '*'); // Print # for taken, * for available  
        }
        cout << " | Price: $" << fixed << setprecision(2) << prices[i] << endl; // Display prices  
    }
}

bool isSeatAvailable(const vector<vector<bool>>& seats, int row, int seat) {
    return !seats[row - 1][seat - 1];
}

void sellTicket(vector<vector<bool>>& seats, const vector<double>& prices, double& totalSales, int row, int seat) {
    seats[row - 1][seat - 1] = true; // Mark the seat as taken  
    totalSales += prices[row - 1];
    cout << "Ticket sold for Row " << row << ", Seat " << seat << " at price $" << prices[row - 1] << endl;
}

void displaySales(const vector<vector<bool>>& seats) {
    int availableSeats = 0;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < SEATS; ++j) {
            if (!seats[i][j]) {
                availableSeats++;
            }
        }
    }
    cout << "Total available seats: " << availableSeats << endl;
}

int main() {
    vector<double> prices(ROWS);
    vector<vector<bool>> seats(ROWS, vector<bool>(SEATS, false));
    double totalSales = 0.0;

    // Enter seat prices  
    cout << "Enter the seat prices for each row:\n";
    for (int i = 0; i < ROWS; ++i) {
        cout << "Row " << (i + 1) << ": ";
        cin >> prices[i];
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display Seating Chart\n";
        cout << "2. Sell Ticket\n";
        cout << "3. View Total Sales\n";
        cout << "4. View Available Seats\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displaySeatingChart(seats, prices);
            break;
        case 2: {
            int row, seat;
            cout << "Enter row number (1-15): ";
            cin >> row;
            cout << "Enter seat number (1-30): ";
            cin >> seat;

            if (row < 1 || row > ROWS || seat < 1 || seat > SEATS) {
                cout << "Invalid row or seat number." << endl;
            }
            else if (isSeatAvailable(seats, row, seat)) {
                sellTicket(seats, prices, totalSales, row, seat);
            }
            else {
                cout << "Seat is already taken." << endl;
            }
            break;
        }
        case 3:
            cout << "Total ticket sales: $" << fixed << setprecision(2) << totalSales << endl;
            break;
        case 4:
            displaySales(seats);
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}