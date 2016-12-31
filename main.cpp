#include <iostream>
#include <random>
#include "ind.h"            // Class Indiviuum
#include "pop.h"            // Class Population
using namespace std;



int main() {
    pop *  Population = new pop(200);
    int solution [] {7,3,0,2,5,1,6,4};
    int probiere [] {7,3,4,2,5,1,6,4};
    ind * test = new ind(probiere);
    test->calfit();
    cout << "Fitness: " << test->get_fitness() << endl;


    int durchl = 200;
    double average_fitness = 0;
    while (Population->get_best_fitness()) {
        cout << Population->get_best_fitness() << "\n";
        Population->select();
        Population->pair();

        Population->mutiere();
        --durchl;
        cout << "Durchlaefe: " << durchl << "\n";
    }
    //Population->print();
    Population->get_best()->print();

    return 0;
}