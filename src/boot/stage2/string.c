#include "string.h"
#include "stdint.h"


const char* strchr(const char* str, char chr)
{
    if (str == NULL)
        return NULL;

    while (*str)
    {
        if (*str == chr)
            return str;

        ++str;
    }

    return NULL;
}

char* strcpy(char* dst, const char* src)
{
    char* origDst = dst;

    if (dst == NULL)
        return NULL;

    if (src == NULL)
    {
        *dst = '\0';
        return dst;
    }

    while (*src)
    {
        *dst = *src;
        ++src;
        ++dst;
    }
    
    *dst = '\0';
    return origDst;
}

unsigned strlen(const char* str)
{
    unsigned len = 0;
    while (*str)
    {
        ++len;
        ++str;
    }

    return len;
}
unsigned strcmp(const char *src, const char *dest){
	int length = strlen(src);
	int count=0;
	while(*src){
		if(*src != *dest){
			return -1;
		}
		src++;
		dest++;
	}
	if(!(strlen(src)==strlen(dest)))
		return 0;
	return -1;
}
//going to assume our token hunters or whatever is gonna be able to parse both (cd\0dir) and (cd\0\0\0dir);
//later we will build a more complex one

void strtok(char *buf, char delim){
	while(*buf != '\0'){
		if(*buf==delim){
			while(*buf==delim){
				*buf='\0';		
				buf++;
			}
		}
		else{
			buf++;
		}
	}
}



