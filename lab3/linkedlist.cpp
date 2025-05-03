#include <iostream>

using namespace std;

class LinkedList {

    class Node {
    public:
        Node(const string& name,const unsigned int year, const string profession) {
            this->name = name;
            this->profession = profession;
            this->year = new unsigned int(year);
        }
        string& to_str() const {
            string node;
            node += "name: " + name + "\n";
            node += "year: " + toString(*year) +"\n";
            node += "profession: " + profession + "\n";
        }
    private:

        template <typename T>
        static std::string toString(T val) {
            std::ostringstream oss;
            oss<< val;
            return oss.str();
        }

        string name;
        unsigned int* year;
        string profession;
        Node* next = nullptr;
    };

    
    Node* right = nullptr;
    Node* left = nullptr;
};

