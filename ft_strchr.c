#include <stdio.h>
#include <string.h>

char *ft_strchr(const char *s, int c){
    size_t i = 0;

    while (s[i]){ 
        if (s[i] == (char) c)
            return (char *)&s[i];
        i++;
    }

    if ((unsigned char)c == '\0')
        return (char *)&s[i];

    return NULL;
}

int main(){
    const char s[] = "";
    printf("%s", ft_strchr(s,3000));
    printf("%s", strchr(s,3000));    

}
