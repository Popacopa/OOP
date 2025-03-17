
/* Вариант 6 
Описать структуру (класс) с именем WORKER, содержащую следующие поля:  фамилию и инициалы 
работника (char *, string); название занимаемой должности (char *, string); год поступления на работу 
(int).  
Написать программу, выполняющую следующие действия: 
➢ Ввод данных  (файл, клавиатура на выбор пользователя). 
➢ Упорядочить  записи  по алфавиту (фамилию и инициалы) 
➢ Вывод на экран работников, чей стаж работы превышает значение К. 
➢ Вывод на экран работников, работающих в должности N.  Если  информация не найдена, вывести соответствующее сообщение. 
Предусмотреть возможность редактирования элементов списка – удаление, добавление, изменение. */

#include "src/workers.h"

#define INPUT_ERR std::cout << "\x1b[31mневерный ввод!" << "\x1b[0m" << "\n"; std::cin.clear();
#define THROW if (std::cin.fail()) {std::cin.clear();std::cin.ignore();throw TypeError();}


// Главная функция программы
int main(int argc, char const *argv[])
{
    Workers workers; 
    while (true) {
        int check;
        std::cout << "1/2/3/4/5/6 добавить/поиск/изменить/удалить/вывод/сортировка: ";
        try {                 
            std::cin >> check;

            THROW                          // THROW!!!

            if (check == 1) { 
                std::cout << "1/0 консоль/файл: ";
                int k = NULL; 
                std::cin >> k;

                THROW                              // THROW!!!

                if(k == 1) {
                    workers.append(workers.stdinput()); 
                    //workers.sort(); 
                } else if (!k) {
                    workers.filein(); 
                    //workers.sort(); 
                    std::cout << "добавлено >>" << "\n\n";
                    workers.printInfo(); 
                } else {
                    INPUT_ERR
                }
            } else if (check == 2) { 
                int k; std::cout << "1/2/3 имя/должность/стаж: ";
                std::cin >> k;

                THROW                               // THROW!!!

                switch (k) {
                    case 1: 
                        {
                            std::string name;
                            std::cout << "введите имя сотрудника(ов): ";
                            std::cin.ignore();
                            std::getline(std::cin, name);
                            workers.search_withname(name);
                            break;
                        }
                    case 2:
                        {
                            std::string job;
                            std::cout << "введите должность сотрудника(ов): ";
                            std::cin.ignore();
                            std::getline(std::cin, job);
                            workers.search_withjob(job);
                            break;
                        }
                    case 3:
                        {
                            int year;
                            std::cout << "введите год устройства сотрудника(ов): ";
                            std::cin >> year;

                            THROW                           // THROW!!!

                            workers.search_withyear(year);
                            break;
                        }
                    default:
                        INPUT_ERR
                }
            } else if (check == 3) { 
                                    std::cout << "Порядковый номер изменяемого работника: ";
                                    int num; std::cin >> num;

                                    THROW                   // THROW!!!

                                    workers.update(num); 
                                    workers.printInfo(); 
            } else if (check == 4) { 
                                    std::cout << "Порядковый номер удаляемого работника: ";
                                    int num; std::cin >> num;

                                    THROW                   // THROW!!!

                                    workers.remove(num); 
                                    workers.printInfo(); 
            } else if (check == 5) { 
                                    workers.printInfo();
            } else if (check == 6) { 
                                    workers.sort();
            } else {                        
                                    INPUT_ERR
            }
        } catch (TypeError& e) {std::cerr << e.what();} 
    }
    return 0;
}

