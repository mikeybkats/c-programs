#include <stdio.h>
#include <cs50.h>

int main(void){
    printf("Enter a character type to build your pyramid: ");
    char charBlock = get_char();
    
    printf("Your character of choice is %c\n", charBlock);
    
    printf("Enter a pyramid height: ");
    int pyrHeight = get_int();
    
    if ( pyrHeight > 23 || pyrHeight <= 0) {
        do {
            printf("Enter a new height greater than 0 and less than 23: ");
            pyrHeight = get_int();
        }
        while( pyrHeight > 23 || pyrHeight <= 0 );
    }
    
    printf("The height of your pyramid will be %i lines high. \n", pyrHeight);
   
    for (int i = 0; i < pyrHeight; i++){
        int spacesBefore = pyrHeight - i - 1;
        int blocks = pyrHeight - spacesBefore;    
        int singleSpace = ' ';
        
        for (int x = 0; x < spacesBefore; x++){
            printf("%c", singleSpace);
        }
        
        for (int z = 0; z < blocks; z++){
            printf("%c", charBlock);
        }
    
        printf("%2c", singleSpace);
        
        for (int z = 0; z < blocks; z++){
            printf("%c", charBlock);
        }
        printf("\n");
    }
    return 1
}
