#include <iostream>
#include "lab1.hpp"

// Главная функция программы
int main(int argc, char const *argv[])
{
    Workers workers; // Создаем объект класса Workers для управления информацией о работниках
    while (true) {
        int check;
        // Выводим меню для выбора действия
        std::cout << "1/2/3/4/5 добавить/поиск/изменить/удалить/вывод: ";
        std::cin >> check;
        
        if (check == 1) { // Добавление работника
            std::cout << "1/0 консоль/файл: ";
            int k; std::cin >> k;
            if(k == 1) {
                Worker person;
                person.updateFromConsole(); // Ввод информации о работнике с консоли
                workers.append(person); // Добавление работника в список
                workers.sort(); // Сортировка списка работников
                std::cout << "добавлен >>" << "\n";
                person.printInfo(); // Вывод информации о добавленном работнике
            } else if (!k) {
                workers.ReadFromFile(); // Чтение информации о работниках из файла
                workers.sort(); // Сортировка списка работников
                std::cout << "добавлено >>" << "\n\n";
                workers.printInfo(); // Вывод информации о всех работниках
            } else {
                std::cout << "\x1b[31mневерный ввод!" << "\x1b[0m" << "\n"; continue;
            }
        } else if (check == 2) { // Поиск работника
            int k; std::cout << "1/2/3 имя/должность/стаж: ";
            std::cin >> k;
            switch (k) {
                case 1: // Поиск по имени
                    {
                        std::string name;
                        std::cout << "введите имя сотрудника(ов): ";
                        std::cin >> name;
                        workers.search_withname(name);
                        break;
                    }
                case 2: // Поиск по должности
                    {
                        std::string job;
                        std::cout << "введите должность сотрудника(ов): ";
                        std::cin >> job;
                        workers.search_withjob(job);
                        break;
                    }
                case 3: // Поиск по году устройства
                    {
                        int year;
                        std::cout << "введите год устройства сотрудника(ов): ";
                        std::cin >> year;
                        workers.search_withyear(year);
                        break;
                    }
                default:
                    std::cout << "\x1b[31mнекорректный ввод!" << "\x1b[0m" << "\n";
            }
        } else if (check == 3) { // Изменение информации о работнике
            std::cout << "Порядковый номер изменяемого работника: ";
            int num; std::cin >> num;
            workers.update(num); // Обновление информации о работнике
            workers.printInfo(); // Вывод обновленной информации о всех работниках
        } else if (check == 4) { // Удаление работника
            std::cout << "Порядковый номер удаляемого работника: ";
            int num; std::cin >> num;
            workers.remove(num); // Удаление работника из списка
            workers.printInfo(); // Вывод информации о всех оставшихся работниках
        } else if (check == 5) { // Вывод информации о всех работниках
            workers.printInfo();
        } else {
            std::cout << "\x1b[31mневерный ввод!" << "\x1b[0m" << "\n"; continue;
        }
    }
    return 0;
}

