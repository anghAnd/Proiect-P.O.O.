#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <fstream>
//#include "Menu_log.cpp"
#include "Menu_log.h"




using namespace std;

int main() {
    int choose_1;
    int t, cont = 1;
    while (cont == 1) {
        Menu();
        cout << "If you want to continue press 1." << endl;
        cout << "If you want to exit press 0." << endl;

        while (!(cin >> t) || (t != 0 && t != 1)) {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            cout << "Invalid input. Please enter 1 to continue or 0 to exit: ";
        }

        cont = t;
    }

    cout << "Goodbye!" << endl;
    return 0;
}
