#ifndef GOBACK_H
#define GOBACK_H

#include <iostream>
using namespace std;

void goBack() {
    char back;
    cout << "Input 'b' to go back: ";
    cin >> back;
    
    if (back == 'b') {
        // logic untuk kembali ke page sebelumnya di setiap menu
        // For example, you can simply return here if this function is part of a loop in main
        return;
    } else {
        cout << "Invalid input. Try again." << endl;
        goBack();  // jika inpit bukan "b" memanggil goback;
    }
}

#endif