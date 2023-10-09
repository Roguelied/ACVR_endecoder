#include <iostream>
#include "ACVR.h"

/*
    cout << Atbash::encode("Message") << "\n";
    cout << Atbash::decode(Atbash::encode("Message")) << "\n";

    cout << Caesar::encode("Message", 3) << '\n';
    cout << Caesar::decode("Message") << '\n';

    cout << Vigenere::encode("Message", "Key") << '\n';
    cout << Vigenere::decode("wiqceeo", "Key") << '\n';

    cout << RSA::encode("Message", 23, 29);
    cout << RSA::decode("305 453 115 115 217 181 453", 411, 667) << "\n";
*/

int main() {
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    while (true) {
        cout << "Choose cryptography method: \n1) Atbash\n2) Caesar\n3) Vigenere\n4) RSA\n";
        string str;
        str = input(OnlyNums, 1);
        system("cls");
        if (str == "1") {
            system("cls");
            cout << "Atbash encryption/decryption\n";
            cout << "Enter your message (Should only contain alphabet symbols, anything else will be ignored, maximum 50 symbols)\n";
            fflush(stdin);
            SetConsoleTextAttribute(h, 2); //green
            str = input(NonNumAlpha, 50);
            SetConsoleTextAttribute(h, 15); //white
            cout << "\nEncrypted message: ";
            SetConsoleTextAttribute(h, 14); //red
            cout << Atbash::encode(str) + "\n";
            SetConsoleTextAttribute(h, 15); //white
            cout << "Press any key to continue\n";
            system("pause >nul");
            system("cls");
            fflush(stdin);
        }
        if (str == "2") {
            cout << "Caesar\n1) Encrypt\n2) Decrypt\n";
            str = input(OnlyNums, 1);
            if (str == "1") {
                system("cls");
                cout << "Caesar encryption\n";
                cout << "Enter your message (Should only contain alphabet symbols, anything else will be ignored)\n";
                SetConsoleTextAttribute(h, 2);
                str = input(NonNumAlpha, 50);
                SetConsoleTextAttribute(h, 15);
                fflush(stdin);

                string str1;
                while (true) {
                    cout << "\nEnter amount of shift iterations\n";
                    SetConsoleTextAttribute(h, 2);
                    str1 = input(OnlyNums, 3);
                    if (int_check(str1)) {
                        break;
                    } else {
                        SetConsoleTextAttribute(h, 15);
                        cout << "\nWrong format, try again";
                        continue;
                    }
                }
                int n = std::atoi(str1.c_str());

                SetConsoleTextAttribute(h, 15);
                cout << "\nEncrypted message - ";
                SetConsoleTextAttribute(h, 14);
                cout << Caesar::encode(str, n) + '\n';
                SetConsoleTextAttribute(h, 15);
                cout << "Press any key to continue\n";
                system("pause >nul");
                fflush(stdin);
            }
            if (str == "2") {
                system("cls");
                cout << "Caesar decryption\n";
                cout << "Enter message to encrypt (Should only contain alphabet symbols, anything else will be ignored)\n";
                SetConsoleTextAttribute(h, 2);
                str = input(NonNumAlpha, 50);
                SetConsoleTextAttribute(h, 15);
                cout << "\nAll encrypted variations:\n";
                SetConsoleTextAttribute(h, 14);
                cout << Caesar::decode(str) + '\n';
                SetConsoleTextAttribute(h, 15);
                cout << "Press any key to continue\n";
                system("pause >nul");
                fflush(stdin);
            } else {
                system("cls");
                fflush(stdin);
                continue;
            }
        }
        if (str == "3") {
            cout << "Vigenere\n1) Encrypt\n2) Decrypt\n";
            str = input(OnlyNums, 1);
            if (str == "1") {
                system("cls");
                cout << "Vigenere encryption\n";
                cout << "Enter message to encrypt (Anything except alphabet symbols will be ignored, max 50 symbols):\n";
                SetConsoleTextAttribute(h, 2);
                str = input(NonNumAlpha, 50);
                SetConsoleTextAttribute(h, 15);
                cout << "\nEnter encryption key (Key with length more than message will be fetch to message length):\n";
                SetConsoleTextAttribute(h, 2);
                string str1 = input(NonNumAlpha, 50);
                SetConsoleTextAttribute(h, 15);
                cout << "\nEncrypted message - ";
                SetConsoleTextAttribute(h, 14);
                cout << Vigenere::encode(str, str1) + '\n';
                SetConsoleTextAttribute(h, 15);
                cout << "Press any key to continue\n";
                system("pause >nul");
                fflush(stdin);
            }
            if (str == "2") {
                system("cls");
                cout << "Vigenere decryption\n";
                cout << "Enter message to decrypt (Anything except alphabet symbols will be ignored, max 50 symbols):\n";
                SetConsoleTextAttribute(h, 2);
                str = input(NonNumAlpha, 50);
                SetConsoleTextAttribute(h, 15);
                cout << "\nEnter decryption key (Key with length more than message will be fetch to message length):\n";
                SetConsoleTextAttribute(h, 2);
                string str1 = input(NonNumAlpha, 50);
                SetConsoleTextAttribute(h, 15);
                cout << "\nDecrypted message - ";
                SetConsoleTextAttribute(h, 14);
                cout << Vigenere::decode(str, str1) + '\n';
                SetConsoleTextAttribute(h, 15);
                cout << "Press any key to continue\n";
                system("pause >nul");
                fflush(stdin);
                system("cls");
            }
            else {
                fflush(stdin);
                system("cls");
                continue;
            }
        }
        if (str == "4") {
            cout << "RSA\n1) Encrypt\n2) Decrypt\n";
            str = input(ValidAlpha, 1);
            if (str == "1") {
                system("cls");
                cout << "RSA encryption\n";
                cout << "Enter message to encrypt (max 50 symbols):\n";
                SetConsoleTextAttribute(h, 2);
                str = input(ValidAlpha, 50);
                SetConsoleTextAttribute(h, 15);
                string str1; string str2;
                int p, q;

                while (true) {
                    cout << "\nEnter prime number p:\n";
                    SetConsoleTextAttribute(h, 2);
                    str1 = input(OnlyNums, 3);
                    SetConsoleTextAttribute(h, 15);

                    while (true) {
                        if (!isPrime(atoi(str1.c_str()))) {
                            cout << "\n" + str1 + " is not prime, try again\n";
                            str1 = input(OnlyNums, 3);
                        } else { break; }
                    }

                    cout << "\nEnter prime number q:\n";
                    SetConsoleTextAttribute(h, 2);
                    str2 = input(OnlyNums, 3);
                    SetConsoleTextAttribute(h, 15);

                    while (true) {
                        if (!isPrime(atoi(str2.c_str()))) {
                            cout << "\n" + str2 + " is not prime, try again\n";
                            str2 = input(OnlyNums, 3);
                        } else { break; }
                    }

                    p = atoi(str1.c_str());
                    q = atoi(str2.c_str());

                    if (p * q < 130) {
                        SetConsoleTextAttribute(h, 4);
                        cout << "\nPublic key is to low to cover all ASCII characters, try bigger numbers";
                        SetConsoleTextAttribute(h, 15);
                        continue;
                    } else {break;}
                }

                cout << "\nPublic key = (" + str1 + ", " + str2 + ")\n";

                cout << "Encoded message - ";
                SetConsoleTextAttribute(h, 14);
                cout << RSA::encode(str, p, q) + '\n';
                SetConsoleTextAttribute(h, 15);
                cout << "Press any key to continue\n";
                system("pause >nul");
                fflush(stdin);
                system("cls");
            }
            if (str == "2") {
                system("cls");
                cout << "RSA decryption\n";
                cout << "Enter message to decrypt (max 50 symbols):\n";
                SetConsoleTextAttribute(h, 2);
                str = input(RSAdecrypt, 350);
                SetConsoleTextAttribute(h, 15);
                string str1; string str2;
                int d, n;

                cout << "\nEnter d:\n";
                SetConsoleTextAttribute(h, 2);
                str1 = input(OnlyNums, 10);
                SetConsoleTextAttribute(h, 15);

                cout << "\nEnter n:\n";
                SetConsoleTextAttribute(h, 2);
                str2 = input(OnlyNums, 10);
                SetConsoleTextAttribute(h, 15);


                d = atoi(str1.c_str());
                n = atoi(str2.c_str());

                cout << "\nDecoded message - ";
                SetConsoleTextAttribute(h, 14);
                cout << RSA::decode(str, d, n) + '\n';
                SetConsoleTextAttribute(h, 15);
                cout << "Press any key to continue\n";
                system("pause >nul");
                fflush(stdin);
                system("cls");

            } else {
                fflush(stdin);
                system("cls");
                continue;
            }
        }
        else {
            system("cls");
            fflush(stdin);
            continue;
        }
    }
}
