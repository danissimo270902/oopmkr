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
        linkedList->output();
    }


}
