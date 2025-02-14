#include <stdio.h>

#define get_and_sub_num_of_units(result, total, unit_size) \
    {(result)=(total)/(unit_size);(total)-=(result)*(unit_size);}

#define inc_unit(unit, d, upper, carry) \
    {(unit)+=(d)+(carry);if((unit)>(upper)){(unit)-=(upper),(carry)=1;}else{(carry)=0;}}

int main(void) {
    const int NUM_OF_DAYS_PER_MONTH = 30;
    const int NUM_OF_MONTHS_PER_YEAR = 12;
    const int NUM_OF_DAYS_PER_YEAR =
                NUM_OF_DAYS_PER_MONTH * NUM_OF_MONTHS_PER_YEAR;
    const int END_OF_WORLD = 0x12345678;

    int yyyy, mm, dd, N, num_of_days;

    scanf("%04d-%02d-%02d", &yyyy, &mm, &dd);
    scanf("%d", &N);

    int next_yyyy, next_mm, next_dd, carry;

    get_and_sub_num_of_units(next_yyyy, N, NUM_OF_DAYS_PER_YEAR);
    get_and_sub_num_of_units(next_mm, N, NUM_OF_DAYS_PER_MONTH);
    get_and_sub_num_of_units(next_dd, N, 1);

    carry = 0;

    inc_unit(dd, next_dd, NUM_OF_DAYS_PER_MONTH, carry);
    inc_unit(mm, next_mm, NUM_OF_MONTHS_PER_YEAR, carry);
    inc_unit(yyyy, next_yyyy, END_OF_WORLD, carry);

    printf("%04d-%02d-%02d\n", yyyy, mm, dd);
    return 0;
}