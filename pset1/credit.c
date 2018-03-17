#include <cs50.h>
#include <stdio.h>
#include <math.h>

// American Express uses 15-digit numbers, American Express numbers all start with 34 or 37
// MasterCard uses 16-digit numbers, MasterCard numbers all start with 51, 52, 53, 54, or 55
// Visa uses 13- and 16-digit numbers, Visa numbers all start with 4

int cardLength;

int getFirstDigit(long long x){
    return floor(llabs(x) / pow( 10, cardLength-1 ));
}

int getFirstTwoDigit(long long x){
    return floor(llabs(x) / pow( 10, cardLength-2 ));
}

int getCardLength(long long x){
    return floor(log10(llabs(x))) + 1;
}

int validateCardNumber(long long x){
    long long cardNumber = llabs(x);
    int finalOddDigit = 0;
    int finalEvenDigit = 0;
    
    for (int digitPos = 0; digitPos < cardLength; digitPos++) {
            long long digit = cardNumber;
            digit = x % 10; /* first digit */
            
            if (digitPos >= 0 && digitPos % 2 != 1 ){
                digit = x / (pow(10, digitPos));
                digit = digit % 10;
                // printf("even digit %lld\n", digit);
                
                finalEvenDigit = digit + finalEvenDigit;
            }
            
            if (digitPos > 0 && digitPos % 2 == 1){ 
                digit = x / (pow(10, digitPos));
                digit = digit % 10;
                int newDigit = digit * 2;
                
                if (newDigit >= 10 ){
                    // printf("new digit %i\n", newDigit);
                    int newDigit1 = newDigit % 10;
                    int newDigit2 = floor(newDigit / 10);
                    newDigit2 = newDigit2 % 10;
                    newDigit = newDigit1 + newDigit2;
                }

                finalOddDigit = newDigit + finalOddDigit;
            }
            
    }
    // printf("the sum of all the odd digits is %i\n", finalOddDigit);
    // printf("the sum of all the even digits is %i\n", finalEvenDigit);
    int finalDigit = finalEvenDigit + finalOddDigit;
    // printf("the sum of all the digits is %i\n", finalDigit);
    if (finalDigit % 10 != 0){
        printf("INVALID\n");
        return 0;
    }
    return 1;
}

long long getCardNumber(){
    printf("Please enter a credit card number for validation: ");
    long long x = get_long_long();
    cardLength = getCardLength(x);
    if ( cardLength < 13 ){
        do {
            printf("Not a credit card number please enter a different number: \n");
            x = get_long_long();
            cardLength = getCardLength(x);
        }while( cardLength < 13 );
    }
    return x;
}

long long identifyCardType(long long cardNumber){
    cardLength = getCardLength(cardNumber);
    if ( cardLength < 13 ){
        do {
            printf("Not a credit card number please enter a new value\n");
            cardNumber = get_long_long();
            cardLength = getCardLength(cardNumber);
        }while( cardLength < 13 );
    }
    
    int firstDigit = getFirstDigit(cardNumber);

    int firstTwo = getFirstTwoDigit(cardNumber);

    if ( cardLength == 15 || firstTwo == 34 || firstTwo == 37 ){    
        printf("AMEX\n");
    };
    
    if ( cardLength == 16 || cardLength == 13){
        if ( firstDigit == 5 && firstTwo > 50 && firstTwo < 56 ){
            printf("MASTERCARD\n");
        }
         if ( firstDigit == 4 || cardLength == 13 ){
            printf("VISA\n");
        }
    }
    return cardLength;
}

int main(void){
    long long cardNumber = getCardNumber();
    int validitedCard = validateCardNumber(cardNumber);
    if (validitedCard == 1){ 
        identifyCardType(cardNumber);
    }
}


    

