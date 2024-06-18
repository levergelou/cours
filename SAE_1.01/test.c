#include <stdio.h>
#include <stdlib.h>

/*      1   2   3   4   5   6   7   8   9
    ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗               
  1 ║ 5 ║ 3 ║   ║   ║ 7 ║   ║   ║   ║   ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  2 ║ 6 ║   ║ 7 ║ 1 ║ 9 ║ 5 ║   ║   ║   ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  3 ║   ║ 9 ║ 8 ║   ║   ║   ║   ║ 9 ║   ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  4 ║ 8 ║   ║   ║   ║ 6 ║   ║   ║   ║ 3 ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  5 ║ 4 ║   ║   ║ 8 ║   ║ 3 ║   ║   ║ 1 ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  6 ║ 7 ║   ║   ║   ║ 2 ║   ║   ║   ║ 6 ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  7 ║   ║ 6 ║   ║   ║   ║   ║ 2 ║ 8 ║   ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  8 ║   ║   ║   ║ 4 ║ 1 ║ 9 ║   ║   ║ 5 ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  9 ║   ║   ║   ║   ║ 8 ║   ║   ║ 7 ║ 9 ║
    ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝*/

int main(){
    // Print the board with the number around it
    printf("      1   2   3   4   5   6   7   8   9\n");
    printf("    ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗\n");
    printf("  1 ║ 5 ║ 3 ║   ║   ║ 7 ║   ║   ║   ║   ║\n");
    printf("    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n");
    printf("  2 ║ 6 ║   ║ 7 ║ 1 ║ 9 ║ 5 ║   ║   ║   ║\n");
    printf("    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n");
    printf("  3 ║   ║ 9 ║ 8 ║   ║   ║   ║   ║ 9 ║   ║\n");
    printf("    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n");
    printf("  4 ║ 8 ║   ║   ║   ║ 6 ║   ║   ║   ║ 3 ║\n");
    printf("    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n");
    printf("  5 ║ 4 ║   ║   ║ 8 ║   ║ 3 ║   ║   ║ 1 ║\n");
    printf("    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n");
    printf("  6 ║ 7 ║   ║   ║   ║ 2 ║   ║   ║   ║ 6 ║\n");
    printf("    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n");
    printf("  7 ║   ║ 6 ║   ║   ║   ║   ║ 2 ║ 8 ║   ║\n");
    printf("    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n");
    printf("  8 ║   ║   ║   ║ 4 ║ 1 ║ 9 ║   ║   ║ 5 ║\n");
    printf("    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n");
    printf("  9 ║   ║   ║   ║   ║ 8 ║   ║   ║ 7 ║ 9 ║\n");
    printf("    ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝\n");
    return 0;
}