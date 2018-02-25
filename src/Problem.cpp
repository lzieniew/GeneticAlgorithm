#include "Problem.h"

int Problem::getN() {
    return this->N;
}


Problem::Problem(std::vector<int> input) {
    N = input[0];
    std::vector<int> flowVector;
    std::vector<int> distanceVector;
    for (int i = 1; i < N*N+1; i++){
        distanceVector.push_back(input.at(i));
    }
    for(int i = N*N + 1; i < input.size(); i++){
        flowVector.push_back(input[i]);
    }
    this->flowMatrix = new SquareMatrix(N, flowVector);
    this->distanceMatrix = new SquareMatrix(N, distanceVector);
}

SquareMatrix *Problem::getFlowMatrix() {
    return this->flowMatrix;
}

SquareMatrix *Problem::getDistanceMatrix() {
    return this->distanceMatrix;
}

int Problem::costFunction(Result &) {
    return 0;
}