#ifndef GENALG_POP_H
#define GENALG_POP_H

class pop {

    static const int size {200};
    static ind *best;
    ind *Induviduen;
    ind *buffer;

public:

    pop(int pop_size = 200) {
        Induviduen = new ind[pop_size];

        buffer = nullptr;
        best = Induviduen;

        for (int i = 0; i < pop_size; i++) {
            if (Induviduen[i].get_fitness() > best->get_fitness())
                best = &Induviduen[i];                                                                 // Set ind * best = best fitness in Population
        }

        double temp_bestfitness = (best->get_fitness());                                                // Besser "double" für die folgende Division

        for (int i = 0; i < size; i++) {
            Induviduen[i].set_relfitness(temp_bestfitness /
                                         Induviduen[i].get_fitness());                                  // Set relative Fitness to every single Induviduum
        }
    };

    int get_best_fitness() {
        return best->get_fitness();
    }

    double get_average() {
        double average = 0;

        for (int i = 0; i < size; i++) average += Induviduen[i].get_fitness();

        return average /= size;
}

    static ind *get_best() {
        return best;
    }

    void select() {                                                                                                     // Wählt Induvidien nach relativer fitess aus und kopiert in den buffer

        if (!buffer) buffer = new ind[size];                                                                                          // Sollte "leere" Induviduen erstellen, nicht den Standardkonstuktor verwernden!

        for (int i = 0, j = 0; j < size; i++) {
            if (rand() % 100 < (Induviduen[i % size].get_relfitness() * 100)) {
                buffer[j] = Induviduen[i % size];
                j++;
            }
        }
    }

    void pair() {                                                                                                       // Generiert aus den (Eltern) Induviduen im buffer 2 Kind Induvidiuen

        int * temp_parentA; int parentA[8];
        int * temp_parentB; int parentB[8];

        for (int i = 0; i < size; i ++) {
            temp_parentA = buffer[i].get_dna();
            temp_parentB = buffer[(i + 1) % 200].get_dna();
                for (int j = 0; j < 8; j++) {
                    parentA[j] = temp_parentA[j];
                    parentB[j] = temp_parentB[j];
            }

            int number = rand() % 8;

            int dna_bufferA [8];

            for (int i = 0; i < number; i++)
                dna_bufferA[i] = parentA[i];

            for (int i = number; i < 8; i++)
                dna_bufferA[i] = parentB[i];

            buffer[i].set_dna(dna_bufferA);
        }

        for (int i = 0; i < size; i++) {
            buffer[i].calfit();
        }
    }

    void mutiere(int p = 10) {                                                                                           // Variiert die Induvidien aus dem buffer

        for (int i = 0; i < size; i++) {
            ind selected = buffer[i];


            for (int j = 0; j < 8; j++) {
                if (rand() % 100 < p) {
                    (rand() % 100 < 50) ? selected.dna_plus(j) : selected.dna_minus(j);                                  // Increase or Decrease Selected DNA
                }
            }
            selected.calfit();

            Induviduen[i] = selected;
        }


        for (int i = 0; i < size; i++) {
            buffer[i].calfit();
        }

        for (int i = 0; i < size; i++) {                                                                                // function find best Induviduum in Population
            if (Induviduen[i].get_fitness() > best->get_fitness()) best = &Induviduen[i];
        }

        double temp_bestfitness = (best->get_fitness());                                                                // function calculiere relative fitness für Population

        for (int i = 0; i < size; i++) {
            Induviduen[i].set_relfitness(temp_bestfitness /
                                         Induviduen[i].get_fitness());                                                  // Set relative Fitness to every single Induviduum
        }
    }

    void print() {
        for (int i = 0; i < size; i++){
            std::cout << "i: " << i << " ";
            Induviduen[i].print();
        }
    }
    void debug_info (int durchl) {
        std::cout << "Generation: " << durchl << "\n";
        std::cout << "Beste Fitness: " << this->get_best_fitness() << " Durchschn. Fitness: "
             << this->get_average() << "\n";
    }
};
ind* pop::best = nullptr;

#endif //GENALG_POP_H