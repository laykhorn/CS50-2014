#include <stdio.h>
#include <cs50.h>
int main(void)

{
    int i, j, k;
    printf("Height: ");       
    int height = GetInt();
  
    if  (height > 0 && height <= 23)
        {
            for ( i = 0; i < height; i++)
            {
                for ( j = 0; j < ( height - i -1 ); j++)
                {printf(" ");}
                for ( k = 0; k < ( i + 2); k++)
                {
                printf("#");
                }
                printf("\n");
            }
        }
      else
      {
      printf("\nThe value you entered is invalid. \n");
      return 1;
      }
          
      
             
}
