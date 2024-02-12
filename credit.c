#include <cs50.h>
#include <stdio.h>

int get_digit(long a, int digit);
long requestCN(void);
int calc_sum1(long);
string name_card(long);
int calc_digits(long);

int main(void)
{
    long cardnumber = requestCN();
    int sum1 = calc_sum1(cardnumber);
    // printf("n = %i\n", sum1);
    string namecard = name_card(cardnumber);
    printf("%s\n", namecard);
}

int get_digit(long a, int digit)
{
    for (int i = 0; i < digit; i++)
    {
        a = a / 10;
    }
    return a % 10;
}

long requestCN(void)
{
    long cardnumber;
    do
    {
        cardnumber = get_long("Number: ");
    }
    while (1000000000 > cardnumber || cardnumber >= 10000000000000000);
    return cardnumber;
}

int calc_sum1(long cn)
{
    int sum1 = 0;
    for (int i = 0; i < 16; i++)
    {
        int x = (i % 2 + 1) * get_digit(cn, i);
        if (x >= 10)
        {
            sum1 = sum1 + get_digit(x, 1) + get_digit(x, 0);
        }
        else
        {
            sum1 = sum1 + x;
        }
    }
    return sum1;
}

string name_card(long cn)
{
    if ((get_digit(calc_sum1(cn), 0) != 0))
    {
        return "INVALID";
    }

    string namecard = "";
    if ((calc_digits(cn) == 15)
        && (get_digit(cn, 13) == 4 || get_digit(cn,13) == 7) && (get_digit(cn, 14) == 3)
    )
    {
        namecard = "AMEX";
    }
    else if ((calc_digits(cn)==16)
        && (get_digit(cn, 14) < 6) && (get_digit(cn, 14) > 0) && (get_digit(cn, 15) == 5)
    )
    {
        namecard = "MASTERCARD";
    }
    else if ((((calc_digits(cn)==16) && (get_digit(cn, 15) == 4))
        || ((calc_digits(cn)==13) && (get_digit(cn, 12) == 4)))
    )
    {
        namecard = "VISA";
    }
    else
    {
        namecard = "INVALID";
    }
    return namecard;
}


int calc_digits(long cn)
{
    int digits = 0;
    while (cn != 0)
    {
        cn = cn / 10;
        digits++;
    }
    return digits;
}
