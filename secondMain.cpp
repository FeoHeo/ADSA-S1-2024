#include <iostream>
#include <string>
#include <math.h>
#include <vector>

//Functions used in main()
int schoolAdd(int I1_in, int I2_in);
int karatsubaMul(int I1_in, int I2_in, int B_in);
void vect_print(std::vector<int> p_input);
int schoolAdd_return(std::vector<int> I1_in , std::vector<int> I2_in , int B_in);

//QoL functions for 2 functions
std::vector<int> strToDigit(int num_input);
void strToDigit_return(int num_input, std::vector<int>* vectReturn);

int main() {
    int I2;
    int I1;

    //Takes I1, I2 and B input
    std::cout << "Input 1: "; std::cin >> I1;
    printf("\n");

    std::cout << "Input I2: "; std::cin >> I2;
    printf("\n");

    //Calling the functions to do the work
    std::cout << schoolAdd(I1,I2) << std::endl;
    return 0;
};


int schoolAdd(int I1_in , int I2_in) {

    //Throw error if I2_in == 0
    try {
        if(I2_in != 0) {
            std::cout << "Starting addition" << std::endl;
        } else {
            throw(I2_in);
        }
    }
    catch(int I2_in) {
        std::cout << "Error: I2 must not be 0 \n"
        << "I2 value: " << I2_in << std::endl;
    }
    
    int B;
    std::cout << "Input B: "; std::cin >> B;
    printf("\n");
    //Prepare to do the algorithm
    std::vector<int> I1_vect = strToDigit(I1_in);
    std::vector<int> I2_vect = strToDigit(I2_in);

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
        std::cout << "executing" << std::endl;
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

//Will return a vector of digits recursively
std::vector<int> strToDigit(int num_input) {
    std::vector<int> vectReturn;

    strToDigit_return(num_input , &vectReturn);
    return vectReturn;
};

void strToDigit_return(int num_input , std::vector<int>* vectReturn) {
    if(num_input >= 10) {
        strToDigit_return(num_input / 10 , vectReturn);
    }

    vectReturn->push_back(num_input % 10);

}