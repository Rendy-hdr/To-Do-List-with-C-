#include <iostream>
#include <ctime>//untuk menampilkan waktu terkini
#include <string>
#include <vector>
#include "taskmanager.h"//definisi Class TaskCategory yang digunakan untuk mengelola tugas.
#include "displaymenu.h"//fungsi untuk menampilkan menu utama kepada pengguna
#include "operationmenu.h"//fungsi untuk menampilkan menu operasi(add, complete, delete) pada setiap kategori tugas.
#include "goback.h"//membantu dalam navigasi kembali ke menu sebelumnya.
#include "getstart.h"//fungsi untuk menampilkan informasi awal saat program dimulai.
using namespace std;

//aplikasi manajemen tugas  yang memungkinkan pengguna untuk memilih kategori tugas, menambah tugas, menandai tugas 
//sebagai selesai, dan menghapus tugas.
// Object-Oriented Programming (OOP) dan modularisasi melalui header files untuk menjaga kode tetap terstruktur 
//dan mudah dipelihara.
int main() {
    int choice;//menyimpan pilihan pengguna dari menu utama.
    TaskCategory* selectedCategory = nullptr;//Pointer untuk menunjuk kategori tugas yang dipilih.

    do {
        // Clear the screen before showing the main menu to ensure a clean view.
        clearScreen();
        getStart();
        choice = displayMenu();
        //Program memeriksa input pengguna. Jika pilihan antara 1 hingga 5, maka program akan menunjuk ke kategori 
        //tugas yang dipilih.
        if (choice >= 1 && choice <= 5) {
            selectedCategory = &taskCategories[choice - 1];
        } else if (choice == 6) {
            cout << "Exiting the program..." << endl;
            return 0;  // Exit the program
        } else {
            //Jika pengguna memilih 6, program menampilkan pesan keluar dan menghentikan eksekusi.
            cout << "Invalid choice. Please choose a valid option (1-6)." << endl;
            system("pause");
            continue;
        }

        cout << choice << endl;

        // Task operations menu (Add, Complete, Delete)
        int operation;
        do {
            clearScreen();
            displayDate();

            // Display tasks at the beginning of each operation
            selectedCategory->displayTasks();

            operation = taskOperationsMenu();
            
            switch (operation) {
                case 1:
                    selectedCategory->addTask();
                    break;
                case 2:
                    selectedCategory->completeTask();
                    break;
                case 3:
                    selectedCategory->deleteTask();
                    break;
                case 4:
                    // Break out of the loop to go back to the main menu
                    break;
                default:
                    cout << "Invalid operation. Please choose a valid option (1-4)." << endl;
                    system("pause");
            }
        } while (operation != 4 && choice >= 1 && choice <= 5);
    
    } while (choice != 6);

    return 0;
}

//Program ini memanfaatkan OOP untuk memisahkan logika dalam kelas TaskCategory, menjaga setiap operasi terstruktur
//dan mudah diperluas. Modularisasi kode dengan header files membuat program lebih mudah dikelola dan dipahami.