#include <iostream>  
#include <vector>  
#include <cstdlib>  

using namespace std;

struct Lab {
    int stations;
    int* users; // Array to hold user IDs for the stations  
};

void initializeLabs(Lab* labs, int M, int N) {
    for (int i = 0; i < M; ++i) {
        labs[i].stations = N;
        labs[i].users = new int[N]; // Allocate memory for stations  
        for (int j = 0; j < N; ++j) {
            labs[i].users[j] = 0; // 0 means no user logged in  
        }
    }
}

void logIn(Lab* labs, int labNum, int stationNum, int userId) {
    *(labs[labNum].users + stationNum) = userId;
}

void logOut(Lab* labs, int labNum, int stationNum) {
    labs[labNum].users[stationNum] = 0; // Set to 0 upon logout  
}

void displayLabs(Lab* labs, int M) {
    cout << "Current Logins:\n";
    for (int i = 0; i < M; ++i) {
        cout << "Lab " << (i + 1) << ": ";
        for (int j = 0; j < labs[i].stations; ++j) {
            cout << *(labs[i].users + j) << " ";
        }
        cout << endl;
    }
}

void searchUser(Lab* labs, int M, int userId) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < labs[i].stations; ++j) {
            if (labs[i].users[j] == userId) {
                cout << "User " << userId << " is in Lab " << (i + 1)
                    << " at Station " << (j + 1) << endl;
                return;
            }
        }
    }
    cout << "User " << userId << " is not logged into any computer station." << endl;
}

int main() {
    int M, N;

    cout << "Enter the number of labs: ";
    cin >> M;
    cout << "Enter the number of stations per lab: ";
    cin >> N;

    Lab* labs = new Lab[M]; // Allocate memory for labs  
    initializeLabs(labs, M, N);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Log In\n";
        cout << "2. Log Out\n";
        cout << "3. Display Current Logins\n";
        cout << "4. Search User\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            int labNum, stationNum, userId;
            cout << "Enter lab number (1 to " << M << "): ";
            cin >> labNum;
            cout << "Enter station number (1 to " << N << "): ";
            cin >> stationNum;
            cout << "Enter user ID (5-digit number): ";
            cin >> userId;
            logIn(labs, labNum - 1, stationNum - 1, userId); // Adjust for 0-based index  

        }
        else if (choice == 2) {
            int labNum, stationNum;
            cout << "Enter lab number (1 to " << M << "): ";
            cin >> labNum;
            cout << "Enter station number (1 to " << N << "): ";
            cin >> stationNum;
            logOut(labs, labNum - 1, stationNum - 1); // Adjust for 0-based index  

        }
        else if (choice == 3) {
            displayLabs(labs, M);

        }
        else if (choice == 4) {
            int userId;
            cout << "Enter user ID to search: ";
            cin >> userId;
            searchUser(labs, M, userId);
        }

    } while (choice != 5);

    // Free allocated memory  
    for (int i = 0; i < M; ++i) {
        delete[] labs[i].users; // Free memory for users  
    }
    delete[] labs; // Free memory for labs  

    return 0;
}





