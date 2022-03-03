#include <iostream>
#define student_total 4
using namespace std;

struct studentScore {
    string firstName;
    string lastName;
    int csScore {};
    int dmScore {};
    int pdScore {};
    int toalScore {};
};

int highestCsScore(const studentScore* sList, int listSize){
    int highest_cs_score = 0;
    for(int i=0; i<listSize; i++){
        if(sList[i].csScore > highest_cs_score){
            highest_cs_score = sList[i].csScore;
        }
    }
    return highest_cs_score;
};

int highestDmScore(const studentScore* sList, int listSize){
    int highest_dm_score = 0;
    for(int i=0; i<listSize; i++){
        if(sList[i].dmScore > highest_dm_score){
            highest_dm_score = sList[i].dmScore;
        }
    }
    return highest_dm_score;
};

int highestPdScore(const studentScore* sList, int listSize){
    int highest_pd_score = 0;
    for(int i=0; i<listSize; i++){
        if(sList[i].pdScore > highest_pd_score){
            highest_pd_score = sList[i].pdScore;
        }
    }
    return highest_pd_score;
};

int highestTotalScore(const studentScore* sList, int listSize){
    int highest_total_score = 0;
    for(int i=0; i<listSize; i++){
        int totalScore = sList[i].csScore + sList[i].dmScore + sList[i].pdScore;
        if(totalScore > highest_total_score){
            highest_total_score = totalScore;
        }
    }
    return highest_total_score;
};

int main() {

    studentScore students[student_total];

    for(int i=0; i<student_total; i++){
        cin >> students[i].firstName >> students[i].lastName >> students[i].csScore >> students[i].dmScore >> students[i].pdScore;
    }

    int max_csScore = highestCsScore(students, student_total);
    for(int i=0; i<student_total; i++){
        if(students[i].csScore == max_csScore){
            cout << "Highest CS Score: " << max_csScore << ", " << students[i].firstName << " " << students[i].lastName << endl;
        }
    }

    int max_dmScore = highestDmScore(students, student_total);
    for(int i=0; i<student_total; i++){
        if(students[i].dmScore == max_dmScore){
            cout << "Highest DM Score: " << max_dmScore << ", " << students[i].firstName << " " << students[i].lastName << endl;
        }
    }

    int max_pdScore = highestPdScore(students, student_total);
    for(int i=0; i<student_total; i++){
        if(students[i].pdScore == max_pdScore){
            cout << "Highest PD Score: " << max_pdScore << ", " << students[i].firstName << " " << students[i].lastName << endl;
        }
    }

    int max_totalScore = highestTotalScore(students, student_total);
    for(int i=0; i<student_total; i++){
        int TotalScore = students[i].csScore + students[i].dmScore + students[i].pdScore;
        if(TotalScore == max_totalScore){
            cout << "Highest Total Score: " << max_totalScore << ", " << students[i].firstName << " " << students[i].lastName << endl;
        }
    }

    return 0;
};
