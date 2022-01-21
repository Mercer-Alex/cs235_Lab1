#include <iostream>
#include <string>
#include "TodoList.h"

using namespace std;

int main(int argc, char *argv[]) {

    TodoList mylist;

    if (argc > 1) {
        string command = argv[1];
        if (command == "add") {
            cout << "Doing an add" << endl;
            string date = argv[2];
            string task = argv[3];
            mylist.add(date, task);
        }
        if (command == "remove") {
            cout << "Removing task" << endl;
            string task = argv[2];
            cout << argv[2] << endl;
            mylist.remove(task);
        }
        if (command == "print") {
            cout << "Printing" << endl;
            mylist.printTodoList();
        }
        if (command == "printDay") {
            cout << "Printing day" << endl;
            string day = argv[2];
            mylist.printDaysTasks(day);
        }
    }

    return 0;
}
