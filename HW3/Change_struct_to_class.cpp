#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#define STUDENT_TOTAL 20

using namespace std;

class studentType
{
    public:
        void setScore(int);
        int getScore() const;
        void setFName(string);
        string getFName() const;
        void setLName(string);
        string getLName() const;
		void setGrade(char);
		char getGrade() const;
        studentType();
        studentType(string, string, int);
        studentType(string, string);
        studentType(string);
        ~studentType();
    private:
        string studentFName;
        string studentLName;
        int testScore;
        char grade;
};

void getData(fstream& inFile, studentType sList[], int listSize);
void printResult(fstream& outFile, studentType* sList, int listSize);
void calculateGrade(studentType* sList, int listSize);
int highestScore(const studentType* sList, int listSize);

int main(void)
{
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

void getData(fstream& inFile, studentType* sList, int listSize) {
    string FName;
    string LName;
    int score;
    for (int i = 0; i < listSize; i++) {
        inFile >> FName >> LName >> score;
        sList[i].setFName(FName);
        sList[i].setLName(LName);
        sList[i].setScore(score);
    }
}

void calculateGrade(studentType* sList, int listSize) {
	for (int i = 0; i < listSize; i++) {
		if (sList[i].getScore() <= 100 && sList[i].getScore() >= 90) sList[i].setGrade('A');
		else if (sList[i].getScore() <= 89 && sList[i].getScore() >= 80) sList[i].setGrade('B');
		else if (sList[i].getScore() <= 79 && sList[i].getScore() >= 70) sList[i].setGrade('C');
	}
}

int highestScore(const studentType* sList, int listSize) {
	int maxScore = -1;
	for (int i=0; i<listSize; i++) {
		if (sList[i].getScore() > maxScore) maxScore = sList[i].getScore();
	}
	return maxScore;
}

void printResult(fstream& outFile, studentType* sList, int listSize) {
	outFile << left << setw(20) << "Student Name"  << setw(15) << "Test Score" <<"Grade" << endl;
    for (int i = 0; i < listSize; i++) {
        outFile << left << setw(23) << sList[i].getLName() + ", " + sList[i].getFName() << setw(14) << sList[i].getScore() << sList[i].getGrade() << endl;
    }
    outFile << "\nHighest Test Score: " << highestScore(sList, STUDENT_TOTAL) << endl;
    outFile << "Student having the highest test score: " << endl;
    for (int i = 0; i < listSize; i++) {
    	if (sList[i].getScore() == highestScore(sList, STUDENT_TOTAL)) outFile << left << setw(20) << sList[i].getLName()  + ", " + sList[i].getFName() << endl;
    }
}

studentType::studentType(string FName, string LName, int score){
    studentFName = FName;
    studentLName = LName;
    testScore = score;
    grade = 'X';
}

studentType::studentType(string FName, string LName){
    studentFName = FName;
    studentLName = LName;
    testScore = -1;
    grade = 'X';
}

studentType::studentType(string FName){
    studentFName = FName;
    studentLName = "";
    testScore = -1;
    grade = 'X';
}

studentType::studentType(){
    studentFName = "";
    studentLName = "";
    testScore = -1;
    grade = 'X';
}

studentType::~studentType(){
}

void studentType::setFName(string FName){
    studentFName = FName;
}

void studentType::setLName(string LName){
    studentLName = LName;
}

void studentType::setScore(int score){
    testScore = score;
}

int studentType::getScore() const{
    return testScore;
}

string studentType::getFName() const{
    return studentFName;
}

string studentType::getLName() const{
    return studentLName;
}

void studentType::setGrade(char testGrade) {
	grade = testGrade;
}

char studentType::getGrade() const {
	return grade;
}

