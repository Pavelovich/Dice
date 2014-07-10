#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *rot13(char *str)
{
    str = malloc(100*sizeof(char));
    for (int i = 0; i <= strlen(str); i++)
        {
            if ((str[i] >= 'a' && str[i] <= 'n')||(str[i] >= 'A' && str[i] <= 'N'))
                {
                    str[i]+=13;
                }
            else if ((str[i] >= 'o' && str[i] <= 'z')||(str[i] >= 'O' && str[i] <= 'Z'))
                {
                    str[i]-=13;
                }
            else
                str[i] = str[i];
        }
    return str;
}

//abcdefghijklmnopqrstuvwxyz
//NOPQRSTUVWXYZABCDEFGHIJKLM

int main(void)
{
    //char encrypted[];
    char *encrypted = rot13("Hello");
    printf("%s \n", encrypted);
}
