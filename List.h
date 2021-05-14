//
// Created by danis on 14.05.2021.
//

#ifndef OOPMKR_LIST_H
#define OOPMKR_LIST_H


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

public:

    List(){
        head = nullptr;
        tail = nullptr;

    }

    ~List() = default;


};


#endif //OOPMKR_LIST_H
