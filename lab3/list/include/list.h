#pragma once
#include <iostream>

struct value_t {
    std::string name, job;
    int* date;
};

class Node {
    value_t value;
public:
    Node* next;
    Node(const std::string& name,const std::string& job,const int date);
    bool operator<(const Node& other) const;
    void print() const;
};

template<typename T>
class LinkedList {
    T* head;
    T* tail;
    friend class Iterator;
public:
    LinkedList() {head = tail = nullptr;}
    class Iterator {
        T* ptr;
        public:
        Iterator(T* p) {ptr = p;}
        T& operator*() const {return *ptr;}
        T* operator->() const {return ptr;}
        bool operator!=(const Iterator& other) const {return ptr != other.ptr;}
        bool operator==(const Iterator& other) const {return ptr == other.ptr;}
        Iterator& operator++() {
            ptr = ptr->next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ptr = ptr->next;
            return tmp;
        }
    };

    Iterator begin() const { return Iterator(head); }
    Iterator end() const { return Iterator(nullptr); }

    //void sort() {}
    void print() const {for (auto i : *this) {i.print();}}
    Iterator push_front(T& node) {
                                if (head == nullptr) {
                                    head = tail = &node;
                                }
                                else {
                                    node.next = head;
                                    head = &node;
                                }
                                return Iterator(&node);
    }
    Iterator push_back(T& node) {
                                if (head == nullptr) {
                                    head = tail = &node;
                                }
                                else {
                                    tail->next = &node;
                                    tail = &node;
                                }
                                return Iterator(&node);
    }
    Iterator pop_back() {
                                T* tmp = head;
                                while(tmp->next != tail) {
                                    tmp = tmp->next;
                                }
                                tmp->next = nullptr;
                                tail = tmp;
                                return tmp;
    }
    Iterator pop_front() {
                                T* tmp = head;
                                head = head->next;
                                delete tmp;
                                return Iterator(head);
    }
};