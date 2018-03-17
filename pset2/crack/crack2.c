#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <unistd.h>

// string encryptString( string original ){
//     char saltKey[] = "50";
//     string encryptedString = crypt( original, saltKey);
    
//     return encryptedString;
// }


// for (int y = 33; y < 126; y++){
             
//             char yy = (char) y;
//             asciiCodeArray[x][z] = &yy;
//             string a = asciiCodeArray[x][z];
            
//             if ( strcmp(a, originString) == 0 ){
//                 printf("%s", a);
//             }
//             if ( strcmp(a, originString) != 0 ){
//                 baseArrayLength++;
//             }
// }
        
// printf("\n");

int compareCrackHash(){
    int matched = false;
    int x, y;
    int asciiCodeArray[4][93];

    for ( x = 0; x < 93; x++ ){
        asciiCodeArray[0][x] = x+33;
        asciiCodeArray[1][x] = x+33;
        asciiCodeArray[2][x] = x+33;
        asciiCodeArray[3][x] = x+33;
    }

    while(matched == false){
        for ( x = 0; x < 4; x++){
            for ( y = 0; y < 93; y++){
                printf( "%c", asciiCodeArray[x][y] );    
            }
            printf("\n");
        }
        
        matched = true;
    }
    return asciiCodeArray[0][0];
}

int main(int argc, string argv[]){

    compareCrackHash();
    
    printf( "\n%s\n", argv[1] );
    
    // return 0;   
}
