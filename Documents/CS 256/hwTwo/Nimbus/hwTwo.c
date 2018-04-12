#include <stdio.h>

void patterns();
void stocks();
void oceanLevels();
void restaurantBill();

int main(int argc, char **argv) {

    printf("*****Restaurant Bill*****\n");
    restaurantBill();

    printf("*****Ocean Levels*****\n");
    oceanLevels();

    printf("*****Stock Trading Program Bill*****\n");
    stocks();

    printf("*****Pattern Displays*****\n");
    patterns();

    return 0;
}

void restaurantBill(){
    double meal = 88.67;
    double tax = .0675;
    double tip = .2;

    double mealTax = meal*tax;
    double mealTip = (meal + mealTax) * tip;
    double total = meal + mealTax + mealTip;

    printf("Meal cost: %f\n", meal);
    printf("Tax amount: %f\n", mealTax);
    printf("Tip amount: %f\n", mealTip);
    printf("Total Bill: %f\n\n\n", total);
}

void oceanLevels(){
    double rate = 1.5;

    printf("5 years: %f\n", rate*5);
    printf("7 years: %f\n", rate*7);
    printf("10 years: %f\n\n\n", rate*10);
}

void stocks(){
    float purchased = 1000;
    float initialPrice = 45.50;
    float commission = 0.02;
    float sold = 1000;
    float sellPrice = 56.90;

    float buyComm = initialPrice*purchased*commission;
    float sellComm = sellPrice*sold*commission;

    float profit = (sellPrice*sold - sellComm) - (initialPrice*purchased - buyComm);

    printf("Price Joe bought stock: %f\n", purchased*initialPrice);
    printf("Commission paid for purchase: %f\n", buyComm);
    printf("Price Joe sold stock: %f\n", sellPrice * sold);
    printf("Commission paid for selling stock: %f\n", sellComm);
    printf("Joe's profit: %f\n\n", profit);
}

void patterns() {
    printf("pattern a:\n");

    for(int i = 1; i <= 10; i++) {

        for (int j = 1; j <= i; j++ ) {
            printf("%c", '+');
        }
        printf("\n");
    }

    printf("\n\npattern b:\n");

    for(int p = 1; p <= 10; p++) {

        for (int j = 10; j >= p; j-- ) {
            printf("%c", '+');
        }
        printf("\n");
    }

    printf("\n\n");
}