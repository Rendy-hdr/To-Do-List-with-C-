#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "taskmanager.h"
#include "displaymenu.h"
#include "operationmenu.h"
#include "goback.h"
#include "getstart.h"
using namespace std;

int main() {
    int choice;
    TaskCategory* selectedCategory = nullptr;

    do {
        // Clear the screen before showing the main menu to ensure a clean view.
        clearScreen();
        getStart();
        choice = displayMenu();
        
        if (choice >= 1 && choice <= 5) {
            selectedCategory = &taskCategories[choice - 1];
        } else if (choice == 6) {
            cout << "Exiting the program..." << endl;
            return 0;  // Exit the program
        } else {
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
