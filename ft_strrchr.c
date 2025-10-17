#include <string.h>
#include <stdio.h>

char *ft_strrchr(const char *s, int c){

    size_t i = 0;

    while (s[i])
        i++;

    while (i >= 0){
        
        if ((unsigned char)s[i] == (unsigned char)c) //if c = '\0' it will work fine because s[i] = '\0' in the first loop 
            return (char *) &s[i];
        
        i--;
    }

    return NULL;
}
/*
int main (){
    const char s[] = {57,65,83,57,73,77};

    printf("copy: \n");
    printf("%s\n",ft_strrchr(s, 65) );
    printf("original: \n" );
    printf("%s\n",strrchr(s, 65) );

}*/

int main (){
    const char s[] = {57,65,83,57,73,77};

    printf("copy: \n");
    printf("%s\n",ft_strrchr("abc", '\0') );
    printf("original: \n" );
    printf("%s\n",strrchr("abc", '\0') );

}

