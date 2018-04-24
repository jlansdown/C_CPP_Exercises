#include <stdio.h>

const int row = 15; //number of rows
const int seats = 30; //number of seats

void setSeats(double[], int);
void mapSeats(char [row][seats], double price[]);


int main() {

    const int rowNum = 15;
    double rowPrice[rowNum]; //prices for rows
    double ticketSales = 0.00;
    int ticketsSold = 0;
    char selection;
    int rowSelection, seatSelection;
    const char taken = '#';
    const char empty = '*';

    char map[row][seats];


    for (int i = 0; i <= row; i++) {        //mark seats EMPTY initially
        for (int j = 0; j <= seats; j++) {
            map[i][j] = empty;
        }
    }

    setSeats(rowPrice, rowNum);
    mapSeats(map, rowPrice);
    printf("\n\n");

    do {
        printf("\nTheater Menu\n");
        printf("--------------------\n");
        printf("1) Sell a ticket\n");
        printf("2) Display seating\n");
        printf("3) Ticket sales\n");
        printf("q/Q) Quit program\n");
        printf("Selection: ");
        scanf(" %c", &selection);


        if (selection == '1') {
            printf("Please enter a row number and seat to purchase a ticket: ");
            printf("Row # : ");
            scanf(" %d", &rowSelection);
            fflush(stdin);
            printf("\nSeat # : ");
            scanf(" %d", &seatSelection);
            fflush(stdin);
            printf("\n");


            if (map[rowSelection][seatSelection] == taken) {
                printf("This seat is taken! Please enter another selection.\n");
                continue;
            } else {
                map[rowSelection][seatSelection] = taken; //mark seat as TAKEN
                ticketSales += rowPrice[rowSelection];
                ticketsSold += 1;
            }
        } else if (selection  == '2') {
            mapSeats(map, rowPrice);
        } else if (selection == '3') {
            printf("\nTickets sold: %d\n", ticketsSold);
            printf("Ticket sales: %.2lf\n", ticketSales);
        }
        else if (selection == 'q' || selection == 'Q') {
            printf("Thank you...Goodbye");
            break;
        }else if (selection != '1' || selection != '2' || selection != 'q' || selection != 'Q') {
            printf("Invalid selection...\n");
        }
    } while (selection != '1' || selection != '2' || selection != 'q' || selection != 'Q');

    return 0;
}


void setSeats(double rowPrice[], int row) {
    printf("\nPlease enter a ticket price for each row: \n");

    for (int i = 0; i < row; i++) {
        printf("Row # %d: ", i+1);
        scanf(" %lf", &rowPrice[i]);

    }
}


void mapSeats(char seatMap[row][seats], double price[]) {

    printf("Seats  price   ");
    for (int i = 0; i < seats; i++) {
        printf("%-3d ", i+1);
    }

    for (int i = 0; i < row; i++) {
        if (i < 9) {
        printf("\nRow %d  $%.2f   ", i + 1, price[i]);
        }else {
            printf("\nRow %d $%.2f   ", i + 1, price[i]);
        }

        for (int j = 0; j < seats; j++) {

            printf("%-3c ", seatMap[i][j]);

        }
    }
    printf("\n");
}