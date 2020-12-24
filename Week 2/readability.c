//including all the libraries required

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LIMIT 200000


// The coleman liau index

int main(void)
{
    //how to get input sentence in C
    char str[MAX_LIMIT];
    printf("Text: ");
    fgets(str, MAX_LIMIT,stdin);
    
    //printf("%s",str);
    //return  0;
    
    //definning the variables for number of letters, words and sentences
    
    float letters = 0;
    float words = 0;
    float sentence = 0;
    
    
    
    //looping the whole sentence to the length of the string to count
    
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        //counting the letters using the ASCII code
        //65 is the ASCII Code for 'A'
        //122 is the ASCII Code for 'z'
        if (str[i] >= 65 && str[i] <= 122)
        {
            // it counts whenever it sees an alphabet, no matter lowercase or upper case
            letters++;
        }
        
        //counting the number of words by reading all the spaces in between them
        // 32 is the ASCII code for a space
        // basically it checks whether the string is a space and the previous string is not a space and counts a word
        else if (str[i] == 32 && (str[i-1] != 33 && str[i - 1]!= 46 && str[i - 1]!= 63))
        {
            words++;
        }
        
        else if (str[i] == 33 || str[i]==46 || str[i] == 63)
        {
            sentence++;
            words++;
        }
    }
    
    float L = letters * 100/words;
    float S = sentence * 100/words;
    
    //using the formula
    
    float index = round(0.0588 * L - 0.296 * S - 15.8);
    
    
    
    //What to give as output
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) index);
    }
}
    
    
    
        
        
        
        
        
        
        
        
        