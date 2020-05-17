#include <iostream>
#include <cmath>
#include <cctype>  
#include <string>
#include <windows.h>
#include <iomanip>
#define DOT '.'
#define MINUS '-'

using namespace std;

float checkinput(string call);

int main() {

    SetConsoleOutputCP(CP_UTF8);

    float a, b, k;

    a = 0.75 * (double)pow(0.5, 1.0/2) - pow(4, 1.0/3) * 1/2;

    b = pow(100, (log(9) / 2 - log10(2))) * tan(1.0/3);

    if (a > b)
        k = sqrt(15 * pow(a, 2.0) + 21 * pow(b, 2.0));

    else
        k = sqrt(15 * pow(b, 2.0) + 21 * pow(a, 2.0));

    cout << "Часть 1" << "\na = " << fixed << setprecision(3) << a << " = " << scientific << a << endl;
    cout << "b = " << fixed << b << " = " << scientific << b << endl;
    cout << "k = " << fixed << k << " = " << scientific << k << endl;

    ///////////////// Часть 2

    cout << "\nЧасть 2" << endl;
    
    string call = "Введите значение x: ";
    float x = checkinput(call);

    call = "Введите значение y: ";
    float y = checkinput(call);

    call = "Введите значение z: ";
    float z = checkinput(call);


    cout << "\nx = " << fixed << setprecision(3) << x << " = " << scientific << x << endl;

    cout << "y = " << fixed << y << " = " << scientific << y << endl;

    cout << "z = " << fixed << z << " = " << scientific << z << endl;


    a = 2 * cos(x - M_PI/6) / (1.0/2 + pow(sin(y), 2.0));

    b = 1 + pow(z, 2.0) / (3 + pow(z, 2.0)/5);

    cout << "\na = " << fixed << a << " = " << scientific << a << endl;
    cout << "b = " << fixed << b << " = " << scientific << b << endl;


    system("pause");
    return 0;
}

////////////// FUNCTIONS

float checkinput (string call) {
    string str;
    int count = 0;
    int count_dot = 0;
    int count_minus = 0;
    bool flag = true;
    bool flag_dot = false;
    bool flag_minus = false;
    bool correct = false;

    do {
        cout << call;
        cin >> str;
        for (int i = 0; i < (int) str.length(); i++) {
            if (str[i] == DOT) {
                count_dot++;
                flag_dot = true;
            }
            if (str[i] == MINUS) {
                flag_minus = true;
                count_minus++;
            }
            if (((!isdigit(str[i])) && (!flag_dot) && (!flag_minus)) || (count_dot >= 2)) {
                cout << "Введено не число, попробуйте еще раз" << endl;
                cin.ignore(10000, '\n');
                flag = true;
                break;
            }
            else
                count++;
        }
        if ((((count == (int) str.length()) && (atof(str.c_str()) > -9223372036854775808.0) &&
              (atoi(str.c_str()) < 9223372036854775807.0))) || ((count_minus == 1) &&
              (((int(count + 1) == (int) str.length()) && (atof(str.c_str()) > -9223372036854775808.0) &&
              (atoi(str.c_str()) < 9223372036854775807.0))))) {
            correct = true;
        }
        else if (flag) {
            correct = false;
        }
    } while (correct == false);

    float input = stof(str);

    return input;

}
