// Copyright 2020 John Doll
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char* argv[]) {
if (argc != 2)
    cerr << "Please enter a number";

int list[stoi(argv[1]) - 1];

cout << "Enter " << argv[1] << " number(s):";

for (int i = 0; i < stoi(argv[1]); i++)
    cin >> list[i];

int *ptr = &list[stoi(argv[1]) - 1];

for (int i = 0; i < stoi(argv[1]); i++) {
    cout << "The factors of " << *ptr << " are:" << endl;
    for (int j = *ptr - 1; j > 1; j--) {
        if (*ptr % j == 0)
           cout << j << " ";
    }
    ptr -= 1;
    cout << endl;
}


return 0;
}
