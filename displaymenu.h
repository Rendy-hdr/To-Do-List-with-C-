#ifndef DISPLAYMENU_H
#define DISPLAYMENU_H

#include <iostream>
#include <cstdlib> // For atoi
#include <string>
using namespace std;

//Memastikan bahwa fungsi untuk menampilkan dan menangani pilihan menu dipecah menjadi bagian-bagian yang modular.

// Function untuk menampilkan main menu dan menghandle choice
int displayMenu() {
    string input;
    int choice;

    while (true) {
        cout << "Main Menu\n1. My Day\n2. Important\n3. Planned\n4. Task\n5. Assigned to me\n6. Exit\n";
        cout << "Choose a category (1-6): ";
        
        getline(cin, input);
        
        choice = atoi(input.c_str());

        if (choice == 0 && input != "0") {
            cout << "Non-numeric or invalid input entered. Please enter a valid number (1-6)." << endl;
            system("pause");
        } 
        else if (choice >= 1 && choice <= 6) {
            return choice;
        } 
        else {
            cout << "Invalid choice. Please choose a valid option (1-6)." << endl;
            system("pause");
        }
    }
}

#endif
