#include "worker.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>

// класс Workers - управление информацией о работниках
struct Workers {

    // вектор с информацией о работниках
    std::vector<Worker> data;
 
    // добавить работника
    void append(const Worker& person) {
        data.push_back(person);
    }

    // обновление данных от пользователя
    Worker stdinput() {
        Worker person;
        std::string name, job; int year;
        std::cout << "Введите имя работника: ";
        std::cin.ignore();
        std::getline(std::cin, name); 
        std::cout << "Введите должность работника: ";
        std::getline(std::cin, job);
        std::cout << "Введите год принятия на работу: ";
        std::cin >> year;
        if (std::cin.fail()) {
            throw TypeError();
        }
        person.setName(name);
        person.setJob(job);
        person.setYear(year);
        return person;
    }

    // считать информацию из файла
    void filein() {
        std::ifstream file("data.txt");
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
            Worker person;
            person.setName(words[0]);
            person.setJob(words[1]);
            person.setYear(std::stoi(words[2])); 
            append(person);
        }
        
    }

    // обновить информацию
    int update(int& num) {
        if (num < 1 || num > data.size()) {std::cout << "неверный ввод!"; return 1;}
        num--;
        try {
            data[num] = stdinput();
        } catch (TypeError& e) {std::cout << e.what();}
            
        return 0;
    }

    // удалить работника
    int remove(int& num) {
        if (num < 1 || num > data.size()) {std::cout << "неверный ввод!"; return 1;}
         num--;
         data.erase(data.begin() + num);
         return 0;
    }

    // сортировать
    void sort() {
        std::sort(data.begin(), data.end());
    }

    // поиск по имени
    void search_withname(std::string& name) const {
        bool flag = 0;
        for (int i = 0; i < data.size(); i++) {
            if (name == data[i].getName()) {
                data[i].printInfo();
                flag = 1;
            }
        }
        if (flag == 0) {std::cout << "\x1b[31mнет результатов!" << "\x1b[0m" << "\n";}
    }

    // поиск по году
    void search_withyear(int& in) const {
        bool flag = 0;
        for (int i = 0; i < data.size(); i++) {
            if (in <= data[i].getYear()) {
                data[i].printInfo();
                flag = 1;
            }
        }
         if (flag == 0) {std::cout << "\x1b[31mнет результатов!" << "\x1b[0m" << "\n";}
    }

    // поиск по должности
    void search_withjob(std::string& job) const {
        bool flag = 0;
        for (int i = 0; i < data.size(); i++) {
            if (job == data[i].getJob()) {
                data[i].printInfo();
                flag = 1;
            }
        }
         if (flag == 0) {std::cout << "\x1b[31mнет результатов!" << "\x1b[0m" << "\n";}
    }

    // вывести информацию
    void printInfo() const {
        if (data.empty()) {std::cout << "\x1b[31mрабочих нет!" << "\x1b[0m" << "\n";}
        for (int i = 0; i < data.size(); i++) {
            data[i].printInfo();
        }
    }
    
};
