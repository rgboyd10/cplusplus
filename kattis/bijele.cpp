/*
Mirko has found an old chessboard and a set of pieces in his attic. Unfortunately, the set contains only white pieces, and apparently an incorrect number of them. A set of pieces should contain:

    One king

    One queen

    Two rooks

    Two bishops

    Two knights

    Eight pawns

Mirko would like to know how many pieces of each type he should add or remove to make a valid set.
Input

The input consists of 6 integers on a single line, each between 0 and 10 (inclusive). The numbers are, in order, the numbers of kings, queens, rooks, bishops, knights and pawns in the set Mirko found.

Output
Output should consist of 6 integers on a single line; the number of pieces of each type Mirko should add or remove. If a number is positive, Mirko needs to add that many pieces. If a number is negative, Mirko needs to remove pieces.
Sample Input 1 	Sample Output 1

0 1 2 2 2 7     1 0 0 0 0 1

Sample Input 2 	Sample Output 2

2 1 2 1 2 1     -1 0 0 1 0 7

*/

#include <iostream>
using namespace std;
int main()
{
  int current_king, current_queen, current_rooks, current_bishops, current_knights, current_pawns;
  int desired_king = 1;
  int desired_queen = 1;
  int desired_rooks = 2;
  int desired_bishops = 2;
  int desired_knights = 2;
  int desired_pawns = 8;

  cin >> current_king >> current_queen >> current_rooks >> current_bishops >> current_knights >> current_pawns;

  cout << desired_king - current_king << " "
       << desired_queen - current_queen << " "
       << desired_rooks - current_rooks << " "
       << desired_bishops - current_bishops << " "
       << desired_knights - current_knights << " "
       << desired_pawns - current_pawns << endl;
}
