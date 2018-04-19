#include <stdio.h>
#include <stdlib.h>


const char *calculator();
const char *population();
const char *ticTacToe();
const char *reverseArray();
float rateCheck(float rate);
float popSize(int prevPop, float birthRate, float deathRate);
void input_integer( int **a, size_t *n );
void inverse_reorder( int *a, size_t n );



int main() {

    int selection = 0, run = 1;

    puts("Homework 3");


    printf("----------\n");

    printf("1. Geometry Calculator\n"
                   "2. Population\n"
                   "3. Tic-Tac-Toe\n"
                   "4. Reverse Array\n"
                   "5. Exit\n"
                   "Select Problem (1-4) 5 to exit:");

    scanf("%d", &selection);
    fflush(stdin);

    while (run == 1) {
        switch (selection) {
            case 1:
                printf("%s", calculator());
                printf("\n");
                selection = 0;
                break;

            case 2:
                printf("%s", population());
                printf("\n");
                selection = 0;
                break;

            case 3:
                printf("%s", ticTacToe());
                printf("\n");
                selection = 0;
                break;

            case 4:
                printf("%s", reverseArray());
                printf("\n");
                selection = 0;
                break;

            case 5:
                return 0;

            default:
                printf("invalid selection\n");
                selection = 0;
                break;
        }
        printf("\n1. Geometry Calculator\n"
                       "2. Population\n"
                       "3. Tic-Tac-Toe\n"
                       "4. Reverse Array\n"
                       "5. Exit\n"
                       "SSelect Problem (1-4) 5 to exit::");
        gets(&selection);

        if (scanf("%d", &selection) == 0) {break;}
    }

    return 0;
}

const char *calculator() {
    static char *exit = "exit calculator";
    int selection = 0;

    float r = 0.0, pi = 3.14159, area = 0.0,
    length = 0.0, width = 0.0,
    base = 0.0, height = 0.0;

    printf("1. Calculate the Area of a Circle\n"
                   "2. Calculate the Area of a Rectangle\n"
                    "3. Calculate the Area of a Triangle\n"
                     "4. Quit\n"
                   "Enter your choice (1-4):");

    scanf("%d", &selection);
    fflush(stdin);

    switch (selection) {
        case 1:
            printf("\nEnter radius: ");
            scanf("%f", &r);
            fflush(stdin);
            area = pi * r * r;
            printf("\nArea: %f\n", area);
            selection = 0;
            break;

        case 2:
            printf("\nEnter length: ");
            scanf("%f", &length);
            fflush(stdin);
            printf("\nEnter width: ");
            scanf("%f", &width);
            area = length * width;
            printf("\nArea: %f\n", area);
            selection = 0;
            break;

        case 3:
            printf("\nEnter base: ");
            scanf("%f", &base);
            fflush(stdin);
            printf("\nEnter height: ");
            scanf("%f", &height);
            area = base * height * 0.5;
            printf("\nArea: %f\n", area);
            selection = 0;
            break;

        case 4:
            selection = 0;
            break;
    }
    return exit;
}


const char *population() {
    static char *exit = "exit population";

    int startPop, years, newPop;
    float deathRate, birthRate;

    printf("Enter the initial population: ");
    scanf("%d", &startPop);
    fflush(stdin);

    while(startPop < 2) {
        printf("Enter a value greater than 2 for the initial population: ");
        scanf("%d", &startPop);
    }

    printf("Enter death rate: ");
    scanf("%f", &deathRate);
    deathRate = rateCheck(deathRate);
    fflush(stdin);

    printf("Enter birth rate: ");
    scanf("%f", &birthRate);
    birthRate = rateCheck(birthRate);
    fflush(stdin);

    printf("Enter number of years observed: ");
    scanf("%d", &years);

    while (years < 1) {
        printf("years must be greater than 0...");
        scanf("%d", &years);
    }

    newPop = startPop;

    printf("Initial population: %d\n", newPop);

    for (int i = 1; i <= years; i++) {
        newPop = popSize(newPop, birthRate, deathRate);
        printf("Population for year %d is %d\n", i, newPop);
    }

    return exit;
}


const char *ticTacToe() {
    static char *exit = "exit Tic-tac-toe";

    int i = 0;
    int player = 0;
    int go = 0;
    int row = 0;
    int column = 0;
    int line = 0;
    int winner = 0;
    char board[3][3] = {
            {'1','2','3'},
            {'4','5','6'},
            {'7','8','9'}
    };

    for( i = 0; i<9 && winner==0; i++)
    {
        /* Display the board */
        printf("\n\n");
        printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

        player = i%2 + 1;                           /* Select player */

        /* Get valid player square selection */
        do
        {
            printf("\nPlayer %d, please enter the number of the square "
                           "where you want to place your %c: ", player,(player==1)?'X':'O');
            scanf("%d", &go);

            row = --go/3;                                 /* Get row index of square      */
            column = go%3;                                /* Get column index of square   */
        }while(go<0 || go>9 || board[row][column]>'9');

        board[row][column] = (player == 1) ? 'X' : 'O';        /* Insert player symbol   */

        /* Check for a winning line - diagonals first */
        if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
           (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
            winner = player;
        else
            /* Check rows and columns for a winning line */
            for(line = 0; line <= 2; line ++)
                if((board[line][0] == board[line][1] && board[line][0] == board[line][2])||
                   (board[0][line] == board[1][line] && board[0][line] == board[2][line]))
                    winner = player;


    }
    /* Game is over so display the final board */
    printf("\n\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

    /* Display result message */
    if(winner == 0)
        printf("\nDraw\n");
    else
        printf("\nCongratulations, player %d, wins!\n", winner);


    return exit;
}


const char *reverseArray() {
    static char *exit = "exit Reverse array";

    int *a;
    size_t n;

    input_integer( &a, &n );

    if ( n )
    {
        printf( "inputted data : " );

        for ( size_t i = 0; i < n ; i++ )
        {
            printf( "%d, ", *( a + i ) );
        }
        putchar( '\n' );

        inverse_reorder( a, n );

        printf( "reversed data : " );

        for ( size_t i = 0; i < n ; i++ )
        {
            printf( "%d, ", *( a + i ) );
        }
        putchar( '\n' );

        free( a );
    }

    return exit;
}

float rateCheck(float rate) {
    while (rate < 0) {
        printf("The rate must be greater >= 0...");
        scanf("%d", &rate);
    }

    return rate;
}

float popSize(int prevPop, float birthRate, float deathRate) {
    return (prevPop + (birthRate*prevPop - deathRate*prevPop));
}

void input_integer( int **a, size_t *n ) {
    *a = NULL;
    *n = 0;

    printf( "Array size = ? " );

    if ( scanf( "%zu", n ) == 1 && *n != 0 )
    {
        *a = malloc( *n * sizeof( int ) );

        printf( "enter %zu integers: ", *n );
        for ( size_t i = 0; i < *n; i++ ) scanf( "%d", *a + i );
    }
}

void inverse_reorder( int *a, size_t n ) {
    for ( size_t i = 0; i < n / 2; i++ )
    {
        int tmp = *( a + i );
        *( a + i ) = *( a + n - i - 1 );
        *( a + n - i - 1 ) = tmp;
    }
}