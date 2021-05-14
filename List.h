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

        auto *node = new ListNode(value) ;
        if(length == 0){
            head = node;
            tail = node;
            length++;
            return;
        }
        length++;
        ListNode* count = head;
        for(int i = 0; i < index; i++){
            count = count->next;
        }

        if(count == head){
            count->prev = node;
            node->next = count;
            head = node;
            return;
        } else if(count == tail){
            count->next = node;
            node->prev = count;
            tail = node;
            return;
        }else{
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
    void output(){
        if(length == 0){
            std::cout<<"List is empty - nothing to output\n";
        }
        ListNode* count = head;
        for(int i = 0; i < length; i++){
            std::cout<<i<<":\t"<<count->value<<"\n";
            count = count->next;
        }
    }



};


#endif //OOPMKR_LIST_H
