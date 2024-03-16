#include <iostream>
#include <string>
#include <math.h>
#include <vector>

//Functions used in main()
int schoolAdd(int I1_in, int I2_in , int B_in);
int karatsubaMul(int I1_in, int I2_in, int B_in);
int karatsubaMul_recurse(std::vector<int> I1_in , std::vector<int> I2_in , int B_in);
int schoolAdd_return(std::vector<int> I1_in , std::vector<int> I2_in , int B_in);
std::vector<int> extractVect(int pos_begin , int pos_end , std::vector<int> vect_in);

//QoL functions for 2 functions
std::vector<int> vectorOfDigits(int num_input);
void vectorOfDigits_return(int num_input, std::vector<int>* vectReturn);

int main() {
    int I2;
    int I1;
    int B;

    //Takes I1, I2 and B input
    std::cout << "Input 1: "; std::cin >> I1;
    printf("\n");

    std::cout << "Input I2: "; std::cin >> I2;
    printf("\n");

    std::cout << "Input Base: "; std::cin >> B;
    printf("\n");

    //Calling the functions to do the work
    std::cout << schoolAdd(I1,I2,B) << " " << karatsubaMul(I1,I2,B) << " " << 0 << std::endl;
    return 0;
};


int schoolAdd(int I1_in , int I2_in , int B_in) {
    
    int B = B_in;
    //Prepare to do the algorithm
    std::vector<int> I1_vect = vectorOfDigits(I1_in);
    std::vector<int> I2_vect = vectorOfDigits(I2_in);

    /*
    What will be done: Post_c_vect vector will be saved and added together with the c_vect
    */
   

    return schoolAdd_return(I1_vect , I2_vect , B);
};

//Implementing a Adder
int schoolAdd_return(std::vector<int> I1_in , std::vector<int> I2_in , int B_in) {
    int B_temp = B_in;
    int carry = 0;
    int add_return = 0;


    while(I1_in.size() != I2_in.size()) {   //Equalizes the size of both vectors
        if(I1_in.size() < I2_in.size()) {
            I1_in.insert(I1_in.begin() , 0);

        } else {
            I2_in.insert(I2_in.begin() , 0);

        }
    }

    for(int i=0 ; i<I2_in.size() ; i++) {
        add_return = add_return + ((I1_in[i] + I2_in[i] + carry) % B_temp) * pow(B_temp,i);
        carry = (I1_in[i] + I2_in[i] + carry) / B_temp;
        pow(B_temp,i);
    }

    return add_return;
}

//Doing Karatsuba Multiplication
int karatsubaMul(int I1_in , int I2_in , int B_in) {
    
    std::vector<int> I1_digits = vectorOfDigits(I1_in);
    std::vector<int> I2_digits = vectorOfDigits(I2_in);

    return karatsubaMul_recurse(I1_digits , I2_digits , B_in);
};

int karatsubaMul_recurse(std::vector<int> I1_in , std::vector<int> I2_in , int B_in) {
    int B_num = B_in;
    //Base case for the function
    if(I1_in.size() < 2 || I2_in.size() < 2) {
        return I1_in[0] * I2_in[0];
    };

    int maxDigit;
    //Calculate number of digits in the number
    if(I1_in.size() - I2_in.size() >= 0) {   //Take the largest amount of digits
        maxDigit = I1_in.size();
    } else {
        maxDigit = I2_in.size();
    }
    int halfDigit = maxDigit / 2;

    //Split the numbers
    std::vector<int> I1_high;
        I1_high = extractVect(halfDigit,maxDigit,I1_in);
    std::vector<int> I1_low;
        I1_low = extractVect(0,halfDigit,I1_in);
    std::vector<int> I2_high;
        I2_high = extractVect(halfDigit,maxDigit,I2_in);
    std::vector<int> I2_low;
        I2_low = extractVect(0,halfDigit,I2_in);

    int ac = karatsubaMul_recurse(I1_high , I2_high , B_num);
    int bd = karatsubaMul_recurse(I1_low , I2_low , B_num);
    int ad_bc = schoolAdd(karatsubaMul_recurse(I1_high,I2_low,B_num) , karatsubaMul_recurse(I2_high,I1_low,B_num) , B_num);
    // std::cout << "ac bd ad_bc: " << ac << " " << bd << " " << ad_bc <<  std::endl;

    int result = pow(B_in,maxDigit) * bd + pow(B_in,halfDigit) * ad_bc + ac;
    return result;
};






//Functions used for both algorithms
//Will return a vector of digits recursively
std::vector<int> vectorOfDigits(int num_input) {
    std::vector<int> vectReturn;

    vectorOfDigits_return(num_input , &vectReturn);
    return vectReturn;
};

void vectorOfDigits_return(int num_input , std::vector<int>* vectReturn) {
    if(num_input >= 10) {
        vectorOfDigits_return(num_input / 10 , vectReturn);
    }

    vectReturn->push_back(num_input % 10);
}

std::vector<int> extractVect(int pos_begin , int pos_end , std::vector<int> vect_in) {
    std::vector<int>::const_iterator begin = vect_in.begin() + pos_begin;
    std::vector<int>::const_iterator end = vect_in.begin() + pos_end;
    return {begin,end};
};

