#include <iostream>
#include <string>
#include "lab1.hpp"

int main(int argc, char const *argv[])
{
    Workers workers;
    while (true) {
    int check;
    std::cout << "1/2/3/4/5 добавить/поиск/изменить/удалить/вывод: ";
    std::cin >> check;
    if (check == 1) {
        std::cout << "1/0 консоль/файл: ";
        int k; std::cin >> k;
        if(k == 1) {
            Worker person;
            person.updateFromConsole();
            workers.append(person);
            workers.sort();
            std::cout << "добавлен >>" << "\n";
            person.printInfo();
        } else if (!k) {
            workers.ReadFromFile();
            workers.sort();
            std::cout << "добавлено >>" << "\n\n";
            workers.printInfo();
        } else {
            std::cout << "\x1b[31mневерный ввод!" << "\x1b[0m" << "\n"; continue;
        }
    } else if (check == 2) {
        int k; std::cout << "1/2/3 имя/должность/стаж: ";
        std::cin >> k;
        switch (k) {
            case 1:
                {std::string name;
                std::cout << "введите имя сотрудника(ов): ";
                std::cin >> name;
                workers.search_withname(name);
            break;}
            case 2:
                {std::string job;
                std::cout << "введите должность сотрудника(ов): ";
                std::cin >> job;
                workers.search_withjob(job);
            break;}
            case 3:
                {int year;
                std::cout << "введите год устройства сотрудника(ов): ";
                std::cin >> year;
                workers.search_withyear(year);
            break;}
            default:
                std::cout << "\x1b[31mнекорректный ввод!" << "\x1b[0m" << "\n";
        }
    } else if (check == 3) {
        std::cout << "Порядковый номер изменяемого работника: ";
        int num; std::cin >> num;
        workers.update(num);
        workers.printInfo();
    } else if (check == 4) {
        std::cout << "Порядковый номер удаляемого работника: ";
        int num; std::cin >> num;
        workers.remove(num);
        workers.printInfo();
    } else if (check == 5) {
        workers.printInfo();
    } else {std::cout << "\x1b[31mневерный ввод!" << "\x1b[0m" << "\n"; continue;}
    }
    return 0;
}
