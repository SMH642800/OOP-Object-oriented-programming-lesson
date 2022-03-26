#include <iostream>
#include <string>

using namespace std;

class romanType
{
private:
    string romanNum;
    int naturalNum;
public:
    void setRoman(string);
    void roman2Natural();
    int getNatural() const;
    string getRoman() const;
    romanType()
    {
        romanNum = "";
        naturalNum = -1;
    };
    romanType(string);
};

void romanType::setRoman(string roman)
{
    romanNum = roman;
    roman2Natural();
}

void romanType::roman2Natural()
{
    int numCount = 0;
    int length = getRoman().length();
    string roman = getRoman();
    for(int i = 0; i < length; i++){
        if(roman[i] == 'M') numCount += 1000;
        else if(roman[i] == 'D') numCount += 500;
        else if(roman[i] == 'C'){
            if(roman[i+1] == 'M' && i != length-1){numCount += 900; i++;}
            else if(roman[i+1] == 'D' && i != length-1){numCount += 400; i++;}
            else numCount += 100;
        }
        else if(roman[i] == 'L') numCount += 50;
        else if(roman[i] == 'X'){
            if(roman[i+1] == 'C' && i != length-1){numCount += 90; i++;}
            else if(roman[i+1] == 'L' && i != length-1){numCount += 40; i++;}
            else numCount += 10;
        }
        else if(roman[i] == 'V') numCount += 5;
        else if(roman[i] == 'I'){
            if(roman[i+1] == 'X' && i != length-1){numCount += 9; i++;}
            else if(roman[i+1] == 'V' && i != length-1){numCount += 4; i++;}
            else numCount += 1;
        }
    }

    naturalNum = numCount;
}

string romanType::getRoman() const
{
    return romanNum;
}

int romanType::getNatural() const
{
    return naturalNum;
}

romanType::romanType(string roman)
{
    romanNum = roman;
    roman2Natural();
}

int main() {

	romanType *roman;
	string str;

	for(int i = 0; cin >> str; i++) {

		if(i % 2) {

			roman = new romanType();
			roman->setRoman(str);

		} else {

			roman = new romanType(str);
		}

		cout << roman->getRoman() << " = " << roman->getNatural() << endl;
	}
}
