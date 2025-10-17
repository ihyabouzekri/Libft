#include <stdio.h>
#include <string.h>

int ft_strncmp(const char *s1, const char *s2, size_t n){
    size_t i = 0;

    while (i < n){
        
        if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
            return (unsigned char) s1[i] - (unsigned char) s2[i];
         
        i++;
    }

    return 0;

 }

 /*int main(){
    const char s1[] = "ahmed";
    const char s2[] = "ahmed is cold";
    printf("%i", ft_strncmp(s1, s2, 5));
    printf("%i", strncmp(s1, s2, 5));

 }*/