#include <iostream>
#include <string>
using namespace std;

int RNToDecimal (string userRomanNumeral){
    const int I= 1;
    const int V = 5;
    const int X = 10;
    const int L = 50;
    const int C = 100;
    const int D = 500;
    const int M = 1000;

    int totalDec = 0;
    for (int i; i < userRomanNumeral.size(); i++){

       if (userRomanNumeral.at(i) == 'M'){
           totalDec += M;
       }
       else if (userRomanNumeral.at(i) == 'D'){
           totalDec += D;
       }
       else if (userRomanNumeral.at(i) == 'C'){
          /* if (userRomanNumeral.at(i + 1) == 'D' || userRomanNumeral.at(i + 1) == 'M'){
               totalDec -= C;
           }*/
           totalDec += C;
       }
       else if (userRomanNumeral.at(i) == 'L'){
           totalDec += L;
       }
       else if (userRomanNumeral.at(i) == 'X'){
          /*if (userRomanNumeral.at(i + 1) == 76 || userRomanNumeral.at(i + 1) == 67){
               totalDec -= X;
           }*/
          totalDec += X;
       }
       else if (userRomanNumeral.at(i) == 'V'){
           totalDec += V;
       }
       else if (userRomanNumeral.at(i) == 'I'){
          /* if (userRomanNumeral.at(i + 1) == 86 || userRomanNumeral.at(i + 1) == 88){
               totalDec--;
           }*/
           totalDec++;
       }
    }
    return totalDec;
}

 int Thousands (int& userNum) {
        int thousands = 0;
        if (userNum >= 1000) {
           thousands = userNum / 1000;
            userNum = userNum % 1000;
        }
        return thousands;
    }
int FiveHundreds (int& userNum) {
    int fiveHundreds = 0;
    if (userNum >= 500 && userNum != 900 && userNum != 990 && userNum != 999) {
        fiveHundreds = userNum / 500;
        userNum = userNum % 500;
    }
    return fiveHundreds;
}
int Hundreds (int& userNum) {
    int hundreds = 0;
    if (userNum >= 100) {
        hundreds = userNum / 100;
        userNum = userNum % 100;
    }
    return hundreds;
}
int Fifties (int& userNum) {
    int fifties = 0;
    if (userNum >= 50 && userNum != 90 && userNum != 99) {
        fifties = userNum / 50;
        userNum = userNum % 50;
    }
    return fifties;
}
int Tens (int& userNum) {
    int tens = 0;
    if (userNum >= 10) {
        tens = userNum / 10;
        userNum = userNum % 10;
    }
    return tens;
}
int Fives (int& userNum) {
    int fives = 0;
    if (userNum >= 5 && userNum !=9) {
        fives = userNum / 5;
        userNum = userNum % 5;
    }
    return fives;
}
int Ones (int& userNum) {
    int ones = 0;
    if (userNum >= 1) {
        ones = userNum;

        return ones;
    }
}

void DecimalToRN(int thousands, int fiveHundreds, int hundreds, int fifties, int tens, int fives, int ones){
     if (thousands != 0){
         for(int i =0; i < thousands; i++){
             cout << "M";
         }
     }
    if (fiveHundreds != 0){
        for(int i =0; i << fiveHundreds; i++){
            cout << "D";
        }
    }
    if (hundreds != 0){
        if (hundreds == 4){
            cout << "CD";
        }
        else if (hundreds == 9){
            cout << "CM";
        }
        else {for(int i =0; i < hundreds; i++) {
                cout << "C";
            }
        }
    }
    if (fifties != 0){
        for(int i =0; i < fifties; i++){
            cout << "L";
        }
    }
    if (tens != 0){
        if (tens == 4) {
            cout << "XL";
        }
        else if (tens == 9) {
            cout << "XC";
        }
        else { for ( int i =0; i < tens; i++) {
                cout << "X";
            }
        }
    }
    if (fives != 0){
        for(int i =0; i < fives; i++){
            cout << "V";
        }
    }
    if (ones != 0){
        if (ones == 4) {
            cout << "IV";
        }
        else if (ones == 9){
            cout << "IX";
        }
        else {for(int i =0; i < ones; i++) {
                cout << "I";
            }
        }
    }
 }

int main() {
    int userNum;
    char whichConversion;
    cout << "Hello! Welcome to the Roman Numeral converter! Would you like to" << endl;
    cout << "a: Convert a decimal to a Roman Numeral" << endl;
    cout << "b: Convert a Roman Numeral to a decimal" << endl;
    cin >> whichConversion;
    if (whichConversion == 'a' || whichConversion == 'A'){
        cout << "Enter a number (0 to quit): ";
        while (userNum != 0) {
            cin >> userNum;
            int thousands = Thousands(userNum);
            int fiveHundreds = FiveHundreds(userNum);
            int hundreds = Hundreds(userNum);
            int fifties = Fifties(userNum);
            int tens = Tens(userNum);
            int fives = Fives(userNum);
            int ones = Ones(userNum);

            DecimalToRN(thousands, fiveHundreds, hundreds, fifties, tens, fives, ones);
            cout << endl;
        }
    }
    else if (whichConversion == 'b' || whichConversion == 'B') {
        string userRomanNumeral;
        cout << "Enter a Roman Numeral (\"q\" to quit) : ";
        while (userRomanNumeral != "q") {
            cin >> userRomanNumeral;

            cout << RNToDecimal(userRomanNumeral) << endl;
        }
    }
    else {cout << "Invalid input. Goodbye :)";}

    return 0;
}
