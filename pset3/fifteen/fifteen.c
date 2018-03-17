/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9
#define blankTile 0
// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool won(void);
bool move(int tile);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);
        

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        //testWon();
        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
   int j;
   int k; 
   int i = d*d-1;
   for(j = 0; j < d; j++){
    for(k = 0; k < d; k++){
        if(i != blankTile){ 
          board[j][k] = i;
          i--;
        }
      }
   }
   board[d-1][d-1] = blankTile;

   if(d%2==0){
      board[d-1][d-3] = 1;
      board[d-1][d-2] = 2;
   }
 }

/**
 * Prints the board in its current state.
 */
void draw(void)
{
   int j;
   int k; 
   for(j = 0; j < d; j++){
     for(k = 0; k < d; k++){
       if( board[j][k] != 99 && board[j][k] != blankTile ){
         printf("%2i ", board[j][k]);
         continue;
       }
      if( board[j][k] == blankTile ){ 
         printf(" _ ");
         continue;
      }    
     }
     printf("\n");
   }
}

int search(int value, int values[], int n)
{
  for( int i = 0; i < n; i++ ){
      if ( value == values[i] ){
          return i;
      }
  }
  return 99;
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO
    int result;
    int lengthOfArray = d;
    int tileLocation[2];
    int blankLocation[2];
    // printf("Tile: %i\n", tile);
    // first search for the tile to find a [y][x] location
    for(int y = 0; y < d; y++){ 
      result = search(tile, board[y], lengthOfArray);
      
      if( result >= 0 && result < d*d ){
        tileLocation[0] = y;
        tileLocation[1] = result;
        break;
      }
      
      if( y == d-1 && result > d*d ){
        break;
      }
    }
    // printf("tile location: [%i], [%i]\n", tileLocation[0], tileLocation[1]);

///////////////////////// aaaaaaaahhhhhhhh........////////////////////
    for(int y = 0; y < d; y++){
      result = search( blankTile, board[y], lengthOfArray);
    //   printf("%i, %i\n ", y, result);
      
      if( result >= 0 && result < d*d ){
        blankLocation[0] = y;
        blankLocation[1] = result;
        break;
      }
      
      if( y == d-1 && result > d*d ){
        break;
      }
    }
    
    // printf("blank location: [%i], [%i]\n", blankLocation[0], blankLocation[1]);
    // usleep(2000000);

    //determine which moves are legal moves
    if (  (blankLocation[0]-1 == tileLocation[0] && blankLocation[1]-1 == tileLocation[1]) ||
          (blankLocation[0]+1 == tileLocation[0] && blankLocation[1]+1 == tileLocation[1]) ||        
          (blankLocation[0]-1 == tileLocation[0] && blankLocation[1]+1 == tileLocation[1]) ||
          (blankLocation[0]+1 == tileLocation[0] && blankLocation[1]-1 == tileLocation[1]) 
        ){
      return false;
    }
    
    // blankLocation[0] = 2, blankLocation[1] = 2, blank=[2][2];
    // tileLocation[0] = 1, tileLocation[1] = 2, tile=[1][2];
     
    if ( (blankLocation[0]-1 == tileLocation[0] || blankLocation[1]-1 == tileLocation[1]) ||
         (blankLocation[0]+1 == tileLocation[0] || blankLocation[1]+1 == tileLocation[1])
        ){
    //   //swap the tiles
      int tempValue = board[tileLocation[0]][tileLocation[1]];
      board[tileLocation[0]][tileLocation[1]] = board[blankLocation[0]][blankLocation[1]];    
      board[blankLocation[0]][blankLocation[1]] = tempValue;
      return true;
    }

    return false;
}

void sort(int values[], int lengthOfArray)
{ 
    for ( int i = 0; i < lengthOfArray-1; i++){
        int startPosition = i;
        int smallestNumber = values[startPosition];
        int smallestNumberPosition = startPosition;
        int k;
        for( k = startPosition; k < lengthOfArray; k++){
           if ( values[k] < smallestNumber ){
               smallestNumberPosition = k;
               smallestNumber = values[k];
           }
        }
        int min = smallestNumberPosition;
        int tempValue = values[i];
        values[i] = values[min];
        values[min] = tempValue;
    }
}
/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int i;
    int j;
    int count = 0;
    
    for ( j = 0; j < d; j++){  
      for ( i = 0; i < d; i++){
        //printf("%i, ", board[j][i]);
        if( (j == d-1 && i == d-1) && (board[d-1][d-1] == blankTile) ){
            count++;
            continue;
        }
        
        if( board[j][i] < board[j][i+1] ){
            count++;
            continue;
        }
       
      }
    }
    printf("\ncount: %i\n", count);
        
    if( count == (d-1)*(d) ){
        return true;
    }
    return false;
 }

// void testWon(void) {
//  int i, j;
//  for( j = 0; j < d; j++ ){
//   for( i = 0; i < d; i++ ){
//      board[j][i] = wonBoard[j][i]; 
//   }
//  }
// }

