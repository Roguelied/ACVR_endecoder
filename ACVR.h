#ifndef ACVR_ENDECODER_ACVR_H
#define ACVR_ENDECODER_ACVR_H

#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <windows.h>
#include <conio.h>

using std::string, std::cout, std::cin, std::size, std::vector, std::to_string, std::any_of;

#define NonNumAlpha "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
#define ValidAlpha "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abcdefghijklmnopqrstuvwxyz+%|/=_-{}[];:.><,)(*&?^$#@!"
#define RSAdecrypt "1234567890 "
#define Alpha "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define RevAlpha "ZYXWVUTSRQPONMLKJIHGFEDCBA"
#define OnlyNums "1234567890"


// ACVR.cpp
void to_upper(string & str);
void to_valid(string & str);
unsigned long gcd_recursive(unsigned a, unsigned b);
bool isPrime(int a);
vector<string> split(string str, string delimiter);
int modExp(int a, int b, int n);
int modinv(int u, int v);
string input(string Alphabet, int n);
int int_check(string str);


// Atbash.cpp
class Atbash {
public:
    static string encode(string Message);
    static string decode(string Message);
};


// Caesar.cpp
class Caesar {
public:
    static string encode(string Message, int n);
    static string decode(string Message);
};


// Vigenere.cpp
class Vigenere {
private:
    static void size_match(string & str, const string& str1);

public:
    static string encode(string Message, string Key);
    static string decode(string Message, string Key);
};


// RSA.cpp
class RSA {
private:
    static int calc_d(int e, int fi);
    static int calc_e(int fi);
    static int reverse_calc_e(int fi);

public:
    static string encode(string Message, int p, int q);
    static string decode(const string& Message, int d, int n);

};



#endif //ACVR_ENDECODER_ACVR_H
