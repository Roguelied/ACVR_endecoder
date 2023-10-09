#include "ACVR.h"


void to_upper(string & str) {
    for (auto & c: str) c = toupper(c);
}


void to_valid(string & str) {
    for (int i = 0; i < str.length(); i++) {
        if ((str[i] < 'A' or str[i] > 'Z') and (str[i] < 'a' or str[i] > 'z')) {
            str.erase(i, 1);
        }
    }
}


unsigned long gcd_recursive(unsigned a, unsigned b) {
    if (b)
        return gcd_recursive(b, a % b);
    else
        return a;
}


bool isPrime(int n) {
    if (n <= 1) { return false; }

    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) { return false; }
    }
    return true;
}


vector<string> split(string str, string delimiter)
{
    vector<string> v;
    if (!str.empty()) {
        int start = 0;
        do {
            int index = str.find(delimiter, start);
            if (index == string::npos) {
                break;
            }

            int length = index - start;
            v.push_back(str.substr(start, length));
            start += (length + delimiter.size());
        } while (true);
        v.push_back(str.substr(start));
    }
    return v;
}

//modPow
int modExp(int a, int b, int n) {
    long long x=1, y=a;
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n;
        }
        y = (y*y) % n;
        b /= 2;
    }
    return x % n;
}

bool in(char sym, string Alphabet) {

    for (char i : Alphabet) {
        if (i == sym) {
            return true;
        }
    }

    return false;
}

string input(string Alphabet, int n) {
    string buffer;
    char sym;
    int c = 0;

    do {
        sym = (char) getch();

        if (sym == VK_BACK and !buffer.empty()) {
            putch(VK_BACK);
            putch(VK_SPACE);
            putch(VK_BACK);
            buffer.pop_back();
            c--;
        }
        else if (in(sym, Alphabet) and c != n)  {
            c++;
            buffer += sym;
            putch(sym);
        }

    } while (sym != VK_RETURN);

    return buffer;
}

int int_check(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ' || isdigit(str[i]) == 0) { return 0; }
    }
    return 1;
}