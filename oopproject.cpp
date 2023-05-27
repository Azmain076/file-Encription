#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class FileEncryptor {
public:
    void encryptFile(const string& inputFile, const string& outputFile) {
     ifstream inFile(inputFile);
     ofstream outFile(outputFile);

        if (!inFile.is_open()) {
    cerr << "Error opening input file." <<endl;
            return;
        }

        if (!outFile.is_open()) {
           cerr << "Error opening output file." << endl;
            return;
        }

        char ch;
        while (inFile.get(ch)) {
            ch = encryptChar(ch);
            outFile << ch;
        }

        inFile.close();
        outFile.close();

      cout << "File encrypted successfully." << endl;
    }

    void decryptFile(const string& inputFile, const string& outputFile) {
       ifstream inFile(inputFile);
      ofstream outFile(outputFile);

        if (!inFile.is_open()) {
          cerr << "Error opening input file." << endl;
            return;
        }

        if (!outFile.is_open()) {
       cerr << "Error opening output file." << endl;
            return;
        }

        char ch;
        while (inFile.get(ch)) {
            ch = decryptChar(ch);
            outFile << ch;
        }

        inFile.close();
        outFile.close();

     cout << "File decrypted successfully." <<endl;
    }

private:
    char encryptChar(char ch) {
        // Perform encryption logic here
        // For example, you can shift the character by a fixed amount
        return ch + 1;
    }

    char decryptChar(char ch) {
        // Perform decryption logic here
        // For example, you can shift the character back by the same amount
        return ch - 1;
    }
};

int main() {
string inputFile, outputFile;
    int choice;

   cout << "Enter the name of the input file: ";
 cin >> inputFile;

cout << "Enter the name of the output file: ";
cin >> outputFile;

  cout << "Choose an option:\n1. Encrypt file\n2. Decrypt file\n";
   cout << "Enter your choice (1 or 2): ";
 cin >> choice;

    FileEncryptor encryptor;

    switch (choice) {
        case 1:
            encryptor.encryptFile(inputFile, outputFile);
            break;
        case 2:
            encryptor.decryptFile(inputFile, outputFile);
            break;
        default:
           cerr << "Invalid choice. Exiting." << endl;
            return 1;
    }

    return 0;
}
