#include <stdio.h>
#include <stdint.h>

typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;

int main(int argc, char *argv[]){
  (void)argc;
  (void)argv;

  BYTE g = 'F';
  DWORD gg = 4294967295;
  printf("Size of BYTE: %lu\n", sizeof(g));
  printf("Size of DWORD: %lu\n", sizeof(gg));
  printf("Size of LONG: %lu\n", sizeof(LONG));
  printf("Size of WORD: %lu\n", sizeof(WORD));
}
