#include <stdio.h>

// ------------------- TASK 2 ------------------- //

int main() {
    userInputForClosestNumber();
    return 0;
}

struct FibonacciPair{
    unsigned long number;
    unsigned long long value;
};

struct FibonacciPair generateNextFibonaciiPair(struct FibonacciPair currentPair, struct FibonacciPair previousPair){
    struct FibonacciPair fPair;
    fPair.value = previousPair.value + currentPair.value;
    fPair.number = currentPair.number + 1;
    return fPair;
}

struct FibonacciPair closer(long long inputNumber){

    struct FibonacciPair previousPair;
    previousPair.number = 1;
    previousPair.value = 1;

    struct FibonacciPair currentPair;
    currentPair.number = 2;
    currentPair.value = 1;

    if (inputNumber <= 1){;
        return previousPair;
    }

    while (currentPair.value < inputNumber) {
        struct FibonacciPair tmpPair = generateNextFibonaciiPair(currentPair, previousPair);
        previousPair = currentPair;
        currentPair = tmpPair;
    }

    return ( (currentPair.value - inputNumber) < (inputNumber - previousPair.value) ) ? currentPair : previousPair;
}

userInputForClosestNumber(void){
    printf("Enter a number for closest match: ");
    long long inputNumber = 0;
    scanf("%lld", &inputNumber);
    struct FibonacciPair fPair = closer(inputNumber);
    printf("\nThe closest fibonacci number is %llu at position %lu \n", fPair.value, fPair.number);
}
