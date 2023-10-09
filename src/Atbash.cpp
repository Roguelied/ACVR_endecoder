#include "../ACVR.h"

string Atbash::encode(string Message) {
    to_upper(Message);
    string EncodedMessage;
    for (int ASCII_char : Message) {
        if (ASCII_char >= 'A' && ASCII_char <= 'Z') {
            EncodedMessage += RevAlpha[ASCII_char - 65];
        }
    }
    return EncodedMessage;
}

string Atbash::decode(string Message) {
    return encode(std::move(Message));
}

