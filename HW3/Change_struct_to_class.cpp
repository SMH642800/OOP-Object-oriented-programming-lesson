#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#define STUDENT_TOTAL 20

using namespace std;

class studentType
{
    public:
        //member function
        //get value --> const
        void setFName(string);
        string getFName() const;
        void setLName(string);
        string getLName() const;
        void setScore(int);
        int getScore() const;
		void setGrade(char);
		char getGrade() const;

		//constructor
        studentType();
        studentType(string, string, int);
        studentType(string, string);
        studentType(string);

        //destructor
        ~studentType();

    private:
        //data member
        string studentFName;
        string studentLName;
        int testScore;
        char grade;
};

//constructor parameterized
studentType::studentType(string FName, string LName, int score){
    studentFName = FName;
    studentLName = LName;
    testScore = score;
    grade = 'X';
}
//constructor parameterized
studentType::studentType(string FName, string LName){
    studentFName = FName;
    studentLName = LName;
    testScore = -1;
    grade = 'X';
}
//constructor parameterized
studentType::studentType(string FName){
    studentFName = FName;
    studentLName = "";
    testScore = -1;
    grade = 'X';
}
//constructor parameterized
studentType::studentType(){
    studentFName = "";
    studentLName = "";
    testScore = -1;
    grade = 'X';
}
//destructor
studentType::~studentType(){
}

//class member function
void studentType::setFName(string FName){
    studentFName = FName;
}
//class member function
void studentType::setLName(string LName){
    studentLName = LName;
}
//class member function
void studentType::setScore(int score){
    testScore = score;
}
//class member function
int studentType::getScore() const{
    return testScore;
}
//class member function
string studentType::getFName() const{
    return studentFName;
}
//class member function
string studentType::getLName() const{
    return studentLName;
}
//class member function
void studentType::setGrade(char testGrade) {
	grade = testGrade;
}
//class member function
char studentType::getGrade() const {
	return grade;
}

//global function
void getData(fstream& inFile, studentType* sList, int listSize) {
    string FName;
    string LName;
    int score;
    for (int i = 0; i < listSize; i++) {
        // read inFile data
        inFile >> FName >> LName >> score; // read inFile data
        // call class member function
        sList[i].setFName(FName);
        sList[i].setLName(LName);
        sList[i].setScore(score);
    }
}
//global function
void calculateGrade(studentType* sList, int listSize) {
	for (int i = 0; i < listSize; i++) {
        // call class getScore() function & setGrade() function
		if (sList[i].getScore() <= 100 && sList[i].getScore() >= 90) sList[i].setGrade('A');
		else if (sList[i].getScore() <= 89 && sList[i].getScore() >= 80) sList[i].setGrade('B');
		else if (sList[i].getScore() <= 79 && sList[i].getScore() >= 70) sList[i].setGrade('C');
	}
}
//global function
int highestScore(const studentType* sList, int listSize) {
	int maxScore = -1;
	for (int i=0; i<listSize; i++) {
		if (sList[i].getScore() > maxScore) maxScore = sList[i].getScore();
	}
	return maxScore;
}
//global function
void printResult(fstream& outFile, studentType* sList, int listSize) {
	outFile << left << setw(20) << "Student Name"  << setw(15) << "Test Score" <<"Grade" << endl;
    for (int i = 0; i < listSize; i++) {
        outFile << left << setw(23) << sList[i].getLName() + ", " + sList[i].getFName() << setw(14) << sList[i].getScore() << sList[i].getGrade() << endl;
    }
    outFile << "\nHighest Test Score: " << highestScore(sList, listSize) << endl;
    outFile << "Student having the highest test score: " << endl;
    for (int i = 0; i < listSize; i++) {
    	if (sList[i].getScore() == highestScore(sList, listSize)) outFile << left << setw(20) << sList[i].getLName()  + ", " + sList[i].getFName() << endl;
    }
}

//main function
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
