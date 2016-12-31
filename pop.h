#ifndef GENALG_POP_H
#define GENALG_POP_H

class pop {

    static const int n {200};
    static ind *best;
    ind *Induviduen;
    ind *buffer;

public:

    pop(int size = 200) {
        Induviduen = new ind[size];

        buffer = nullptr;
        best = Induviduen;

        for (int i = 0; i < size; i++) {
            if (Induviduen[i].get_fitness() > best->get_fitness())
                best = &Induviduen[i];                                                                 // Set ind * best = best fitness in Population
        }

        double temp_bestfitness = (best->get_fitness());                                                // Besser "double" für die folgende Division

        for (int i = 0; i < n; i++) {
            Induviduen[i].set_relfitness(temp_bestfitness /
                                         Induviduen[i].get_fitness());                                  // Set relative Fitness to every single Induviduum
        }
        /* for (int i = 0; i < 200; i++) {
            std::cout << i << ": " << Induviduen[i].get_fitness() << "          " << Induviduen[i].get_relfitness() << std::endl;
        }
        std::cout << best->get_fitness() << "\n";
         */
    };

    int get_best_fitness() {
        return best->get_fitness();
    }

    static ind *get_best() {
        return best;
    }

    void set_best(ind *new_best) {
    }

    void select() {                                                                                                     // Wählt Induvidien nach relativer fitess aus und kopiert in den buffer
        // std::cout << "Select\n";

        if (!buffer) buffer = new ind[200];                                                                                          // Sollte "leere" Induviduen erstellen, nicht den Standardkonstuktor verwernden!


        for (int i = 0, j = 0; j < n; i++) {
            int test = rand() % 100;
            if (Induviduen[i % n].get_relfitness() * 100 > test) {
                buffer[j] = Induviduen[i % n];
                j++;
                //std::cout << "true\t";
            }
                //else std::cout << "false\t";

            /* std::cout << Induviduen[i % n].get_relfitness() * 100 << " > " << test << std::endl;
            if (j == 200) std::cout << "i: " << i << std::endl;
             */
        }

        /*for (int i = 0; i < 200; i++) {
            std::cout << i << ": " << buffer[i].get_fitness() << "          " << buffer[i].get_relfitness() << std::endl;
        }
        std::cout << best->get_fitness() << "\n";
         */
    }

    void pair() {                                                                                                       // Generiert aus den (Eltern) Induviduen im buffer 2 Kind Induvidiuen

        int * temp_parentA; int parentA[8];
        int * temp_parentB; int parentB[8];

        for (int i = 0; i < 200; i ++) {
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

        for (int i = 0; i < 200; i++) {
            buffer[i].calfit();
        }
    }

    void mutiere(int p = 2) {                                                                                           // Variiert die Induvidien aus dem buffer/Jedoch übernimmt nur positive dna änderungen

        for (int i = 0; i < n; i++) {
            ind selected = buffer[i];

            for (int i = 0; i < n; i++) {
                if (rand() % 100 < p) {
                    (50 < rand() % 100) ? selected.get_dna() : selected.get_dna();                                      // Increase or Decrease Selected DNA
                }
            }
            selected.calfit();

            (buffer[i].get_fitness() < selected.get_fitness()) ? Induviduen[i] = selected: Induviduen[i] = buffer[i];
        }
        for (int i = 0; i < 200; i++) {
            buffer[i].calfit();
        }
        for (int i = 0; i < 200; i++) {                                                                                 // function find best Induviduum in Population
            if (Induviduen[i].get_fitness() > best->get_fitness()) best = &Induviduen[i];
        }

        double temp_bestfitness = (best->get_fitness());                                                               // function calculiere relative fitness für Population

        for (int i = 0; i < n; i++) {
            Induviduen[i].set_relfitness(temp_bestfitness /
                                         Induviduen[i].get_fitness());                                                  // Set relative Fitness to every single Induviduum
        }
    }
    void print() {
        for (int i = 0; i < 200; i++){
            std::cout << "i: " << i << " ";
            Induviduen[i].print();
        }
    }
};

ind* pop::best = nullptr;

#endif //GENALG_POP_H
