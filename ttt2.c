#include "ttt.h"
#include <string.h>
#include <stdio.h>

void init_boards(){
  for (int i = 0; i < HSIZE; i++){  //initialize
    htable[i].init = 0;
  }
}

int depth(Board board){
  int markers = 0;
  for (int i = 0; i < BSIZE; i++){
    if (board[i] == 'X' || board[i] == 'O' ){
      markers++;  //add to markers
    }
  }
  return markers;
}

char winner(Board board){

  for (int i = 0; i < 8; i++){
    if ((board[pos2idx[WINS[i][0]]] == board[pos2idx[WINS[i][1]]]) && (board[pos2idx[WINS[i][0]]] == board[pos2idx[WINS[i][2]]])){
      return board[pos2idx[WINS[i][0]]];  //if the spots are the same, return whats in them
    }
  }

  if (depth(board)<9){
    return '?'; //or if its still going
  } else {
    return '-'; //done
  }
}

char turn(Board board){
  if (depth(board) == 9){ //game done
    return '-';
  }

  if (depth(board)%2 == 0){//is X's turn
    return 'X';
  }
  return 'O'; //else
}

void init_board(Board board){
  int hash = board_hash(board);

  htable[hash].init = 1;
  htable[hash].turn = turn(board);
  htable[hash].depth = depth(board);
  strcpy(htable[hash].board, board);
  htable[hash].winner = winner(board);
}

void join_graph(Board board){
  int hash = board_hash(board);
  Board brdcpy;
  int exits = 0;

  if (winner(board) != '?'){  //game is done
    exits = 1;
    for (int j = 0; j < 9; j++){
      htable[hash].move[j] = -1;  //no more moves
    }
  }

  if (exits == 0){
    for (int i = 0; i < 9; i++){
      if (board[pos2idx[i]] == 'X' || board[pos2idx[i]] == 'O'){
        htable[hash].move[i] = -1;
      } else{
        strcpy(brdcpy,board);
        brdcpy[pos2idx[i]] = turn(brdcpy);
        int newHash = board_hash(brdcpy);
        htable[hash].move[i] = newHash;
        if (htable[newHash].init == 0){ //recursion
          init_board(brdcpy);
          join_graph(brdcpy);
        }
      }
    }
  }
}

void compute_score(){
  for (int i = 0; i < HSIZE; i++){
    if (htable[i].init == 1){
      if (winner(htable[i].board) == 'X'){
        htable[i].score = 1;
      } else if (winner(htable[i].board) == 'O'){
        htable[i].score = -1;
      } else if (winner(htable[i].board) == '-'){
        htable[i].score = 0;
      }
    }
  }
}

int best_move(int board){ //so makefile compiles
  return 1;
}
