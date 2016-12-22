#include <iostream>
#include <random>
#include "ind.h"            // Class Indiviuum
#include "pop.h"            // Class Population
using namespace std;

// int solution [] {7,3,0,2,5,1,6,4};

int main() {
    // Initialsisiere Population, Parameter für Anzahl der Induviduuen
    pop *  Population = new pop(1);

    int probiere [] {7,3,4,2,5,1,6,4};
    ind test;
    test.fitness(probiere);
    int durchl = 200;
    // while (Population->get_best() || 0 >  --durchl) {
        //select(P);
        //pair(pop; new pop);
        //mutate(Population);
        //durchl--;
    //}
    //cout << best.pop;

    return 0;
}