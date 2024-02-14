#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> 
using namespace std;


struct Task {
    string description;
};


void banner();
void addTask();
void showTasks();
void searchTask();
void deleteTask();

int main() {
    char choice;
    do {
        system("cls");
        banner();
        cout << "\n\t1. Add Task";
        cout << "\n\t2. Show Tasks";
        cout << "\n\t3. Search Task";
        cout << "\n\t4. Delete Task";
        cout << "\n\t5. Exit";
        cout << "\n\n\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addTask();
                break;
            case '2':
                showTasks();
                break;
            case '3':
                searchTask();
                break;
            case '4':
                deleteTask();
                break;
            case '5':
                cout << "\n\tExiting...\n";
                break;
            default:
                cout << "\n\tInvalid choice. Please try again.\n";
                break;
        }
    } while (choice != '5');

    return 0;
}


void banner() {
    cout << " _________________________________ " << endl;
    cout << " \t    My  Todo" << endl;
    cout << " _________________________________ " << endl;
}


void addTask() {
    system("cls");
    banner();
    Task newTask;
    cout << "Enter new task description: ";
    cin.ignore(); 
    getline(cin, newTask.description);

    ofstream fout("todo.txt", ios::app);
    if (!fout) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    fout << newTask.description << endl;
    fout.close();

    cout << "\nTask added successfully!\n";
    system("pause");
}


void showTasks() {
    system("cls");
    banner();
    ifstream fin("todo.txt");
    if (!fin) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    string task;
    int count = 0;
    while (getline(fin, task)) {
        cout << ++count << ". " << task << endl;
    }

    fin.close();
    if (count == 0) {
        cout << "\nNo tasks found!\n";
    }
    system("pause");
}


void searchTask() {
    system("cls");
    banner();
    ifstream fin("todo.txt");
    if (!fin) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    string search;
    cout << "Enter task description to search: ";
    cin.ignore(); 
    getline(cin, search);

    string task;
    int count = 0;
    while (getline(fin, task)) {
        if (task.find(search) != string::npos) {
            cout << ++count << ". " << task << endl;
        }
    }

    fin.close();
    if (count == 0) {
        cout << "\nNo matching tasks found!\n";
    }
    system("pause");
}


void deleteTask() {
    system("cls");
    banner();
    ifstream fin("todo.txt");
    if (!fin) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    string tempFile = "temp.txt";
    ofstream temp(tempFile);

    string task, deleteTask;
    bool found = false;
    cout << "Enter task description to delete: ";
    cin.ignore(); 
    getline(cin, deleteTask);

    while (getline(fin, task)) {
        if (task != deleteTask) {
            temp << task << endl;
        } else {
            found = true;
        }
    }

    fin.close();
    temp.close();

    if (!found) {
        remove(tempFile.c_str());
        cout << "\nTask not found!\n";
    } else {
        remove("todo.txt");
        rename(tempFile.c_str(), "todo.txt");
        cout << "\nTask deleted successfully!\n";
    }

    system("pause");
}
