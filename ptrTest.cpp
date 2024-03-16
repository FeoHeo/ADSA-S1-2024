#include <iostream>

int passPtr(int in);
int passPtr_mod(int* in_mod);

int main() {

    std::cout << passPtr(2) << std::endl;

    return 0;
}



int passPtr(int in) {
    int val = in;
    passPtr_mod(&val);
    return val;
}

int passPtr_mod(int* in_mod) {
    int* num = in_mod;
    *in_mod = 5;
    std::cout << "in_mod: " << *in_mod << std::endl;
}