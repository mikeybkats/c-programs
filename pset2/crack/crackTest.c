#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <unistd.h>

string encryptString( string original ){
    char saltKey[] = "50";
    printf("%s\n", &original[0]);
    printf("%s\n", &original[1]);
    string encryptedString = crypt( &original[0], saltKey);

    // printf("%s\n", encryptedString);    
    
    return encryptedString;
}

int compareCrackHash( int arrayLength, string comparisonString ){
    
    
    for (int x = 0; x < arrayLength; x++){
        string asciiCodeArray[x][93];
        for (int y = 33; y < 126; y++){
            int z = 0; 
            char yy = (char) y;
            asciiCodeArray[x][z] = &yy;
            
            string a = asciiCodeArray[x][z];
            
            // char c = (char) a;
            
            printf( "%s", a );
           
            z++;
        }
        
        printf("\n");
    }
    
    return false;
}

// int compareEncryptions( const char *original, const char *crack ){
    
//     char saltKey[] = "50";
    
//     char *encryptedString = crypt( original, saltKey);
//     char *crackString = crypt( crack, saltKey);
    
//     if ( crackString == encryptedString ){
//         printf("%s\n", crackString);
//         printf("%s\n", crack);
//         return true;
//     }else{ return false; };

    
// }




int main(int argc, string argv[]){
    printf("%s\n", argv[1]);
    
    // encryptString( argv[1] );
    
    compareCrackHash( 1, argv[1] );
    
    // printf("%s\n", encryptString( argv[1] ));
    return 0;   
}
