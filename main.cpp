#include "List.h"

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int main() {
    auto* linkedList = new List();
    for(int i = 0; i < 10; i++){
        linkedList->insert(0, fRand(0, 5));
    }
    std::cout << "10 Insertion in position 0\n";
    linkedList->output();

    double temp;
    for(int i = 1; i < 4; i++){
        temp = fRand(0, 5);
        linkedList->insert(i * 2, temp);
        std::cout << "Insertion of " << temp << " in position " << i * 2 << "\n";
        linkedList->output();
    }

    for(int i = 4; i > 0; i--){
        linkedList->erase(i * 2);
        std::cout << "Deletion in position " << i * 2 << "\n";
        linkedList->output();
    }


}
