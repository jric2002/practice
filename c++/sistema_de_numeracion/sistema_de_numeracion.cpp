#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <cmath>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
string decimalToBinary(int);
int binaryToDecimal(string);
string decimalToOctal(int);
int octalToDecimal(string);
string decimalToHexadecimal(int);
int hexadecimalToDecimal(string);
int main() {
  int option;
  string binary, octal, hexadecimal;
  int decimal;
  do {
    cout << "Operations" << endl;
    cout.fill('-');
    cout.width(10);
    cout << "" << endl;
    cout << "1. Decimal to Binary." << endl;
    cout << "2. Binary to Decimal." << endl;
    cout << "3. Decimal to Octal." << endl;
    cout << "4. Octal to Decimal." << endl;
    cout << "5. Decimal to Hexadecimal." << endl;
    cout << "6. Hexadecimal to Decimal." << endl;
    cout << "0. Exit." << endl;
    cout << "Choose an option: ";
    cin >> option;
    switch (option) {
      case 1:
        cout << "Enter a decimal: ";
        cin >> decimal;
        cout << "The decimal " << decimal << " in binary is: " << decimalToBinary(decimal) << endl;
        break;
      case 2:
        cout << "Enter a binary: ";
        cin >> binary;
        cout << "The binary " << binary << " in decimal is: " << binaryToDecimal(binary) << endl;
        break;
      case 3:
        cout << "Enter a decimal: ";
        cin >> decimal;
        cout << "The decimal " << decimal << " in octal is: " << decimalToOctal(decimal) << endl;
        break;
      case 4:
        cout << "Enter an octal: ";
        cin >> octal;
        cout << "The octal " << octal << " in decimal is: " << octalToDecimal(octal) << endl;
        break;
      case 5:
        cout << "Enter a decimal: ";
        cin >> decimal;
        cout << "The decimal " << decimal << " in hexadecimal is: " << decimalToHexadecimal(decimal) << endl;
        break;
      case 6:
        cout << "Enter a hexadecimal: ";
        cin >> hexadecimal;
        cout << "The hexadecimal " << hexadecimal << " in decimal is: " << hexadecimalToDecimal(hexadecimal) << endl;
        break;
      case 0:
        cout << "Leaving the program :)" << endl;
        break;
      default:
        cout << "That option doesn't exist...xD" << endl;
        break;
    }
    cout << endl;
    /* cin.ignore();
    cin.get();
    system("cls"); */
  } while (option != 0);
  return 0;
}
/* Definition */
string decimalToBinary(int decimal) {
  string binary("");
  while (decimal >= 2) {
    binary += to_string(decimal % 2);
    decimal /= 2;
  }
  binary += to_string(decimal);
  reverse(binary.begin(), binary.end());
  return binary;
}
int binaryToDecimal(string binary) {
  char digit;
  int decimal = 0;
  for (int i = 0; i < binary.size(); i++) {
    digit = binary.at(binary.size() - (i + 1));
    decimal = decimal + (atoi(&digit) * pow(2, i));
  }
  return decimal;
}
string decimalToOctal(int decimal) {
  string octal("");
  while (decimal >= 8) {
    octal += to_string(decimal % 8);
    decimal /= 8;
  }
  octal += to_string(decimal);
  reverse(octal.begin(), octal.end());
  return octal;
}
int octalToDecimal(string octal) {
  char digit;
  int decimal = 0;
  for (int i = 0; i < octal.size(); i++) {
    digit = octal.at(octal.size() - (i + 1));
    decimal = decimal + (atoi(&digit) * pow(8, i));
  }
  return decimal;
}
string decimalToHexadecimal(int decimal) {
  string hexadecimal("");
  int remainder;
  while (decimal >= 16) {
    remainder = decimal % 16;
    if (remainder < 10) {
      hexadecimal += to_string(remainder);
    }
    else {
      hexadecimal += (char)(remainder + 55);
    }
    decimal /= 16;
  }
  if (decimal < 10) {
    hexadecimal += to_string(decimal);
  }
  else {
    hexadecimal += (char)(decimal + 55);
  }
  reverse(hexadecimal.begin(), hexadecimal.end());
  return hexadecimal;
}
int hexadecimalToDecimal(string hexadecimal) {
  char character;
  int decimal = 0;
  for (int i = 0; i < hexadecimal.size(); i++) {
    character = hexadecimal.at(hexadecimal.size() - (i + 1));
    if (character >= '0' && character <= '9') {
    decimal = decimal + (atoi(&character) * pow(16, i));
    }
    else {
      decimal = decimal + (((int)(toupper(character)) - 55) * pow(16, i));
    }
  }
  return decimal;
}