#include "list.h"


int main(int argc, char const *argv[])
{
    LinkedList<Node> list;
    list.push_front(*new Node("Ivan", "Engineer", 2019));
    list.push_front(*new Node("Pavel", "Engineer", 2000));
    list.push_back(*new Node("Vasiliy", "Engineer", 2020));
    list.pop_front();
    list.print();
    return 0;
}