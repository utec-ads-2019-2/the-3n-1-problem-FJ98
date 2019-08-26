#include <bits/stdc++.h>

void orderInput(int&, int&);
int getMaxCycle(int, int);
int threeNPlusOne(int);
void print(int, int, int);

int main() {
    int inferior, superior;

    while (std::cin >> inferior >> superior) {
        int maxCycle = getMaxCycle(inferior, superior);
        print(inferior, superior, maxCycle);
    }

    return 0;
}

void orderInput(int& inferior, int& superior){
    if (inferior > superior)
        std::swap(inferior, superior);
}

int getMaxCycle(int inferior, int superior){
    orderInput(inferior, superior);
    int maxCycle = 0;

    for (int i = inferior; i <= superior; ++i) {
        int cycle = threeNPlusOne(i);
        if (cycle > maxCycle) std::swap(cycle, maxCycle);
    }

    return maxCycle;
}

int threeNPlusOne(int number){
    int countSteps = 1;

    while (number != 1) {
        number = (number % 2 == 0) ? number / 2 : 3*number + 1;
        ++countSteps;
    }

    return countSteps;
}

void print(int inferior, int superior, int maxCycle){
    std::cout << inferior << " " << superior << " " << maxCycle << std::endl;
}