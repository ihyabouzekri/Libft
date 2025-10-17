#include <string.h>
#include <stdio.h>

 char *ft_strnstr(const char *haystack, const char *needle, size_t len){
    size_t i,j;

    if (needle[0] == '\0')  //if needle is emplty we return haystack
        return (char *) haystack;

    i = 0;
    while (haystack[i] && i < len){ //we shouldn't exceed len

        j = 0;
        while (i + j < len && needle[j] == haystack[i+j]){ //we shouldn't exceed len while j is incrementing
          
            j++;
            if (needle[j] == '\0')
                return (char *) &haystack[i];
        }
        i++;
    }
    return NULL;
 }
 
 /*int main(){
    const char haystack[] = "11027843889jqls";
    const char needle[] = "dsds"; 

    printf("ft_strnstr: \n");
    printf("%s", ft_strnstr(haystack,needle,10));
    printf("\noriginal strnstr: \n");
    printf("%s", strnstr(haystack,needle,10));
 }*/