#include "ttt.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main( int argc, char **argv ){
  init_boards();
  init_board(START_BOARD);
  join_graph(START_BOARD);
  compute_score();

  for (int i = 1; i < argc; i++){
    int hash = atoi(argv[i]); //get hash from cmd line
    print_node(htable[hash]);
  }
}
