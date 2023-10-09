#include "../ACVR.h"


string Caesar::encode(string Message, int n) {

    if (n > size(Alpha) - 1) {
        n = n % (int(size(Alpha)) - 1);
    }

    string EncodedMessage;
    to_upper(Message);
    to_valid(Message);

    for (char ASCII_char : Message) {
        if (ASCII_char < 'A' or ASCII_char > 'Z') {
            EncodedMessage += ASCII_char;
            continue;
        }
        if (ASCII_char + n > 90) {
            EncodedMessage += char(int(ASCII_char + n - 65) % 26 + 65);
        } else {
            EncodedMessage += char(ASCII_char + n);
        }
    }
    return EncodedMessage;
}


string Caesar::decode(string Message) {

    string DecodedMessage;
    to_upper(Message);
    to_valid(Message);

    for (int n = 1; n < int(size(Alpha)); n++) {
        DecodedMessage += std::to_string(n) + ':';
        for (char ASCII_char : Message) {
            if (ASCII_char < 'A' or ASCII_char > 'Z') {
                DecodedMessage += ASCII_char;
                continue;
            }
            if (ASCII_char + n > 90) {
                DecodedMessage += char(ASCII_char + n - 90 + 64);
            } else {
                DecodedMessage += char(ASCII_char + n);
            }
        }
        DecodedMessage += " \n";
    }
    return DecodedMessage;
}
