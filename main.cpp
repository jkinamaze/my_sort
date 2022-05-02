#include <iostream>
#include <stdlib.h>
#include <time.h>
void randomisation(int*, int, int, int);
void sort(int*, int);

int main() {
    int *a = nullptr;
    int n;
    std::cout << "How many numbers will be?";
    std::cin >> n;
    a = new int[n];
    int min, max;
    std::cout << "Input min number:";
    std::cin >> min;
    std::cout << "Input max number:";
    std::cin >> max;
    randomisation(a, n, min, max);
    std::cout << "Random mass: ";
    for (auto i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl << "Sort mass: ";
    sort(a, n);
    for (auto i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    delete []a;
}

void randomisation(int *mass, int n, int min, int max) {
    srand(time(NULL));
    int aver = (abs(min) + abs(max)) / 2;
    int range = abs(min) + abs(max);
    for (auto i = 0; i < n; ++i) {
        if (min < 0 && max > 0) mass[i] = (rand() % (range + 1)) - aver;
        else if (min == 0 && max > 0) mass[i] = rand() % (range + 1);
        else if (min < 0 && max == 0) mass[i] = (rand() % (range + 1)) - range;
        else if (min > 0 && max > 0) mass[i] = (rand() % ((max - min) + 1)) + min;
        else if (min < 0 && max < 0) mass[i] = (rand() % (abs(min) - abs(max) + 1)) + min;
      }
}

void sort(int* mass, int n) {
    int mass_sort[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        count = 0;
        for (int j = 0; j < n; j++) {
            if (mass[j] <= mass[i]) ++count;
        }
        for (int k = 0; k < n; ++k) {
            if (mass_sort[count - 1] == mass[k]) --count;
        }
        mass_sort[count - 1] = mass[i];
    }
    for (int i = 0; i < n; i++) {
        mass[i] = mass_sort[i];
    }
}