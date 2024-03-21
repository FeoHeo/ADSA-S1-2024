#include <math.h>
#include <iostream>
#include <vector>


int main() {
    std::vector<int> vect = {0};
    vect.insert(vect.begin() , 1);

    for(int i=0 ; i<vect.size() ; i++) {
        std::cout << vect[i] << std::endl;
    }

    return 0;
}