#include <stdio.h>
#include <cs50.h>

int main(void){
    printf("\nHello! This application calculates how much water (in 16oz bottles) you use during your shower. \nPress enter to continue.");
    string enter = get_string();
    printf("%s\n", enter);
    
    printf("Enter the approximate time in minutes that it takes you to shower: ");
    int showerTime = get_int();
    int bottles = 12 * showerTime;
    printf("You use approximately %i 16oz bottles of water per shower! \n", bottles);
}

