// Donald Marovich IFT 510 Fall 2019
// References: 
// https://www.geeksforgeeks.org/binary-representation-of-a-given-number/

#include <stdio.h>

//creating a structure we can call later
struct raw_float_struct {
    unsigned int mantissa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
};

//creating a mixed variable type for our input to be stored into
union mixer {
    float float_value;
    struct raw_float_struct raw;
};


//our operation of dividing the rhs by 2 
void bin(unsigned int n)
{
    if (n > 1)
        bin(n/2);
    printf("%d", n % 2);
}


int main(int argc, const char * argv[]) {
    
    union mixer user_value;
    
    printf("Enter a float value\n");
    
    //taking user input
    scanf("%f", &user_value.float_value);
    
    //printf("user_value is %f\n", user_value.float_value);
    
    //("raw mantissa = %d\n", user_value.raw.mantissa);
    
    //printf("raw exponent = %d\n", user_value.raw.exponent);
    
    //printf("raw sign = %d\n", user_value.raw.sign);
    
    printf("mantissa : ");
    bin(user_value.raw.mantissa);
    printf("\n");
    
    printf("exponent : ");
    bin(user_value.raw.exponent);
    printf("\n");
    
    printf("sign : ");
    bin(user_value.raw.sign);
    printf("\n");

    printf("full binary: ");
    bin(user_value.raw.sign);
    bin(user_value.raw.exponent); 
    bin(user_value.raw.mantissa);
    printf("\n");
    
    return 0;
}
