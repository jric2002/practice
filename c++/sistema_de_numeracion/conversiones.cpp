#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <cmath>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
string decimalBaseToAnyMinorBase(int, int);
int anyMinorBaseToDecimalBase(string, int);
string decimalBaseToAnyMajorBase(int, int);
int anyMajorBaseToDecimalBase(string, int);
float decimalBaseToFraction(float, int);
float fractionToDecimalBase(float, int);
int main() {
  char option;
  int decimal, base;
  string base_number;
  float decimal_number, fraction;
  while (true) {
    cout << "Operations" << endl;
    cout.fill('-');
    cout.width(10);
    cout << "" << endl;
    cout << "1. Decimal base to any minor base." << endl;
    cout << "2. Any minor base to decimal base." << endl;
    cout << "3. Decimal base to any major base." << endl;
    cout << "4. Any major base to decimal base." << endl;
    cout << "5. Fraction: Decimal base to any base." << endl;
    cout << "6. Fraction: Any base to decimal base." << endl;
    cout << "0. Exit." << endl;
    cout << "Choose an option: ";
    cin >> option;
    cin.ignore();
    if (option == '1') {
      cout << "Enter a decimal: ";
      cin >> decimal;
      cout << "Convert to base: ";
      cin >> base;
      cout << "The decimal " << decimal << " in base " << base << " is: " << decimalBaseToAnyMinorBase(decimal, base) << endl;
    }
    else if (option == '2') {
      cout << "Enter a base number: ";
      cin >> base_number;
      cout << "Enter the base of the number: ";
      cin >> base;
      cout << "The base number " << base_number << "of base " << base << " in base decimal is: " << anyMinorBaseToDecimalBase(base_number, base) << endl;
    }
    else if (option == '3') {
      cout << "Enter a decimal: ";
      cin >> decimal;
      cout << "Convert to base: ";
      cin >> base;
      cout << "The decimal " << decimal << " in base " << base << " is: " << decimalBaseToAnyMajorBase(decimal, base) << endl;
    }
    else if (option == '4') {
      cout << "Enter a base number: ";
      cin >> base_number;
      cout << "Enter the base of the number: ";
      cin >> base;
      cout << "The base number " << base_number << " of base " << base << " in base decimal is: " << anyMajorBaseToDecimalBase(base_number, base) << endl;
    }
    else if (option == '5') {
      cout << "Enter a decimal: ";
      cin >> decimal_number;
      cout << "Convert to base: ";
      cin >> base;
      cout.precision(5);
      cout << "The decimal number " << decimal_number << " in base " << base << " is: " << decimalBaseToFraction(decimal_number, base) << endl;
    }
    else if (option == '6') {
      cout << "Enter a fraction: ";
      cin >> fraction;
      cout << "Enter the base of the fraction: ";
      cin >> base;
      cout.precision(5);
      cout << "The fraction " << fraction << " of base " << base << " in base decimal base is: " << fractionToDecimalBase(fraction, base) << endl;
    }
    else if (option == '0') {
      cout << "Leaving the program :)" << endl;
      break;
    }
    else {
      cout << "That option doesn't exist...xD" << endl;
    }
    cout << endl;
    /* cin.ignore();
    cin.get();
    system("cls"); */
  }
  return 0;
}
/* Definition */
string decimalBaseToAnyMinorBase(int number, int base) {
  string converted_number("");
  while (number >= base) {
    converted_number += to_string(number % base);
    number /= base;
  }
  converted_number += to_string(number);
  reverse(converted_number.begin(), converted_number.end());
  return converted_number;
}
int anyMinorBaseToDecimalBase(string base_number, int base) {
  char digit;
  int decimal = 0;
  for (int i = 0; i < base_number.size(); i++) {
    digit = base_number.at(base_number.size() - (i + 1));
    decimal = decimal + (atoi(&digit) * pow(base, i));
  }
  return decimal;
}
string decimalBaseToAnyMajorBase(int decimal, int base) {
  string converted_number("");
  int remainder;
  while (decimal >= base) {
    remainder = decimal % base;
    if (remainder < 10) {
      converted_number += to_string(remainder);
    }
    else {
      converted_number += (char)(remainder + 55);
    }
    decimal /= base;
  }
  if (decimal < 10) {
    converted_number += to_string(decimal);
  }
  else {
    converted_number += (char)(decimal + 55);
  }
  reverse(converted_number.begin(), converted_number.end());
  return converted_number;
}
int anyMajorBaseToDecimalBase(string base_number, int base) {
  char character;
  int decimal = 0;
  for (int i = 0; i < base_number.size(); i++) {
    character = base_number.at(base_number.size() - (i + 1));
    if (character >= '0' && character <= '9') {
    decimal = decimal + (atoi(&character) * pow(base, i));
    }
    else {
      decimal = decimal + (((int)(toupper(character)) - 55) * pow(base, i));
    }
  }
  return decimal;
}
float decimalBaseToFraction(float base_number, int base) {
  float fraction = 0;
  int digit;
  int aux = 10;
  int i = 0;
  while (base_number != 0 && i < 10) {
    base_number = base_number * base;
    digit = int(base_number);
    fraction = fraction + ((float)( digit) / aux);
    base_number = base_number - digit;
    aux *= 10;
    i++;
  }
  return fraction;
}
float fractionToDecimalBase(float base_number, int base) {
  int digit;
  float decimal = 0;
  int i;
  decimal += int(base_number);
  i = 1;
  while (base_number != 0) {
    base_number = (base_number * 10);
    digit = int(base_number);
    decimal += digit / (float)pow(base, i);
    base_number = base_number - digit;
    i++;
  }
  return decimal;
}