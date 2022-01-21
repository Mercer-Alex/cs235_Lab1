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
        ifstream infile ("TODOList.txt");
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
        ofstream outfile;
        outfile.open("TODOlist.txt", ofstream::out | ofstream::trunc);
        for(int i = 0; i < tasks.size(); ++i) {
            cout << tasks[i] << endl;
            outfile << tasks[i] << endl;
        }
        outfile.close();
    }
    virtual void add(string _duedate, string _task) {
        tasks.push_back(_duedate + " " + _task);
        cout << "In add " << _duedate << " " << _task << endl;
    }
    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    virtual int remove(string _task) {
        cout << "In remove" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            if (tasks[i] == _task) {
                tasks.erase(tasks.begin() + i + 1);
            }
        }
        return 1;
    }
    virtual void printTodoList() {
        cout << "In list" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << tasks[i] << " " << endl;
        }
    }
    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    virtual void printDaysTasks(string _date) {
        cout << "In daystacks" << endl;
    }
};
#endif