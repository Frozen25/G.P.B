class Population {

    Individual[] individuals;

    /*
     * Constructors
     */
    // Create a population

    public:



        Population(int populationSize, boolean initialise) {
            individuals = new Individual[populationSize];
            // Initialise population
            if (initialise) {
                // Loop and create individuals
                for (int i = 0; i < size(); i++) {
                    Individual newIndividual = new Individual();
                    newIndividual.generateIndividual();
                    saveIndividual(i, newIndividual);
                }
            }
        }

       /* Getters */
        Individual getIndividual(int index) {
            return individuals[index];
        }

        Individual getFittest() {
            Individual fittest = individuals[0];
            // Loop through individuals to find fittest
            for (int i = 0; i < size(); i++) {
                if (fittest.getFitness() <= getIndividual(i).getFitness()) {
                    fittest = getIndividual(i);
                }
            }
            return fittest;
        }

    /* Public methods */
    // Get population size
        int size() {
            return individuals.length;
        }

    // Save individual
        void saveIndividual(int index, Individual indiv) {
        individuals[index] = indiv;
        }
    }