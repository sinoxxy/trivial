#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
#include <windows.h>

#define MAXCOLS 256
#define MAXROWS 256

// Data type : Labyrinth − ASCII map, costs , directions ∗/
int row_current = 0;
int col_current = 0;

typedef struct labyrinth {
    char lab[MAXCOLS + 2][MAXROWS];
    long costs[MAXCOLS][MAXROWS];
    long bestx[MAXCOLS][MAXROWS];
    long besty[MAXCOLS][MAXROWS];
    int maxrow;
    int startx;
    int starty;
    int treasurex;
    int treasurey;
} LabCell, *Lab_p;


Lab_p init_lab(FILE *in);

void print_lab(Lab_p mylab);

int find_path(Lab_p mylab, int row_cur, int col_cur, long cost);

int main(int argc, char *argv[]) {
    FILE *in = stdin;

    if (argc > 2) {
        fprintf(stderr, "Usage: %s [<file>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (argc == 2) {
        in = fopen(argv[1], "r");
        if (!in) {
            perror(argv[0]);
            exit(EXIT_FAILURE);
        }
    }


    Lab_p mylab = init_lab(in);
    printf("Koordinaten S: %i, %i\n", mylab->startx, mylab->starty);

    int outcome = find_path(mylab, mylab->startx, mylab->starty, 0);
    if (outcome == 1) {
        printf("success");
    } else {
        printf("Failure");
    }

    /* Here: Read from in with (e.g.) fgets(), ... */
    if (in != stdin) {
        fclose(in);
    }
    exit(EXIT_SUCCESS);
}

Lab_p init_lab(FILE *in) {

    Lab_p mylab = malloc(sizeof(LabCell));
    printf("parse\n");
    int row;
    int col;
    char c;
    int i;
    int j;
    row = 0;
    col = 0;
    while ((c = fgetc(in)) != EOF) {
        mylab->lab[row][col] = (char) c;
        if (c != '\n') {
            if (c == 'S') {
                //printf("S gefunden");
                mylab->startx = col;
                mylab->starty = row;
            }
            col++;
            printf("%c", c);
        } else {
            row++;
            col = 0;
            printf("\n");
        }
        mylab->maxrow = row;
    }

    return mylab;

    // find start
/*    for (i = 0; i < 22; i++) {
        for (j = 0; j < 22; j++) {
            if (mylab->lab[i][j] == 'S') {
                *row = i;
                *col = j;
                printf("start: %i, %i",*row, *col);
            }
            printf("%c", mylab->lab[i][j]);
        }
        printf("\n");
    }
    return mylab;
}
*/
}

int find_path(Lab_p mylab, int row_cur, int col_cur, long cost) {

    mylab->costs[row_cur][col_cur] = cost;
    if (mylab->lab[row_cur][col_cur] == 'X') {
        return 1;
        //mylab->treasurex = col_cur;
        //mylab->treasurey = row_cur;
        //return 1;
    }
    system("clear");
    printf("current pos: %i / %i; Value: %c\n", row_cur, col_cur, mylab->lab[row_cur][col_cur]);
    // Abbruchbedingung
    print_lab(mylab);

    //wegpunkt setzen
    if (mylab->lab[row_cur][col_cur] == ' ') {
        mylab->lab[row_cur][col_cur] = '.';
    } else if (mylab->lab[row_cur][col_cur] == '.') {
        mylab->lab[row_cur][col_cur] = '!';
        //printf("AUSRUFEZEICHEN: %c", mylab->lab[row_cur][col_cur]);
    }


    //move right
    if (mylab->lab[row_cur][col_cur + 1] != '#' && mylab->lab[row_cur][col_cur + 1] != '!') {
        if (find_path(mylab, row_cur, col_cur + 1, cost + 1) == 1) {
            return 1;
        }
    }
    //move down
    if (mylab->lab[row_cur + 1][col_cur] != '#' && mylab->lab[row_cur + 1][col_cur] != '!') {
        if (find_path(mylab, row_cur + 1, col_cur, cost + 1) == 1) {
            return 1;
        }
    }
    //move up
    if (mylab->lab[row_cur - 1][col_cur] != '#' && mylab->lab[row_cur - 1][col_cur] != '!') {
        if (find_path(mylab, row_cur - 1, col_cur, cost + 1) == 1) {
            return 1;
        }
    }
    //move left
    if (mylab->lab[row_cur][col_cur - 1] != '#' && mylab->lab[row_cur][col_cur - 1] != '!') {
        if (find_path(mylab, row_cur, col_cur - 1, cost + 1) == 1) {
            return 1;
        }
    }
    return 0;
    //move left if right doubled
    /*
    if (mylab->lab[row_cur][col_cur - 1] == '.' && mylab->lab[row_cur][col_cur + 1] == 99) {
        find_path(mylab, row_cur, col_cur - 1);
    }*/
}

void print_lab(Lab_p mylab) {
    int i;
    for (i = 0; i < mylab->maxrow; i++) {
        printf("%s", mylab->lab[i]);
    }
}
