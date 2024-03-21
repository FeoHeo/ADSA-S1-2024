#include <math.h>
#include <iostream>
#include <vector>


int main() {
    std::vector<int> newVect = {2,3};
    std::string test = "24";

    for(int i=0 ; i<test.size() ; i++) {
        newVect.push_back(test[i] - 48);
    }


    for(int i=0 ; i<newVect.size() ; i++) {
        std::cout << newVect[i] << std::endl;
    }
    

    return 0;
}