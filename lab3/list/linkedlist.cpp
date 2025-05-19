#include "list.h"

Worker::Worker(const std::string& name,const std::string& job,const int date) {
        value.name = name;
        value.job = job;
        value.date = new int(date);
        next = nullptr;
    }
void Worker::print() const {
        std::cout << "\x1b[32m name: \x1b[37m" << value.name << "\n";
        std::cout << "\x1b[32m job: \x1b[37m" << value.job << "\n";
        std::cout << "\x1b[32m date: \x1b[37m" << *value.date << "\n\n";
    }

/* bool Worker::operator<(const Worker& other) const {
    return *value.date < *other.value.date;
} */

bool Worker::operator<(const Worker& other) const {
        int len = std::min(value.name.length(), other.value.name.length());
        int i = 0;
        while (i < len && std::toupper(value.name[i]) == std::toupper(other.value.name[i])) {
            i++;
        }
        return std::toupper(value.name[i]) < std::toupper(other.value.name[i]);
    }

bool Worker::operator>=(const Worker& other) const {
        int len = std::min(value.name.length(), other.value.name.length());
        int i = 0;
        while (i < len && std::toupper(value.name[i]) == std::toupper(other.value.name[i])) {
            i++;
        }
        return std::toupper(value.name[i]) >= std::toupper(other.value.name[i]);
    }

/* bool Worker::operator>=(const Worker& other) const {
    return *value.date >= *other.value.date;
} */

void Worker::modify() {
    std::cin.ignore();
    std::cout << "\x1b[32m name: \x1b[37m";
    std::getline(std::cin, value.name);
    std::cout << "\x1b[32m job: \x1b[37m";
    std::getline(std::cin, value.job);
    std::cout << "\x1b[32m date: \x1b[37m";
    std::cin >> *value.date;
}

Worker Worker::operator=(Worker& other) {
    value = other.value;
    return *this;
}



