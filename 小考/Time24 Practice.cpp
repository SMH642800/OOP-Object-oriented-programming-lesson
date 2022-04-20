#include <iostream>
#include <string>

using namespace std;

class Time24 {
public:
    void setTime(int h, int m, int s)
    {
        if(h>=0 && h<24){
            if(m>=0 && m<60){
                if(s>=0 && s<60){
                    hr = h;
                    min = m;
                    sec = s;
                }
                else{
                    hr = 0;
                    min = 0;
                    sec = 0;
                }
            }
            else{
                hr = 0;
                min = 0;
                sec = 0;
            }
        }
        else{
            hr = 0;
            min = 0;
            sec = 0;
        }
    }

    void displayTimeIn24Hour()
    {
        if(hr<10) cout << "0";
        cout << hr << ":";
        if(min<10) cout << "0";
        cout << min << ":";
        if(sec<10) cout << "0";
        cout << sec << endl;
    }

    void displayTimeIn12Hour()
    {
        if(hr>12){
            hr -=12;
            if(hr<10) cout << "0";
            cout << hr << ":";
            if(min<10) cout << "0";
            cout << min << ":";
            if(sec<10) cout << "0";
            cout << sec << " PM" << endl;

            hr += 12;
        }
        else if(hr == 12){
            cout << hr << ":";
            if(min<10) cout << "0";
            cout << min << ":";
            if(sec<10) cout << "0";
            cout << sec << " PM" << endl;
        }
        else if(hr == 0){
            hr += 12;
            cout << hr << ":";
            if(min<10) cout << "0";
            cout << min << ":";
            if(sec<10) cout << "0";
            cout << sec << " AM" << endl;
            hr -= 12;
        }
        else{
            if(hr<10) cout << "0";
            cout << hr << ":";
            if(min<10) cout << "0";
            cout << min << ":";
            if(sec<10) cout << "0";
            cout << sec << " AM" << endl;
        }
    }

    void displayGreeting()
    {
        if(hr>=6 && hr<12) cout << "Good Morning" << endl;
        else if(hr>=12 && hr<18) cout << "Good Afternoon" << endl;
        else if(hr>=18 && hr<23) cout << "Good Evening" << endl;
        else if(hr>=23 || hr<6) cout << "Time to Sleep" << endl;
    }

private:
    int hr, min, sec;
};

int main() {

	Time24 time24;
	int h, m, s;

	while(cin >> h >> m >> s) {
		time24.setTime(h, m, s);
		time24.displayTimeIn24Hour();
		time24.displayTimeIn12Hour();
		time24.displayGreeting();
	}
}
