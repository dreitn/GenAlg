#ifndef GENALG_IND_H
#define GENALG_IND_H

#endif //GENALG_IND_H


class ind {
    static const int n{8};                          // n Zeilen/Spalten: 1-8; A-H
    int dna[n];                                     //
    int fit;
    float relative_fitness {0};

    public:
    ind() {
        for (int i = 0; i < n; i++) {
            dna[i] = rand() % n;

            this->fit = fitness(dna);
        }
    };

    int get_fitness() {
        return fit;
    }
    void set_fitness(int fit) {
        this->relative_fitness=fit;
    }
    float get_relfitness () {
        return relative_fitness;
    }
    void set_relfitness (float relfit) {
        this->relative_fitness = relfit;
    }

    int fitness (int * dna) {           // Return int Fitness, Bestmögliche Fitness = 0, Kollissionen dekerementieren Fitness
        int fitness = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) { if (i != j) {
                    if (dna[i] - (j-i) == dna[i])           std::cout << "case 1" << std::endl, fitness--;
                    if (dna[j] == dna[i])                   std::cout << "case 2" << std::endl, fitness--;
                    if (dna[i] + (j-i) == dna[i])           std::cout << "case 3" << std::endl, fitness--;
                    if (false) {
                    std::cout << i + 1 << " i = " << " " << dna[i] << '\t' << j + 1 << " j = " << " " << dna[i] - (j-i) << " " << dna[i] << " " << dna[i] + (j-i) << std::endl;
                        }
                    if (j == n-1) std::cout << std::endl;
                    }
                }
            }

        std::cout << "cnt: " << fitness << std::endl;
        return fitness;

    };
};