#include "ttt.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main( int argc, char **argv ){
  init_boards();
  init_board(START_BOARD);
  join_graph(START_BOARD);
  int numRight = 0;

  for (int i = 0; i < HSIZE; i++){ //pretty clear
    if (htable[i].init == 1){
      numRight++;
    }
  }

  printf("%d\n", numRight);
}
