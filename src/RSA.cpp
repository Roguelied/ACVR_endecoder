#include "../ACVR.h"


string RSA::encode(string Message, int p, int q) {

    if (!isPrime(p) or !isPrime(q) or (p == q)) {
        return "p or q is not prime";
    }
    int n = p * q;
    int fi = (p - 1) * (q - 1);

    // Public exponent
    int e = calc_e(fi); // reverse_calc_e(fi) for bigger nums

    // Private exponent
    int d = calc_d(e, fi); // для примера 1027,1643,2259,2875,3491

    string EncodedMessage;
    for (auto i : Message) {
        int c = modExp(i, e, n);
        EncodedMessage += (to_string(c) + ' ');
    }
    EncodedMessage += "  (d, n) = (" + to_string(d) + ", " + to_string(n) + ")\n";
    return EncodedMessage;
}


// String format "305 453 115 115 217 181 453"
string RSA::decode(const string & Message, int d, int n) {
    vector<string> MessageArray = split(Message, " ");
    string DecodedMessage;
    for (const auto & i : MessageArray) {
        unsigned long c = atoi(i.c_str());
        //cout << modExp(c, d, n) << ' ';
        long m = modExp(c, d, n);
        DecodedMessage += char(m);
    }
    return DecodedMessage;
}


int RSA::calc_e(int fi) {
    int e;
    for (e = 2; e < fi; e++) {
        // Find greatest common divisor
        if (gcd_recursive(e, fi) == 1 ) { return e; }
    }
    return -1;
}


// если надо посчитать максимально большую публичную экспоненту, меняем calc_e на эту функцию
// я не тестил с ней, числа станут больше и че нить может сломаться, нужно будет менять макс диапозон в
// польз интерфейсе и подгонять длину строки для расшифровки
int RSA::reverse_calc_e(int fi) {
    int e;
    for (e = fi-1; e > 2; e--) {
        // Find greatest common divisor
        if (gcd_recursive(e, fi) == 1 ) { return e; }
    }
    return -1;
}


int RSA::calc_d(int e, int fi) {

    int d;
    long int k = 1;
    while (true) {
        k = k + fi;
        if ( k % e == 0) {
            d = (k / e);
            return d;
        }
    }
}