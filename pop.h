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
            Induviduen[i].set_relfitness(temp_bestfitness/Induviduen[i].get_fitness());                                  // Set relative Fitness to every single Induviduum
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

        int * dna = buffer[i].get_dna();
        int * dna = buffer[i+1].get_dna();

        int number = rand()%8;

        for (int i = 0; i < number; i++) {
            buffer[i] = dna[i];
        }
        for (int i = number; i < 8; i++){
            buffer[i] = dna[i];
        }

    }
    void mutiere (int p = 2) {
        for (int i = 0; i < n; i++);

        ind selected_ind = buffer[i];

        int * dna = selected_ind.get_dna();
            for (int i = 0; i < 8; i++) {
                if (p < rand()%100) {
                    (50 < rand()%100) ? dna[i] : dna[i];
                }
            }
        if (buffer[i].get_fitness() < dna.get_fitness()) { buffer[i] = dna };
    }
    delete[] buffer;
};

ind* pop::best = nullptr;
