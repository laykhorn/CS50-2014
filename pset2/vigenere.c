// Pset2 Vigenere Cypher
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
     
    
        string key =(argv[1]);          // argv[1] assigned as key
        int m = strlen(argv[1]);
        printf("Enter your plain text: ");
        string p = GetString();
        for ( int i = 0, n = strlen(p); i < n; i ++)
                {  
              if ( islower(p[i]) && (p[i] >= 'a' && p[i] <= 'z'))       // Condition to encrypt lower case letters       
                    {
                    int g = i % (m+1);
                    printf("%i", g);
                    char c;
                             if ( isupper(key[g]))
                             {
                             int k = key[g] - 'A';
                              c = (p[i] + k - 97) % 26 + 97;                      // Encryption of lower case letters
                              printf("%c", c );
                            }
                             else 
                             {
                             int k = key[g] - 'a';
                              c = (p[i] + k - 97) % 26 + 97;                      // Encryption of lower case letters
                              printf("%c", c );
                             }
                      }
                else if ( isupper(p[i]) && (p[i] >= 'A' && p[i] <= 'Z') )        // Condition to encrypt upper case letters
                 {
                            int g =  i % (m+1);
                            printf("%i", g);                     
                        if ( isupper(key[g]))
                             {
                             int k = key[g] - 'A';
                             char x;
                             x = (p[i] + k -65) % 26 + 65;                           // Encrypt upper case letters and then print it
                             printf("%c", x);
                             }                             
                        else 
                              {
                              int k = key[g] - 'a';
                              char x;
                              x = (p[i] + k -65) % 26 + 65;                           // Encrypt upper case letters and then print it
                              printf("%c", x);
                              }
                     }
                else if( p[i] == ' ')
                    { 
                    printf(" ");
                    continue;
                    }      
                else                                                            // Leaving-out symbols and numbers
                    {
                    printf("%c", p[i]);
                     }

                }
                printf("\n");       // New Line
               return 0;
}
}
