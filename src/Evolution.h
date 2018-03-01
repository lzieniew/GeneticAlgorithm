#pragma once

#include "Result.h"
#include "Problem.h"
#include <vector>

class Evolution{
public:
    Evolution(int pop_size, int gen, float px, float pm, int tour, std::string filename);
    virtual ~Evolution();
    int get_pop_size();
    int get_gen();
    float get_px();
    float get_pm();
    int get_tour();
    Problem* getProblem();
    std::vector<Result*>* getPopulation();
    void step();

    static void crossover(Result &result, Result &r2);

private:
    int pop_size;
    int gen;
    float px;
    float pm;
    int tour;
    std::vector<Result*>* population;
    Problem* problem;
};