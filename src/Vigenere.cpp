#include "../ACVR.h"


void Vigenere::size_match(string & Key, const string& Message) {
    while (Key.length() != Message.length()) {
        if (Key.length() < Message.length()) {
            Key += Key;
        } else if (Key.length() > Message.length()) {
            Key.pop_back();
        }
    } // Key is now same length as Message
}


string Vigenere::encode(string Message, string Key) {

    string EncodedMessage;
    to_valid(Message);
    to_valid(Key);
    to_upper(Message);
    to_upper(Key);
    size_match(Key, Message);

    for (int i = 0; i < Message.length(); i++) {
        EncodedMessage += char((Message[i] + Key[i]) % (size(Alpha)-1) + 65);
    }
    return EncodedMessage;
}


string Vigenere::decode(string Message, string Key) {

    string DecodedMessage;
    to_upper(Key);
    to_upper(Message);
    to_valid(Message);
    to_valid(Key);
    size_match(Key, Message);

    for (int i = 0; i < Message.length(); i++) {
        if ((Message[i] - Key[i]) >= 0) {
            DecodedMessage += char((Message[i] - Key[i]) % (size(Alpha) - 1) + 65);
        } else {
            DecodedMessage += char(91 - ((Key[i] - Message[i]) % (size(Alpha) - 1)));
        }
    }
    return DecodedMessage;
}


