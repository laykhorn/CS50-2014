// Pset2 Caesar Cypher
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])       // Accepting command at the Terminal
{ 
if (argc != 2)              // Verifying the input at the command-line to be exactly 2
    {
    printf("Please Enter the valid command-line argument\n");       // Message yelled if argc isnt 2
    return 1;
    }
else
    {
      int k = atoi(argv[1]);          // converting argv[1] into an int and assigning it to key
            if ( k < 0)
                {
                 printf("Please Enter a positive integer as key\n");
                }   
        
        string p = GetString();
        for ( int i = 0, n = strlen(p); i < n; i ++)
            {
              if ( islower(p[i]) && (p[i] >= 'a' && p[i] <= 'z'))       // Condition to encrypt lower case letters       
                  {
                    char c;
                    c = (p[i] + k - 'a') % 26 + 'a';                      // Encryption of lower case letters
                    printf("%c", c );
                  }
               else if ( isupper(p[i]) && (p[i] >= 'A' && p[i] <= 'Z'))        // Condition to encrypt upper case letters
                     {  // Else if our char is upper case, also encrypt
                        int x;
                        x = (p[i] + k -'A') % 26 + 'A';                           // Encrypt upper case letters and then print it
                        printf("%c", x);
                     }
                else                                                            // Leaving-out symbols and numbers
                    {   // Non-Alphabetics remain unchanged.
                    printf("%c", p[i]);
                    }

                }
                printf("\n");       // New Line
               return 0;
}
}
