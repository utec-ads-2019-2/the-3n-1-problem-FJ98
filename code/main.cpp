#include <iostream>
#include <map>

using namespace std;

int threeNPlusOne(int number){
    std::map<int, int> dictionary;
    if (number == 1) { return 1; }
    else if (number % 2 != 0) {
        dictionary[number] = 1 + threeNPlusOne(3*number + 1);
    } else {
        dictionary[number] = 1 + threeNPlusOne(number / 2);
    }
    return dictionary[number];
}


int main() {
    int inferior, superior;

    for (int i = 0; i < 4; ++i) {
        std::cin >> inferior >> superior
    }
    while (std::cin >> inferior >> superior) {
        int start = inferior, stop = superior, maximo = -1;

        if (inferior > superior) { std::swap(inferior, superior); }

        for (int inferiorNumber = start; inferiorNumber <= stop; ++inferiorNumber) {
            maximo = std::max(maximo, threeNPlusOne(inferiorNumber));
        }

        std::cout << inferior << " " << superior << " " << maximo << std::endl;
    }

    return 0;
}