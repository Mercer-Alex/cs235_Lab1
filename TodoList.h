#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "TodoListInterface.h"

using namespace std;

class TodoList: public TodoListInterface {
public:
    vector <string> tasks;
    TodoList() {
        cout << "In Constructor" << endl;
        ifstream infile ("TODO.txt");
        string line;
        if (infile.is_open()) {
            while (getline(infile, line)) {
                cout << line << endl;
                tasks.push_back(line);
            }
            infile.close();
        }
    }
    virtual ~TodoList() {
        cout << "In Destructor" << endl;
        
    }
    /*
    *   Adds an item to the todo list with the data specified by the string _duedate" and the task specified by "_task"
    */
    virtual void add(string _duedate, string _task) {
        cout << "In add" << endl;
    }
    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    virtual int remove(string _task) {
        cout << "In remove" << endl;
        return 1;
    }
    /*
    *   Prints out the full todo list to the console
    */
    virtual void printTodoList() {
        cout << "In list" << endl;
    }
    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    virtual void printDaysTasks(string _date) {
        cout << "In daystacks" << endl;
    }
};
#endif