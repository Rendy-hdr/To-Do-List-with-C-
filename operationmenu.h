#ifndef OPERATIONMENU_H
#define OPERATIONMENU_H

#include <iostream>
#include <cstdlib> // For atoi
#include <string>
using namespace std;

//Memastikan bahwa fungsi untuk menampilkan dan menangani pilihan menu dipecah menjadi bagian-bagian yang modular.

// Function untuk menjalankan add, completed, delete
int taskOperationsMenu() {
    string input2;
    int operation;

    while (true) {
        // Menampilkan menu task operation (add, complete, delete)
        cout << "Task Operations:\n1. Add Task\n2. Complete Task\n3. Delete Task\n4. Back to Main Menu\n";
        cout << "Choose an operation (1-4): ";

        // Mengambil input yang berupa string
        getline(cin, input2);

        // Mengonversi string ke integer
        operation = atoi(input2.c_str());

        // Validasi input: cek jika operation is between 1 and 4
        if (operation >= 1 && operation <= 4) {
            return operation;  // Return valid operation
        } else {
            cout << "Invalid operation. Please choose a valid option (1-4)." << endl;
        }
    }
}

#endif
