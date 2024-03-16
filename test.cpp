#include <math.h>
#include <iostream>
#include <vector>


int main() {
    std::vector<int> bigVect = {1,0};
    std::vector<int>::const_iterator b = bigVect.begin()+1;
    std::vector<int>::const_iterator e = bigVect.begin()+2;
    std::vector<int> newVect = {b,e};
    for(int i=0 ; i<newVect.size() ; i++) {
        std::cout << newVect[i] << std::endl;
    }
    return 0;
}