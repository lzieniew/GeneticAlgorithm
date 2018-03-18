#include "Result.h"
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include "Random.h"


Result::Result(std::vector<int> input) {
    this->res = input;
    this->N = input.size();
}

std::vector<int> Result::getVector() {
    return res;
}

Result::Result(int N) {
    this->N = N;
    this->res = std::vector<int>();
    for(int i = 0; i < N; i++){
        res.push_back(i);
    }
    std::random_shuffle(res.begin(), res.end());
}

void Result::mutate(double probability) {
    for(int i = 0; i < this->res.size(); i++){
        if(random_float(1.0) > probability){
            this->flip(i);
        }
    }
}

void Result::flip(int index){
    int random_index_second = random_int(N);
    while(index == random_index_second){
        random_index_second = random_int(N);
    }
    int first = res.at(index);
    int second = res.at(random_index_second);
    res[index] = second;
    res[random_index_second] = first;
}

//TODO: debug crossover
Result* Result::crossover(Result* other, double probability){
    Result *result1 = this;
    Result *result2 = other;

    std::vector<int> myNewGenes = res;
    std::vector<int> othersNewGenes = other->res;

    float rand = random_float(1.0);
    if(rand < probability){
        int position = random_int(N);

        for(int i = position; i < other->N; i++){
            myNewGenes[i] = other->res[i];
            othersNewGenes[i] = this->res[i];
        }
        result1->res = myNewGenes;
        result2->res = othersNewGenes;
    }

    result1->repair();
    result2->repair();

    return result2;
}

std::string Result::toString() {
    std::string result = "Result [";
    for(auto i : res){
        result += std::to_string(i) + ", ";
    }
    result += "]";
    return result;
}

bool Result::check_unique_values() {
    std::set<int> s;
    for(auto a : this->res){
        s.insert(a);
    }
    return s.size() == res.size();
}

int Result::findByValue(int value) {
    for (int i = 0; i < N; i++) {
        if (res[i] == (int) value)
            return i;
    }
    return -1;
}

Result& Result::repair(){
    for(int i = 0; i < N; i++) {
        for(int j = N; j > 0; j--){
            int number = -2;
            for(int k = 0; k < N; k++){
                if(findByValue(k) == -1) number = k;
            }
            if(findByValue(i) == findByValue(j) && number != -2)
                res[j] = number;
        }
    }
}
