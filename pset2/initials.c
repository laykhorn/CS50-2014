#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{   
    // Prompt Line to input
        string s = GetString();     //Get input
        
            printf("%c", toupper(s[0]));
            for (int i = 0, n = strlen(s); i < n; i++)
            {
                  if ( s[i] == ' ' )
                  {char u = toupper(s[i += 1]);
                   printf("%c", u);
                  }
            }
        printf("\n");
        return 0;
        
        if ( s != NULL )        // Sanity Check to see if there was an input
        {
            printf("You didnt type in the blinking prompt\n");
            return 1;
        }
}
