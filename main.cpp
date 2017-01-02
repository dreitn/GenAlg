#include <iostream>
#include <random>
#include <ctime>
#include "ind.h"            // Class Indiviuum
#include "pop.h"            // Class Population

using namespace std;


int main() {
    srand(time(0));
    bool debug = false;
    pop *  Population = new pop(200);


    int durchl = 0;

    while (Population->get_best_fitness() && durchl < 200) {
        Population->select();
        Population->pair();
        Population->mutiere();

        ++durchl;
        if (debug) Population->debug_info(durchl);
    }

    // Population->print();
    Population->debug_info(durchl);

    Population->get_best()->print();

    return 0;
}