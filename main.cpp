#include <iostream>
#include <string>
#include <math.h>
#include <vector>

//Functions used in main()
std::string schoolAdd(std::string I1_in, std::string I2_in , int B_in);
std::string karatsubaMul(std::string I1_in, std::string I2_in, int B_in);
std::vector<int> karatsubaMul_recurse(std::vector<int> I1_in , std::vector<int> I2_in , int B_in);
std::vector<int> schoolAdd_return(std::vector<int> I1_in , std::vector<int> I2_in , int B_in);
std::vector<int> extractVect(int pos_begin , int pos_end , std::vector<int> vect_in);

//QoL functions for 2 functions
std::vector<int> strToDigit(std::string num_input);
void strToDigit_return(int num_input, std::vector<int>* vectReturn);

int main() {
    std::string I2;
    std::string I1;
    int B;

    //Takes I1, I2 and B input
    std::cin >> I1;

    std::cin >> I2;

    std::cin >> B;

    //Calling the functions to do the work
    std::cout << schoolAdd(I1,I2,B) << " " << karatsubaMul(I1,I2,B) << " " << 0 << std::endl;
    return 0;
};


std::string schoolAdd(std::string I1_in , std::string I2_in , int B_in) {
    
    int B = B_in;
    //Prepare to do the algorithm
    std::vector<int> I1_vect = strToDigit(I1_in);
    std::vector<int> I2_vect = strToDigit(I2_in);
    /*
    What will be done: Post_c_vect vector will be saved and added together with the c_vect
    */
   std::string add_return;
   std::vector<int> add_return_vect = schoolAdd_return(I1_vect, I2_vect, B_in);

   for(int i = 0 ; i<add_return_vect.size() ; i++) {
    add_return += std::to_string(add_return_vect[i]);
   }

    return add_return;
};

//Implementing a Adder
std::vector<int> schoolAdd_return(std::vector<int> I1_in , std::vector<int> I2_in , int B_in) {
    int B_temp = B_in;
    int carry = 0;
    int temp_sum = 0;
    std::vector<int> add_return;


    while(I1_in.size() != I2_in.size()) {   //Equalizes the size of both vectors
        if(I1_in.size() < I2_in.size()) {
            I1_in.insert(I1_in.begin() , 0);

        } else {
            I2_in.insert(I2_in.begin() , 0);

        }
    }

    for(int i=0 ; i<I1_in.size() ; i++) {
        temp_sum = I1_in[i] + I2_in[i] + carry;
        carry = temp_sum / B_temp;

        int digit = temp_sum % B_temp;
        add_return.push_back(digit);

    }


    return add_return;
}

//Doing Karatsuba Multiplication
std::string karatsubaMul(std::string I1_in , std::string I2_in , int B_in) {
    
    std::vector<int> I1_digits = strToDigit(I1_in);
    std::vector<int> I2_digits = strToDigit(I2_in);

    
    std::string mul_return;
    std::vector<int> mul_return_vect = karatsubaMul_recurse(I1_digits , I2_digits , B_in);

    for(int i=0 ; i<mul_return_vect.size() ; i++) {
        mul_return += std::to_string(mul_return_vect[i]);
    }

    return mul_return;
}

std::vector<int> karatsubaMul_recurse(std::vector<int> I1_in , std::vector<int> I2_in , int B_in) {
    std::vector<int> result;
    int B_num = B_in;
    //Base case for the function
    if(I1_in.size() < 2 || I2_in.size() < 2) {
        result.push_back(I1_in[0] * I2_in[0]);
        return result;
    };

    int maxDigit;
    //Calculate number of digits in the number
    if(int(I1_in.size()) - int(I2_in.size()) >= 0) {   //Take the largest amount of digits, I put type int here cause sometimes it is interpretted as another type, causing issues
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

    std::vector<int> bd = karatsubaMul_recurse(I1_low , I2_low , B_num); //First num
    std::vector<int> ac = karatsubaMul_recurse(I1_high , I2_high , B_num);   //Final num
    std::vector<int> ad_bc = schoolAdd_return(karatsubaMul_recurse(I1_high,I2_low,B_num) , karatsubaMul_recurse(I2_high,I1_low,B_num) , B_num); // Middle num
    // std::cout << "ac bd ad_bc: " << ac << " " << bd << " " << ad_bc <<  std::endl;

    result.insert(result.end(), bd.begin() , bd.end());
    result.insert(result.end(), ad_bc.begin() , ad_bc.end());
    result.insert(result.end(), ac.begin() , ac.end());
    return result;
};






//Functions used for both algorithms
//Will return a vector of digits recursively
std::vector<int> strToDigit(std::string str_input) {
    std::vector<int> vectReturn;

    for(int i=0 ; i<str_input.size() ; i++) {
        vectReturn.push_back(str_input[i]-48);
    }
    return vectReturn;
};

std::vector<int> extractVect(int pos_begin , int pos_end , std::vector<int> vect_in) {
    std::vector<int>::const_iterator begin = vect_in.begin() + pos_begin;
    std::vector<int>::const_iterator end = vect_in.begin() + pos_end;
    return {begin,end};
};

