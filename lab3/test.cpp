#include "./list/include/list.h"
#include "rang.hpp"
#include <fstream>
#include <sstream>
#define RED rang::bg::red
#define RESET rang::bg::reset



int main(int argc, char const *argv[])
{
    LinkedList<Worker> list;
    while (true) {
        int check1;
        std::cout << "1. добаить \n2. удалить \n3. изменить \n4. вывести \n5. фильтр по стажу \n6. фильтр по должности\n7. выход\n";
        std::cin >> check1;
        if (check1 == 1) {
            int check2;
            std::cout << "1. вручную \n2. из файла\n";
            std::cin >> check2;
            if (check2 == 1) {
                Worker* tmp = new Worker("none", "none", 0); tmp->modify(); list.push(*tmp);
            }
            if (check2 == 2) {
                std::ifstream file("../data.txt");
                if (!file.is_open()) {
                    std::cerr << "\x1b[31mНе удалось открыть файл!" << "\x1b[0m" << "\n";
                }

                std::string line;
                while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string word;
                std::vector<std::string> words;
                while (std::getline(iss, word, ' ')) {
                    if (!word.empty()) {
                        words.push_back(word);
                    }   
                }
                Worker* person = new Worker("none", "none", 0);
                person->value.name = words[0];
                person->value.job = words[1];
                *person->value.date = std::stoi(words[2]); 
                list.push(*person);
        }
            }
        }
        
        if (check1 == 2) {
            int index;
            std::cout << "введите индекс: ";
            std::cin >> index;
            int status = list.del(index);
            if (status) {std::cout << RED << "неверный ввод!" << RESET << "\n";}
        }
        if (check1 == 3) {
            int index;
            std::cout << "введите индекс: ";
            std::cin >> index;
            int status = list.mod(index);
            if (status) {std::cout << RED << "неверный ввод!" << RESET << "\n";}
        }
        if (check1 == 4) {
            list.print();
        }
        if (check1 == 5) {
            int date;
            bool flag = 0;
            std::cout << "Введите дату: "; std::cin >> date;
            for (auto& i : list) {
                if (*i.value.date > date) {
                    i.print();
                    flag = 1;
                }
            }
            if (!flag) {std::cout << RED << "нет результатов!" << RESET << "\n";}
        }
        if (check1 == 6) {
            std::string job;
            bool flag = 0;
            std::cout << "Введите должность: "; std::cin >> job;
            for (auto& i : list) {
                if (i.value.job == job) {
                    i.print();
                    flag = 1;
                }
            }
            if (!flag) {std::cout << RED << "нет результатов!" << RESET << "\n";}
        }
        if (check1 == 7) {
            break;
        }
    }
    return 0;
}