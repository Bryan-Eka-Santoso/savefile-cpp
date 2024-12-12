#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void encrypt(string input, string output) {
        fstream myFile;
        fstream myFileEncrypt;
        string line;
        char y;
        myFileEncrypt.open(output, ios::out);
        myFile.open(input, ios::in);
        if (myFile.is_open()) {
            while(getline(myFile, line)) {
                for (int i = 0; i < line.length(); i++) {
                    char x = line[i];
                    if (x == 'Z') {
                        line[i] = 'A';
                        y = line[i];
                    } else if (x == 'z') {
                        line[i] = 'a';
                        y = line[i];
                    } else if (x >= 65 && x < 132) {
                        y = line[i] + 1;
                    } else if (x >= 97 && x < 122) {
                        y = line[i] + 1;
                    } else {
                        y = line[i];
                    }
                    myFileEncrypt << y;
                }
                myFileEncrypt << endl;
            }
            myFile.close();
            myFileEncrypt.close();
        }
}

void decrypt(string input, string output) {
        fstream decrypt;
        fstream fileDecrypt;
        string line;
        char y;
        decrypt.open(input, ios::in);
        fileDecrypt.open(output, ios::out);
        if (decrypt.is_open()) {
            while(getline(decrypt, line)) {
                 for (int i = 0; i < line.length(); i++) {
                    char x = line[i];
                    if (x == 'A') {
                        line[i] = 'Z';
                        y = line[i];
                    } else if (x == 'a') {
                        line[i] = 'z';
                        y = line[i];
                    } else if (x >= 65 && x < 132) {
                        y = line[i] - 1;
                    } else if (x >= 97 && x < 122) {
                        y = line[i] - 1;
                    } else {
                        y = line[i];
                    }
                    fileDecrypt << y;
                }
                fileDecrypt << endl;
            }
            decrypt.close();
            fileDecrypt.close();
        }
}

int main()
{
//    ofstream myFile;
//    myFile.open("han.txt", ios::out);
//    if (myFile.is_open()) {
//        myFile << "Hello Guys, this is the first Line\n";
//        myFile << "This is the second line, he he he\n";
//        myFile.close();
//    }

//        fstream myFile;
//        char line;
//        myFile.open("han.txt", ios::in);
//        if (myFile.is_open()) {
//            int counter = 0;
//            while(myFile >> line) {
//                cout << line << endl;
//                counter ++;
//            }
//            myFile.close();
//            cout << counter;
//        }

//        fstream myFile;
//        string line;
//        myFile.open("han.txt", ios::in);
//        if (myFile.is_open()) {
//            int counter = 0;
//            while(getline(myFile, line)) {
//                cout << line << endl;
//                counter ++;
//            }
//            myFile.close();
//            cout << counter;
//        }

//        fstream myFile;
//        char line;
//        myFile.open("han.txt", ios::in);
//        if (myFile.is_open()) {
//            int counter = 0;
//            while(myFile.get(line)) {
//                cout << line << endl;
//                counter ++;
//            }
//            myFile.close();
//            cout << counter;
//        }

//        fstream myFile;
//        fstream myFileEncrypt;
//        fstream decrypt;
//        fstream fileDecrypt;
//        string line;
//        char y;
//        myFileEncrypt.open("encrypt.txt", ios::out);
//        myFile.open("han.txt", ios::in);
//        if (myFile.is_open()) {
//            while(getline(myFile, line)) {
//                for (int i = 0; i < line.length(); i++) {
//                    char x = line[i];
//                    if (x == 'Z') {
//                        line[i] = 'A';
//                        y = line[i];
//                    } else if (x == 'z') {
//                        line[i] = 'a';
//                        y = line[i];
//                    } else if (x >= 65 && x < 132) {
//                        y = line[i] + 1;
//                    } else if (x >= 97 && x < 122) {
//                        y = line[i] + 1;
//                    } else {
//                        y = line[i];
//                    }
//                    myFileEncrypt << y;
//                }
//                myFileEncrypt << endl;
//            }
//            myFile.close();
//            myFileEncrypt.close();
//        }
//
//        cout << endl;
//
//        decrypt.open("encrypt.txt", ios::in);
//        fileDecrypt.open("decrypt.txt", ios::out);
//        if (decrypt.is_open()) {
//            while(getline(decrypt, line)) {
//                 for (int i = 0; i < line.length(); i++) {
//                    char x = line[i];
//                    if (x == 'A') {
//                        line[i] = 'Z';
//                        y = line[i];
//                    } else if (x == 'a') {
//                        line[i] = 'z';
//                        y = line[i];
//                    } else if (x >= 65 && x < 132) {
//                        y = line[i] - 1;
//                    } else if (x >= 97 && x < 122) {
//                        y = line[i] - 1;
//                    } else {
//                        y = line[i];
//                    }
//                    fileDecrypt << y;
//                }
//                fileDecrypt << endl;
//            }
//            decrypt.close();
//            fileDecrypt.close();
//        }
    int pilihan = 1;
    while (pilihan != 0) {
        cout << "Menu" << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "0. Exit" << endl;
        do {
            cout << ">> "; cin >> pilihan;
        } while (pilihan < 0 || pilihan > 2);

        if (pilihan == 1) {
            cout << endl;
            string input, output;
            cout << "Encrypt" << endl;
            cout << "Input file: "; cin >> input;
            cout << "Output file: "; cin >> output;
            encrypt(input, output);
        } else if (pilihan == 2) {
            cout << endl;
            string input, output;
            cout << "Decrypt" << endl;
            cout << "Input file: "; cin >> input;
            cout << "Output file: "; cin >> output;
            decrypt(input, output);
        }

    }

    return 0;
}
