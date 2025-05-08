#include "list.h"

Node::Node(const std::string& name,const std::string& job,const int date) {
        value.name = name;
        value.job = job;
        value.date = new int(date);
        next = nullptr;
    }
void Node::print() const {
        std::cout << "name: " << value.name << "\n";
        std::cout << "job: " << value.job << "\n";
        std::cout << "date: " << *value.date << "\n\n";
    }

bool Node::operator<(const Node& other) const {
    return *value.date < *other.value.date;
} 



