#ifndef AIZO_PROJEKT1_SORTALGORITHM_H
#define AIZO_PROJEKT1_SORTALGORITHM_H

#include <vector>

// klasa rodzic dla wszystkich algorytmów sortowania
template<typename T> class SortAlgorithm
{
public:
    virtual void sort(T* data, int size) = 0;
};

#endif //AIZO_PROJEKT1_SORTALGORITHM_H