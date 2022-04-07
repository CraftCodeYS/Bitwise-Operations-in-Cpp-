#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void printNum(int a);
void printBinary(int a);
void minBit(int a);
void maxBit(uint8_t a);
void getNBit(int a, int n);
void countValue(int a);
void twoComplement(int a);

int main()
{
    int b = 0;
    int n = 0;
    printf("Enter a number between 0 & 255: ");
    scanf("%d", &b);

    printf("Choose an n-th digit: ");
    scanf("%d", &n);
    printf("\n");

    //Get the n-te Bits?
    getNBit(b, n);

    //Print Number
    printNum(b);

    //Exercises
    minBit(b);
    maxBit(b);
    
    //Count the Zeros and Ones
    countValue(b);

    //Two´s Complement
    twoComplement(b);
}

void minBit(int a) {
    uint8_t min = 0b00000001;
    
    if (a & min) {
        printf("LSB: The Number have a min Bit!\n");
    }
    else {
        printf("LSB: The Number have no min Bit!\n");
    }
}

void maxBit(uint8_t a) {
    uint8_t max = 0b00000001;
    max = max << 7;

    if (a & max) {
        printf("MSB: The Number have a max Bit!\n");
    }
    else {
        printf("MSB: The Number have no max Bit!\n");
    }
    printf("\n");
}

//Print Number in Decimal, Hexa, Octal & Binary
void printNum(int a) {
    printf("Decimal:                      %d\n", a);
    printf("Hexadecimal:                  %x\n", a);
    printf("Octal:                        %o\n", a);
    printf("Binary:                       ");
    printBinary(a);
    printf("\n");
}

void printBinary(int a) {
    for (int i = 0; i < 8; i++) {
        if (a & 0b10000000) {
            printf("1");
        }
        else {
            printf("0");
        }
        a = a << 1;
    }
    printf("\n");
}

void getNBit(int a, int n) {
    uint8_t pos = 0b00000001;
    pos = pos << n;
    int result = a & pos;
    
    // Get specific value
    // a = a >> n;
    // a = a & pos;

    printf("The position of the n-th is:  ");
    printBinary(pos);
    printf("The result of the n-th is:    ");
    printBinary(result);
    printf("\n");
}

void countValue(int a) {
    uint8_t pos = 0b00000001;
    int countOne = 0;
    int countZero = 0;
    
    for (int i = 0; i < 8; i++) {
        if (a & pos) {
            countOne++;
        }
        else {
            countZero++;
        }
        a = a >> 1;
    }

    printf("Ones: %d, Zeros: %d", countOne, countZero);
    printf("\n");
}

void twoComplement(int a) {
    uint8_t binary = 0b00000001;

    a = ~a;
    a = a + binary;
    printf("Twos Complement: ");
    printBinary(a);
    
}
