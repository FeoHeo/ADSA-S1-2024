#Bugs

[Weird one]: if change the type of B (base) to uint_8 then the pow() would intepret B as 50 on the second call of 
for() loop. Here is the code:



    #include <iostream>
    #include <string>
    #include <math.h>
    #include <vector>

    //Functions used in main()
    int schoolAdd(int I1_in, int I2_in);
    int karatsubaMul(int I1_in, int I2_in, int B_in);
    void vect_print(std::vector<int> p_input);
    int schoolAdd_return(std::vector<int> I1_in , std::vector<int> I2_in , uint8_t B_in);

    //QoL functions for 2 functions
    std::vector<int> vectorOfDigits(int num_input);
    void vectorOfDigits_return(int num_input, std::vector<int>* vectReturn);

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
        
        uint8_t B;
        std::cout << "Input B: "; std::cin >> B;
        printf("\n");
        //Prepare to do the algorithm
        std::vector<int> I1_vect = vectorOfDigits(I1_in);
        std::vector<int> I2_vect = vectorOfDigits(I2_in);

        /*
        What will be done: Post_c_vect vector will be saved and added together with the c_vect
        */
    

        return schoolAdd_return(I1_vect , I2_vect , B);
    };

    //Implementing a Adder
    int schoolAdd_return(std::vector<int> I1_in , std::vector<int> I2_in , uint8_t B_in) {
        uint8_t B_temp = B_in;
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


#Algos

So to implement the Karatsuba algorithm, we will need to 3 inputs form the user: I1 , I2 , B.

We already got the function to turn each number digits into a vector<int> so got a head-start, only need to implement the function in.

Pseudocode:

        function karatsuba(x, y):
    if x < 10 or y < 10:  // Base case: if either x or y is a single digit number
        return x * y

    // Calculate the number of digits in the numbers
    n = max(digits(x), digits(y))
    m = n / 2

    // Split the numbers into halves
    x_high = high_half(x, m)
    x_low = low_half(x, m)
    y_high = high_half(y, m)
    y_low = low_half(y, m)

    // Recursively compute the three multiplications
    z0 = karatsuba(x_low, y_low)
    z1 = karatsuba(x_low + x_high, y_low + y_high)
    z2 = karatsuba(x_high, y_high)

    // Combine the results
    return (z2 * 10^(2 * m)) + ((z1 - z2 - z0) * 10^m) + z0

    function high_half(num, length):
    // Returns the high half of a number
    return num / 10^length

    function low_half(num, length):
    // Returns the low half of a number
    return num % 10^length

