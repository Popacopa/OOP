#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <string>
#include "exception.h"

// класс Worker - информация о работнике
struct Worker {

    // поля класса
    std::string name;
    std::string job;
    int year;

    public:

    // оператор сравнения для сортировки
    bool operator<(const Worker& other) const {
        int len = std::min(name.length(), other.name.length());
        int i = 0;
        while (i < len && std::toupper(name[i]) == std::toupper(other.name[i])) {
            i++;
        }
        return std::toupper(name[i]) < std::toupper(other.name[i]);
    }

    // вывод информации
    void printInfo() const {
        std::cout << "\x1b[32mИмя:\x1b[32m " << name << "\n"
                  << "Должность: " << job << "\n"
                  << "Год принятия на работу: " << year << "\n";
        std::cout << "\x1b[0m";
        std::cout << "\n";
    }

    // геттеры
    std::string getName() const {return name;}
    std::string getJob() const {return job;}
    int getYear() const {return year;}

    // сеттеры
    void setName(const std::string& name) { this->name = name; }
    void setJob(const std::string& job) { this->job = job; }
    void setYear(int year) { this->year = year; } 
};

#endif