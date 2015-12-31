//================================================================
//  PROGRAMMER  : 潘廣霖
//  DATE        : 2015-12-30
//  FILENAME    : HW07B002.CPP
//  DESCRIPTION : A naive, OOP fraction calculator
//================================================================

// #ifdef _MSC_VER
// #include "stdafx.h"
// #endif // _MSC_VER

#include<iostream>
#include<iomanip>
#include<sstream>
#include<cstdlib>
#include<cmath>

using namespace std;

// you can switch to long long here easily
typedef int INTEGER;

INTEGER gcd(INTEGER a, INTEGER b) {
    return a ? gcd(b % a, a) : abs(b);
}

class Fractions {
public:
    Fractions() { num = 0; denom = 1; }
    Fractions(INTEGER n, INTEGER d) {
        if (d == 0) throw false;
        num = n;
        denom = d;
        normalize();
    }
    friend ostream& operator << (ostream&, const Fractions&);
    
    Fractions operator + (Fractions rhs) {
        INTEGER d = gcd(denom, rhs.denom);
        return Fractions(rhs.denom / d * num + denom / d * rhs.num, denom / d * rhs.denom);
    }
    Fractions operator - (Fractions rhs) {
        INTEGER d = gcd(denom, rhs.denom);
        return Fractions(rhs.denom / d * num - denom / d * rhs.num, denom / d * rhs.denom);
    }
    Fractions operator * (Fractions rhs) {
        // TODO: avoid overflow
        return Fractions(num * rhs.num, denom * rhs.denom);
    }
    Fractions operator / (Fractions rhs) {
        // TODO: avoid overflow
        INTEGER n = denom * rhs.num;
        if (n == 0) throw false;
        return Fractions(num * rhs.denom, n);
    }
private:
    int num;
    int denom;
   
    void normalize() {
        int g = gcd(num, denom);
        num /= g;
        denom /= g;
        // take negative sign to the numerator
        if (denom < 0) {
            num *= -1;
            denom *= -1;
        }
    }
};

ostream& operator << (ostream& os, const Fractions& f) {
    if (f.denom == 1) {
        // avoid fractions like (2/1), they are integers
        os << f.num;
        return os;
    }
    os << "(" << f.num << "/" << f.denom << ")";
    return os;
}

inline bool isValidOp(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

void printHeader() {
    cout << "========= FRACTION CALCULATOR =========" << endl;
    cout << "Syntax: <fraction> [<op> <fraction>]" << endl;
    cout << "Input '?' for more details." << endl;
    cout << "=======================================" << endl;
    cout << endl;
}

void printUsage() {
    cout << "=============================================" << endl;
    cout << "Grammar:" << endl;
    cout << " <fraction>: <INT> ['/' <INT>]" << endl;
    cout << "       <op>: '+' | '-' | '*' | '/'" << endl;
    cout << "Examples:" << endl;
    cout << "  \"1/3+2/5\": (1/3) + (2/5) => (11/15)" << endl;
    cout << "  \"-3/4-4\": (-3/4) - (4/1) => (-19/4)" << endl;
    cout << "  \"6/2/2/1\": (6/2) / (2/1) => (3/2)" << endl;
    cout << "  \"7/0\": error, divided by zero!!" << endl;
    cout << "  \"7/2/0/1\": (7/2) / (0/1) => error!!" << endl;  
    cout << "Notes:" << endl;  
    cout << "  * Never divide with zero. Never." << endl;
    cout << "  * The input format is different from common" << endl;
    cout << "    expressions in real life." << endl;
    cout << "=============================================" << endl;
    cout << endl;
}

bool parseError(stringstream& ss, string errMessage, int offset = 0) {
    ss.clear();
    int colNo = (int) ss.tellg();
    if (colNo <= 0) colNo = 1;
    colNo += offset;
    cerr 
    //   << ss.str() << endl
         << setw(colNo) << right << "^" << endl
         << "Parse error: col #" << colNo << ", " << errMessage << endl;
    return false;
}

bool inputOperator(stringstream& s, char& op) {
    s >> op;
    if (s.fail()) {
        op = '\0';
        return true;
    }
    if (!isValidOp(op))
        return parseError(s, "invalid operator!!");
    return true;
}

bool inputFraction(stringstream& s, INTEGER& x, INTEGER& y) {
    s >> x;
    if (s.fail() && s.eof())
        return parseError(s, "numerator expected!!");        
    if (s.fail())
        return parseError(s, "invalid numerator!!");
    
    char c;
    s >> c;
    if (c != '/') {
        y = 1;
        s.unget();
        return true;
        //return parseError(s, "\"/\" expected for a fraction!!");
    }
    
    s >> y;
    if (s.fail() && s.eof()) 
        return parseError(s, "denominator expected!!", 1);
    if (s.fail())
        return parseError(s, "invalid denominator!!", 1);
        
    if (y == 0)
        return parseError(s, "zero cannot be a denominator!!");
    
    return true;
}

bool parseCommand(string l, Fractions*& fr1, Fractions*& fr2, char& op) {
    INTEGER a, b;
    stringstream ss(l);
    
    if (!inputFraction(ss, a, b)) return false;
    fr1 = new Fractions(a, b);
    
    if (!inputOperator(ss, op)) return false;
    if (!op) return true;
    
    if (!inputFraction(ss, a, b)) return false;
    fr2 = new Fractions(a, b);
    
    // ensure no extra character
    char tmp;
    ss >> tmp;
    if (!ss.fail()) return parseError(ss, "extra character!!");
    return true;
}

#ifdef _MSC_VER
int main(int argc, _TCHAR* argv[]) {
#else
int main() {
#endif // _MSC_VER
    char op;
    
    Fractions* fr1 = 0;
    Fractions* fr2 = 0;
    Fractions ans;
    
    printHeader();
    string l;
    while (getline(cin, l)) {
    
        if (l == "?") {
            printUsage();
            continue;
        }
    
        if (!parseCommand(l, fr1, fr2, op)) {
            cout << endl;
            continue;
        }
        
        if (op == '\0') {
            cout << "Input:  " << *fr1 << endl;
        } else {
            if (op == '+')
                ans = *fr1 + *fr2;
            else if (op == '-')
                ans = *fr1 - *fr2;
            else if (op == '*')
                ans = *fr1 * *fr2;
            else if (op == '/')
                try {
                    ans = *fr1 / *fr2;
                } catch (bool b) {
                    cout << "Exception: cannot divided by zero!!" << endl;
                    cout << endl;
                    continue;
                }
    
            cout << "Input:  " << *fr1 << " " << op << " " << *fr2 << endl;
            cout << "Result: " << ans << endl;
        }
        
        // empty line for each line of input
        cout << endl;
        
        // recycle
        delete fr1; fr1 = 0;
        delete fr2; fr2 = 0;
    }
}

