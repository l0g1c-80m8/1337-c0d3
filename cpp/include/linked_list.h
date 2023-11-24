//
// Created by Rutvik Patel on 11/23/23.
//

#ifndef INC_1337_C0D3_LINKED_LIST_H
#define INC_1337_C0D3_LINKED_LIST_H

#include <iostream>

// linked list utils

template <typename T>
struct ListNode {
private:
    T value_;
    ListNode<T>* next_;

public:
    ListNode() : value_(0), next_(nullptr) {}
    ListNode(T x) : value_(x), next_(nullptr) {}
    ListNode(T x, ListNode<T>* next) : value_(x), next_(next) {}
     ~ListNode() = default;

    ListNode* get_next() { return next_; }
    void set_next(ListNode<T>* node) { next_ = node; }
    T get_value() const { return value_; }

    bool operator == (const ListNode<T>& rhs_node) const { return get_value() == rhs_node.get_value(); }
    bool operator != (const ListNode<T>& rhs_node) const { return not get_value() == rhs_node.get_value(); }
};

template <typename T>
class LinkedList {
private:
    ListNode<T>* head_;
public:
    LinkedList() : head_(nullptr) {}
    explicit LinkedList(ListNode<T> head) : head_(head) {}
    LinkedList(std::initializer_list<T> values);
    ~LinkedList();

    ListNode<T>* get_head() const { return head_; }
    ListNode<T>* clear_list(ListNode<T>* node);
    ListNode<T>* erase_node(ListNode<T>* node);
    void insert_front(T value);
    void insert_back(T value);
    void insert_after(ListNode<T>* node, T value);
    void display_list();

    bool operator == (const LinkedList<T>& rhs_list);
    bool operator != (const LinkedList<T>& rhs_list);
};

template<typename T>
bool LinkedList<T>::operator == (const LinkedList<T>& rhs_list) {
    ListNode<T>* itr_lhs = head_;
    ListNode<T>* itr_rhs = rhs_list.get_head();

    while (itr_lhs != nullptr and itr_rhs != nullptr) {
        if (*itr_lhs != *itr_rhs)
            return false;

        itr_lhs = itr_lhs->get_next();
        itr_rhs = itr_rhs->get_next();
    }

    return (itr_lhs == nullptr and itr_rhs == nullptr);
}

template<typename T>
bool LinkedList<T>::operator != (const LinkedList<T>& rhs_list) {
    return this != rhs_list;
}

template <typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> values) : head_(nullptr) {
    for (auto& value : values) insert_back(value);
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear_list(head_);
}

template <typename T>
ListNode<T>* LinkedList<T>::clear_list(ListNode<T>* node) {
    auto* temp_node = node;
    while (temp_node != nullptr) temp_node = erase_node(temp_node);
    return temp_node;
}

template <typename T>
ListNode<T>* LinkedList<T>::erase_node(ListNode<T>* node) {
    ListNode<T>* temp_node = nullptr;
    if (node != nullptr) {
        temp_node = node->get_next();
        delete node;
    }
    return temp_node;
}

template <typename T>
void LinkedList<T>::insert_front(T value) {
    head_ = new ListNode { value, head_ };
}

template <typename T>
void LinkedList<T>::insert_back(T value) {
    if (head_ == nullptr) return insert_front(value);
    if (head_->get_next() == nullptr) return insert_after(head_, value);

    auto* temp_node = head_;
    while (temp_node->get_next() != nullptr) temp_node = temp_node->get_next();
    return insert_after(temp_node, value);
}

template <typename T>
void LinkedList<T>::insert_after(ListNode<T> *node, T value) {
    node->set_next(new ListNode<T> { value, node->get_next() });
}

template <typename T>
void LinkedList<T>::display_list() {
    auto* temp_node = head_;
    std::cout << "List: [ ";
    while (temp_node != nullptr) {
        std::cout << temp_node->get_value() << " ";
        temp_node = temp_node->get_next();
    }
    std::cout << "]" << std::endl;
}

#endif //INC_1337_C0D3_LINKED_LIST_H
