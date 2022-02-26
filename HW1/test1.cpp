#include <iostream>
#include <fstream>
#include <iomanip>
#define STUDENT_TOTAL 20
using namespace std;

struct studentType
{
    string studentFName;
    string studentLName;
    int testScore {};
    char grade {};
};

void getData(fstream& inFile, studentType* sList, int listSize) {
    for (int i = 0; i < listSize; i++) {
        inFile >> sList[i].studentFName >> sList[i].studentLName >> sList[i].testScore;
    }
}

void calculateGrade(studentType* sList, int listSize) {
    for (int i = 0; i < listSize; i++) {
        if (sList[i].testScore <= 100 && sList[i].testScore >= 90) sList[i].grade = 'A';
        else if (sList[i].testScore < 90 && sList[i].testScore >= 80) sList[i].grade = 'B';
        else if (sList[i].testScore < 80 && sList[i].testScore >= 70) sList[i].grade = 'C';
    }
}

int highestScore(const studentType* sList, int listSize) {
    int max_score = 0;
    for (int i = 0; i < listSize; i++) {
        if (sList[i].testScore > max_score) max_score = sList[i].testScore;
    }
    return max_score;
}

void printResult(fstream& outFile, studentType* sList, int listSize) {
    // left : 置左，setw(n) << "string" : 共強制空20格字元，若20 - len(string)後仍有空位，則以空白填空格子
    outFile << left << setw(20) << "Student Name" << setw(15) << "Test Score" <<  "Grade" << endl;
    for (int i = 0; i < listSize; i++) {
        outFile << left << setw(23) << sList[i].studentLName + ", " + sList[i].studentFName << setw(14) << sList[i].testScore <<  sList[i].grade << endl;
    }
    outFile << "\nHighest Test Score: " << highestScore(sList, STUDENT_TOTAL) << endl;
    outFile << "Student having the highest test score: " << endl;
    for (int i = 0; i < listSize; i++) {
        if (sList[i].testScore == highestScore(sList, STUDENT_TOTAL)) outFile << left << setw(20) << sList[i].studentLName + ", " + sList[i].studentFName << endl;
    }
}

int main(void) {
    fstream input_file, output_file;
    input_file.open("./ch09_ex02.txt", ios::in);
    studentType students[STUDENT_TOTAL];
    getData(input_file, students, STUDENT_TOTAL);
    input_file.close();
    calculateGrade(students, STUDENT_TOTAL);
    output_file.open("./ch09_ex02_out.txt", ios::out);
    printResult(output_file, students, STUDENT_TOTAL);
    output_file.close();
    return 0;
}
