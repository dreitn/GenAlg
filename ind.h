#ifndef GENALG_IND_H
#define GENALG_IND_H

class ind {

    static const int n{8};                          // n Zeilen/Spalten: 1-8; A-H
    int dna[n];                                     //
    int fit;
    double relative_fitness;

public:

    ind(int * fromDNA) {
        for (int i = 0; i < 8; i++) this->dna[i] = fromDNA[i];

        this->calfit();
    }
    ind() {
        for (int i = 0; i < n; i++) {
            dna[i] = rand() % 8;
            }
        this->calfit();
    };
    int * get_dna() {
        return this->dna;
    }
    int get_fitness() {
        return this->fit;
    }
    void set_fitness(int fit) {
        this->relative_fitness=fit;
    }
    float get_relfitness () {
        return this->relative_fitness;
    }
    void set_dna (int * parentab) {
        for (int i = 0; i < 8; i++){
            dna[i] = parentab[i];
        }
    }
    void set_relfitness (double relfit) {
        this->relative_fitness = relfit;
    }

    void calfit() {           // Berechne int Fitness, Bestmögliche Fitness = 0, Kollissionen dekerementieren Fitness
        fit = 0;

        int diff = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) { if (i != j) {
                    diff = (i+1)-(j+1);
                    if (dna[j] + diff == dna[i] || dna[j] == dna[i] || dna[j] - diff == dna[i]) fit--;
                    }
                }
            }
        };

    friend std::ostream& operator<<(std::ostream& os, ind & print);

    void print() {
        std::cout << "dna: ";
        for (int i = 0; i < 8; i++) {
            std::cout << dna[i] << " ";
        }
        std::cout << "fit: ";
            fit ? std::cout << fit << std::endl : std::cout << "Optimal" << std::endl;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                (dna[i] == j) ? std::cout << " + " : std::cout << " . ";
                if (j == 7) std::cout << std::endl;
            }
        }
    }
};

/* std::ostream& operator<<(std::ostream& os, const ind & print) {

    for (int i = 0; i < 200; i++){
        std::cout << "DNA[" << i << "] = ";
        for (int j = 0; j < 8; j++)
            std::cout << print.dna[i];
    }
}

 */



#endif //GENALG_IND_H