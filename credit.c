#include <stdio.h>
#include <math.h>

long long check(int n, long long card_no);
int main(void)
{
    printf("Enter Your Credit Card Number the proble : ");
    scanf("%lld", &card_no);
    if (card_no / 100000000000000 != 0)
    {
        if ((card_no / 1000000000000000 != 0) && 
           (card_no / 10000000000000000 == 0))
        {
            if ((card_no / 100000000000000 >= 51) && 
                (card_no / 100000000000000 <= 55))
            {
                if (check(15, card_no) % 10 == 0)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            if(card_no / 1000000000000000 == 4)
            {
                if (check(15, card_no) % 10 == 0)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        if((card_no / 1000000000000000 == 0) && ((card_no / 10000000000000 == 
            34) || (card_no / 10000000000000 == 37)))
        {
            if (check(14, card_no) % 10 == 0)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    if((card_no / 1000000000000 == 4) && (card_no / 10000000000000 == 0))
    {
        if (check(12,card_no) % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}
// Function to check for the validation of card
long long check(int n, long long card_no)
{
    long long c_no_1 = 0, c_no_2 = 0;
    int i;
    for(i = 1;i <= n;i += 2)
    {
        if (((long long) (card_no / (pow(10,i))) % 10 * 2) / 10 == 0)
        {
            c_no_1 += (long long) (card_no / (pow(10,i))) % 10 * 2;
        }
        else
        if(((long long) (card_no / (pow(10,i))) % 10 * 2) / 100 == 0)
        {
            int x=((long long) (card_no / (pow(10,i))) % 10 * 2) / 10 + 
            ((long long) (card_no / (pow(10,i))) % 10 * 2) % 10;
            c_no_1 += x;
        }
    } 
// c_no_1 gives the value of sum of every next no. by multiplyin with 2
    for(i = 0;i <= n;i += 2)
    {
        c_no_2 += (long long) (card_no / (pow(10,i))) % 10;
    } 
// c_no_2 gives the value of the sum of other digits 
    return c_no_1 + c_no_2;
}
