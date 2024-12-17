#include <iostream>
#include <windows.h>
using namespace std;

void print_tasks(string task[], int task_count) {
    cout << "Tasks to do " << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < task_count; i++) {
        cout << "Task " << i + 1 << " is " << task[i] << endl;
    }
    cout << "----------------------------------------" << endl;
}

int main() {
    system("color b");

    string tasks[10]; // Array to store tasks
    int task_count = 0;
    int option = -1;

    while (option != 0) {
        // Display menu
        cout << "--- To DO List ---" << endl;
        cout << "ENTER 1  To Add new task." << endl;
        cout << "ENTER 2  To view tasks." << endl;
        cout << "ENTER 3  To delete the tasks." << endl;
        cout << "ENTER 0  To Terminate the program." << endl;
        cin >> option;

        switch (option) {
            case 1:
                system("cls");
                // Check if task array is full
                if (task_count >= 10) {
                    cout << "Task storage is full, delete some tasks first." << endl;
                } else {
                    cin.ignore(); // Clear the input buffer before using getline
                    cout << "Enter a new task: " << endl;
                    getline(cin, tasks[task_count]); // Read full line
                    task_count++; // Increase task count
                }
                break;

            case 2:
                system("cls");
                // Print the current tasks
                print_tasks(tasks, task_count);
                break;

            case 3:
                system("cls");
                // Handle task deletion
                int del_task;
                cout << "Enter the task number to delete: " << endl;
                cin >> del_task;

                // Validate the task number entered
                if (del_task < 1 || del_task > task_count) {
                    cout << "Invalid task number." << endl;
                } else {
                    // Shift tasks to delete the selected one
                    for (int i = del_task - 1; i < task_count - 1; i++) {
                        tasks[i] = tasks[i + 1]; // Shift the tasks left
                    }
                    task_count--; // Decrease task count
                    cout << "Task " << del_task << " deleted." << endl;
                }
                break;

            case 0:
                cout << "Program is terminating..." << endl;
                break;

            default:
                cout << "Invalid option, please try again." << endl;
                break;
        }

        // Pause to view output before next action
        system("pause");
    }

    return 0;
}
