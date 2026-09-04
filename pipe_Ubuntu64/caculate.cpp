#include "head_files.h"
#include <iostream>

using namespace std;

int caculate(const string& expr) {  
    int pos = 0;
    int a = 0, b = 0;
    char op = '+'; 

    if ((pos = expr.find('+')) != string::npos) { op = '+'; }
    else if ((pos = expr.find('-')) != string::npos) { op = '-'; }
    else if ((pos = expr.find('*')) != string::npos) { op = '*'; }
    else if ((pos = expr.find('/')) != string::npos) { op = '/'; }
    else {
        cout << "不支持的操作符！" << endl;
        return 0;
    }

    a = stoi(expr.substr(0, pos));
    b = stoi(expr.substr(pos + 1));

    if (op == '/') {
        if (b == 0) {
            cout << "错误：除数不能为 0！" << endl;
            return 0;
        }
        return a / b;
    }

    return (op == '+') ? a + b :
        (op == '-') ? a - b :
        (op == '*') ? a * b : 0;
}