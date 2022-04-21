#include <iostream>
#include <iomanip>

using namespace std;

class Scores {
private:
    double A[100], B[100], N;
public:
    void getScore(istream &os)
    {
        for(int i = 0; i < N; i++){
            cin >> A[i] >> B[i];
        }
    }
    void printAverage(ostream &os)
    {
        double sumA = 0 , sumB = 0;
        for(int i = 0; i < N; i++){
            sumA += A[i];
        }
        cout << sumA / N << " ";
        for(int i = 0; i < N; i++){
            sumB += B[i];
        }
        cout << sumB / N << endl;
    }
    void printVariance(ostream &os)
    {
        double avgA = 0, avgB = 0;
        double sumA = 0 , sumB = 0;
        for(int i = 0; i < N; i++){
            sumA += A[i];
        }
        avgA = sumA / N;
        for(int i = 0; i < N; i++){
            sumB += B[i];
        }
        avgB = sumB / N;

        double vA = 0 , vB = 0;
        for(int i = 0; i < N; i++){
            vA += (A[i]-avgA)*(A[i]-avgA);
        }
        cout << vA / N << " ";
        for(int i = 0; i < N; i++){
            vB += (B[i]-avgB)*(B[i]-avgB);
        }
        cout << vB / N << endl;
    }
    Scores(double n)
    {
        if(N < 0) N = 0;
        else N = n;
    }
};

void setOutputFormat(ostream &os) {
    cout << fixed << showpoint << setprecision(4);
}

int main() {

	setOutputFormat(cout);

	int n;
	Scores *s;
	while(cin >> n) {

		s = new Scores(n);

		s->getScore(cin);
		s->printAverage(cout);
		s->printVariance(cout);

		delete s;
	}
}
