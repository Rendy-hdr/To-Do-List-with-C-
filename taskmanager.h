#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <iostream>
using namespace std;

//Berisi definisi kelas TaskCategory dengan metode untuk mengelola daftar tugas, seperti addTask(), completeTask(), dan deleteTask().

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
// Function untuk menampilkan kalender sekarang
void displayDate() {
    string daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    string monthsOfYear[] = {"January", "February", "March", "April", "May", "June", "July",
                             "August", "September", "October", "November", "December"};
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    // Display the current date
    cout << daysOfWeek[ltm->tm_wday] << ", " << ltm->tm_mday << " " << monthsOfYear[ltm->tm_mon]
         << " " << 1900 + ltm->tm_year << endl;
    
    // Display the current time (HH:MM:SS)
    cout << "Current time: " 
         << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour << ":" 
         << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min <<endl;
}

// Base class for Task categories
class TaskCategory {
//atribut-atribut ini hanya dapat diakses oleh kelas itu sendiri dan kelas turunan (subclass).
protected:
    vector<string> tasks;//Menyimpan daftar tugas dalam bentuk string di dalam kategori
    //"My Day", maka tasks akan berisi tiga elemen string seperti 
    //{"Mengerjakan laporan", "Membaca buku", "Latihan coding"}.
    vector<bool> completedTasks; // Track the status of each task
    string categoryName;

public:
    TaskCategory(const string &name) : categoryName(name) {}

    // Function to display all tasks
    void displayTasks() const {
        cout << "Tasks for " << categoryName << ":" << endl;
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
        } else {
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i] << " [" << (completedTasks[i] ? "Completed" : "Pending") << "]" << endl;
            }
        }
        cout << endl;
    }

    // Function to add a task to the category
    void addTask() {
        string newTask;
        do {
            clearScreen();
            displayDate();

            // Display updated tasks
            displayTasks();

            cout << "Enter your task for " << categoryName << " (or type 'b' to go back): ";
            getline(cin, newTask);

            if (newTask == "b") {
                return;  // Go back to task operations
            } else {
                tasks.push_back(newTask);  // Add new task to the list
                completedTasks.push_back(false); // Mark the task as not completed
            }
        } while (true);
    }

    // Function to mark a task as completed
    void completeTask() {
        string taskNumberStr;
        int taskNumber;

        do {
            clearScreen();
            displayDate();

            if (tasks.empty()) {
                cout << "No tasks available to complete." << endl;
                system("pause");
                return;
            }

            // Display updated tasks
            displayTasks();

            cout << "Enter the number of the task you completed (or type 'b' to go back): ";
            getline(cin, taskNumberStr);

            if (taskNumberStr == "b") {
                return;  // Go back to task operations
            }

            try {
                taskNumber = stoi(taskNumberStr);
                if (taskNumber > 0 && taskNumber <= tasks.size()) {
                    completedTasks[taskNumber - 1] = true; // Mark the task as completed
                    cout << "Task " << taskNumber << " marked as completed." << endl;
                    system("pause");
                } else {
                    cout << "Invalid task number. Try again." << endl;
                    system("pause");
                }
            } catch (exception &e) {
                cout << "Invalid input. Please enter a valid task number." << endl;
                system("pause");
            }
        } while (true);
    }

    // Function to delete a task
    void deleteTask() {
        string taskNumberStr;
        int taskNumber;

        do {
            clearScreen();
            displayDate();

            if (tasks.empty()) {
                cout << "No tasks available to delete." << endl;
                system("pause");
                return;
            }

            // Display updated tasks
            displayTasks();

            cout << "Enter the number of the task you want to delete (or type 'b' to go back): ";
            getline(cin, taskNumberStr);

            if (taskNumberStr == "b") {
                return;  // Go back to task operations
            }

            try {
                taskNumber = stoi(taskNumberStr);
                if (taskNumber > 0 && taskNumber <= tasks.size()) {
                    tasks.erase(tasks.begin() + taskNumber - 1);
                    completedTasks.erase(completedTasks.begin() + taskNumber - 1); // Remove task status
                    cout << "Task " << taskNumber << " deleted successfully." << endl;
                    system("pause");
                } else {
                    cout << "Invalid task number. Try again." << endl;
                    system("pause");
                }
            } catch (exception &e) {
                cout << "Invalid input. Please enter a valid task number." << endl;
                system("pause");
            }
        } while (true);
    }
};
// Task categories stored in a vector for dynamic management
vector<TaskCategory> taskCategories = {
    TaskCategory("My Day"),
    TaskCategory("Important"),
    TaskCategory("Planned"),
    TaskCategory("Task"),
    TaskCategory("Assigned")
};


#endif