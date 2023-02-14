#include <iostream>
#include <string>
using namespace std;

int number_of_alphabet(char alphabet) {
if (alphabet >= 'a' && alphabet <= 'm') {
return alphabet - 'a' + 1;
} else if (alphabet >= 'n' && alphabet <= 'z') {
return 13 - (alphabet - 'n');
} else if (alphabet >= 'A' && alphabet <= 'M') {
return alphabet - 'A' + 1;
} else {
return 13 - (alphabet - 'N');
}
}
int rem(int num, int den) {
return num % den;
}

int main() {
string first_name, last_name;
cout << "Enter your first name: ";
cin >> first_name;
cout << "Enter your last name: ";
cin >> last_name;

int length = last_name.length();
if (length < 5) {
last_name += last_name.substr(0, 5-length);
}

int a = number_of_alphabet(last_name[0]) * 100;
int b = number_of_alphabet(last_name[1]) * 100;
int c = number_of_alphabet(last_name[2]) + 4;
int d = number_of_alphabet(last_name[3]) * 500;
int mode = rem((last_name[4] <= 'Z' ? last_name[4] - 'A' + 1 : last_name[4] - 'a' + 1), 4) + 1;

cout << "The parameter set for the name " << " is " << a << " μS, " << b << " μS, " << c << ", " << d << " μS, and mode " << mode << "." << endl;
return 0;
}
