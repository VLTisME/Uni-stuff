#include <iostream>  
#include <fstream>  
#include <vector>  
#include <string>  
#include <iomanip>  

using namespace std;

int main() {
    ifstream correctFile("CorrectAnswers.txt");
    ifstream studentFile("StudentAnswers.txt");

    if (!correctFile || !studentFile) {
        cout << "Error opening file(s)." << endl;
        return 1;
    }

    int numOfQuestions;
    correctFile >> numOfQuestions;

    vector<char> correctAnswers(numOfQuestions);
    vector<char> studentAnswers(numOfQuestions);

    for (int i = 0; i < numOfQuestions; ++i) {
        correctFile >> correctAnswers[i];
    }

    for (int i = 0; i < numOfQuestions; ++i) {
        studentFile >> studentAnswers[i];
    }

    correctFile.close();
    studentFile.close();

    int totalMissed = 0;
    vector<int> missedQuestions;
    vector<pair<char, char>> missedAnswers;

    for (int i = 0; i < numOfQuestions; ++i) {
        if (correctAnswers[i] != studentAnswers[i]) {
            totalMissed++;
            missedQuestions.push_back(i + 1); 
            missedAnswers.push_back(make_pair(correctAnswers[i], studentAnswers[i]));
        }
    }

    double percentageCorrect = (static_cast<double>(numOfQuestions - totalMissed) / numOfQuestions) * 100.0;

    cout << fixed << setprecision(2);
    cout << "Total questions missed: " << totalMissed << endl;

    for (size_t i = 0; i < missedQuestions.size(); ++i) {
        cout << "Question " << missedQuestions[i] << ": Correct Answer = "
            << missedAnswers[i].first << ", Your Answer = "
            << missedAnswers[i].second << endl;
    }

    cout << "Percentage of questions answered correctly: " << percentageCorrect << "%" << endl;

    if (percentageCorrect >= 70.0) {
        cout << "The student passed the exam." << endl;
    }
    else {
        cout << "The student failed the exam." << endl;
    }

    return 0;
}












