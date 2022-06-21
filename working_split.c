#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char    **ft_split(char *str)
{
    int index;
    int pntr;
    int pntr_index;
    char **arr;

    index = 0;
    pntr = 0;
    if (!(arr = (char**)malloc((sizeof(char*))*256)))
        return(NULL);
    while(str[index] == ' ' || str[index] == '\t' || str[index] == '\n')
        index += 1;
    while(str[index])
    {
        pntr_index = 0;
        if (!(arr[pntr] = (char*)malloc((sizeof(char))*4096)))
            return(NULL);
        while(str[index] != ' ' && str[index] != '\t' && str[index] != '\n' && str[index])
            arr[pntr][pntr_index++] = str[index++];
        while(str[index] == ' ' || str[index] == '\t' || str[index] == '\n')
            index += 1;
        arr[pntr][pntr_index] = '\0';
        pntr+=1;
    }
    arr[pntr] = NULL;
    return(arr);
}

int main (void)
{
    int i;
    char **ret;

    i = 0;
    ret = ft_split("HOI DOEI    IS THISWORKING");
    while (ret[i])
    {
        printf("%s\n", ret[i]);
        i++;
    }
}