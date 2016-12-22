#ifndef GENALG_POP_H
#define GENALG_POP_H

#endif //GENALG_POP_H


class pop {
    static const int n {1};
    static ind * best;
    ind * Induviduen;
    ind * buffer;

    public:
    pop(int size = 200) {
        Induviduen = new ind[size];
        best = Induviduen;
        for (int i = 0; i < n; i++) {
            if (Induviduen[i].get_fitness() > best->get_fitness()) *best = Induviduen[i];                                // Set ind * best = best fitness in Population
        }
        int temp_bestfitness = best->get_fitness();
        for (int i = 0; i < n; i++) {
            Induviduen[i].set_relfitness(temp_bestfitness/Induviduen[i].get_fitness());                                // Set relative Fitness to every single Induviduum
        }
   };

    int get_bestfitness() {
        return (get_best()->get_fitness());
    }
    static ind * get_best() {
        return best;
    }
    void set_best (ind * new_best) {
    }

    void select () {
    buffer = new ind[200];
        int j = 0;
        for (int i = 0; i < 200; i++) {
            if (Induviduen[j%200].get_relfitness()*100<rand()%1000)
                buffer[i] = Induviduen[i];
        }
    }
    void pair () {

    }
    void mutiere () {
        for (int i = 0; i < n; i++);
    }
};

//int Something::s_value = 1; // initializer

