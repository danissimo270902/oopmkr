//
// Created by danis on 14.05.2021.
//


#ifndef OOPMKR_LIST_H
#define OOPMKR_LIST_H

#include <iostream>

class List {
private:


    //Body of list

    class ListNode {
    public:

        double value;
        ListNode* prev;
        ListNode* next;

        explicit ListNode(const double& value){
            this->value = value;
            prev = nullptr;
            next = nullptr;
        }
    };

    ListNode*  head;
    ListNode*  tail;
    int length;

public:

    List(){
        head = nullptr;
        tail = nullptr;
        length = 0;

    }

    ~List() = default;
    void insert(int index, double value){
        if(index > length){
            return;
        }
        length++;
        auto *node = new ListNode(value) ;
        if(length == 0){
            head = node;
            tail = node;
            return;
        }
        ListNode* count = head;
        for(int i = 0; i < index; i++){
            count = count->next;
        }
        node->next = count;
        if(count == tail){
            count->next = node;
            node->prev = count;
            tail = node;
            return;
        }
        count = count->next;
        if(count == head){
            count->prev = node;
            node->next = count;
            head = node;
            return;
        } else{
            node->prev = count->prev;
            node->next = count;
            node->prev->next = node;
            count->prev = node;
            return;
        }
    }
    void erase(int index){
        if(index >= length){
            return;
        }
        if(length == 1){
            head = nullptr;
            tail = nullptr;
            length--;
            return;
        }
        if(index == 0){
            head = head->next;
            head->prev = nullptr;
            length--;
            return;
        }
        if(index == length - 1){
            tail = tail->prev;
            tail->next = nullptr;
            length--;
            return;
        }
        ListNode* count;
        count = head;
        for (int i = 0; i < index; i++) {
            count = count->next;
        }
        count->prev->next = count->next;
        count->next->prev = count->prev;
        length--;
    }


};


#endif //OOPMKR_LIST_H
