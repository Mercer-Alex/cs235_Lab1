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
        ifstream infile ("TODOList.txt");
        string line;
        if (infile.is_open()) {
            while (getline(infile, line)) {
                tasks.push_back(line);
            }
            infile.close();
        }
    }
    virtual ~TodoList() {
        ofstream outfile;
        outfile.open("TODOlist.txt", ofstream::out | ofstream::trunc);
        for(int i = 0; i < tasks.size(); ++i) {
            outfile << tasks[i] << endl;
        }
        outfile.close();
    }
    virtual void add(string _duedate, string _task) {
        tasks.push_back(_duedate + " " + _task);
        cout << "In add " << _duedate << " " << _task << endl;
    }
    virtual int remove(string _task) {
        cout << "In remove" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            if (parseTask(tasks[i]) == _task) {
                tasks.erase(tasks.begin() + i);
                return 1;
            }
        }
        return 0;
    }
    string parseTask(string _task) {
        for (int i = 0; i < _task.size(); ++i) {
            if (_task.at(i) == ' ') {
                return _task.substr(i + 1, _task.size() - i - 1);
            }
        }
        return "";
    }
    string firstWordParse(string _task) {
        for (int i = 0; i < _task.size(); ++i) {
            if (_task.at(i) == ' ') {
                return _task.substr(0, i);
            }
        }
        return "";
    }
    virtual void printTodoList() {
        cout << "In list" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << tasks[i] << " " << endl;
        }
    }
    virtual void printDaysTasks(string _date) {
        cout << "Tasks for: " << _date << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            if (firstWordParse(tasks[i]) == _date) {
                cout << parseTask(tasks[i]) << endl;
            }
        }
    }
};
#endif