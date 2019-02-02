#include <stdlib.h>
#include <stdio.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double monthly_balance(double initial, retire_info info) {
  initial =  initial * (1 + info.rate_of_return) + info.contribution;
  return initial;
}

void retirement(int startAge,          // in months
		double initial,        // initial savings in dollars
		retire_info working,   // info about working
		retire_info retired) { // info about being retired) 
  for (int i = startAge; i < startAge + working.months; i++) {
    printf("Age %3d month %2d you have $%.2lf\n", i / 12, i % 12, initial);
    initial = monthly_balance(initial, working);
  }
  for (int i = startAge + working.months; i < startAge + working.months + retired.months; i++) {
    printf("Age %3d month %2d you have $%.2lf\n", i / 12, i % 12, initial);
    initial = monthly_balance(initial, retired);
  }
}

int main(void) {
  retire_info working, retired;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045 / 12;

  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01 / 12;

  retirement(327, 21345, working, retired);
  return EXIT_SUCCESS;
}
