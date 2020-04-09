#include <stdio.h>
#include <cs50.h>
#include<math.h>
int main(void)
{
//Declare all amounts - Quaters, Dimes, Nickels and Pennies values.
float quaters = 0.25;
float dimes = 0.10;
float nickels = 0.05;
float pennies = 0.01;

// Prompt line to enter amount value.
printf("Enter the amount of change owed: ");
float change = GetFloat();                      //Input change
int x = 0;
// Sanity check for less than zero.
if (change <= 0)
{
printf("\nYou entered an invalid change\n");    //Invalid change when change is negative or zero
}
while ( change > 0 )
    {
        if ( change >= quaters)                 //If change > Quaters
        { 
        change = change - quaters;                   //Subtract the value of the Quaters already printed
        x++;
        }
        else if ( change >= dimes )             //If change > Dimes
        {
        change = change - dimes;
        x++;
        }
        else if ( change >= nickels)            //If change > Nickels
        {
        change = change - nickels;
        x++;
        }
        else if (change >= pennies)             //If change > Pennies
        {
        change = change - pennies;
        x++;
        }
        else
        {
            change = roundf(change);
        }
    }
printf("%i\n", x );
}
