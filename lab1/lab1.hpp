#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

// класс Worker - информация о работнике
class Worker {
    public:
    // конструктор
    Worker(std::string name = "none", std::string job = "none", int year = 2000)
    : name(name), job(job), year(year) {}

    // оператор сравнения для сортировки
    bool operator<(const Worker& other) const {
        int len = std::min(name.length(), other.name.length());
        int i = 0;
        while (i < len && name[i] == std::tolower(other.name[i])) {
            i++;
        }
        return name[i] < std::tolower(other.name[i]);
    }

    // обновление данных от пользователя
    void updateFromConsole() {
        std::cout << "Введите имя работника: ";
        std::cin >> name;
        std::cout << "Введите должность работника: ";
        std::cin >> job;
        std::cout << "Введите год принятия на работу: ";
        std::cin >> year;
        std::cin.ignore();
    }

    // вывод информации
    void printInfo() const {
        //std::cout << "\n";
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

    private:
    // поля класса
    std::string name;
    std::string job;
    int year; 
};

// структура Workers - управление информацией о работниках
struct Workers {

    // добавить работника
    void append(Worker& person) {
        data.push_back(person);
    }

    // считать информацию из файла
    void ReadFromFile() {
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
            Worker person(words[0], words[1], std::stoi(words[2]));
            append(person);
        }
        
    }
    
    // вывести информацию
    void printInfo() {
        if (data.empty()) {std::cout << "\x1b[31mрабочих нет!" << "\x1b[0m" << "\n";}
        for (int i = 0; i < data.size(); i++) {
            data[i].printInfo();
        }
    }

    // обновить информацию
    void update(int& num) {
        num--;
        data[num].updateFromConsole();
    }

    // удалить работника
    void remove(int& num) {
         num--;
         data.erase(data.begin() + num);
    }

    // сортировать
    void sort() {
        std::sort(data.begin(), data.end());
    }

    // поиск по имени
    void search_withname(std::string& name) {
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
    void search_withyear(int& in) {
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
    void search_withjob(std::string& job) {
        bool flag = 0;
        for (int i = 0; i < data.size(); i++) {
            if (job == data[i].getJob()) {
                data[i].printInfo();
                flag = 1;
            }
        }
         if (flag == 0) {std::cout << "\x1b[31mнет результатов!" << "\x1b[0m" << "\n";}
    }

    // вектор с информацией о работниках
    std::vector<Worker> data;
};
