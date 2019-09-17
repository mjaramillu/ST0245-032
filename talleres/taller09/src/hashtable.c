#include "hashtable.h"

unsigned long Hashtable_Hash(unsigned char *str)
{
    unsigned long hash = 0;
    unsigned long len = strlen(str);
    int c;

    for (unsigned long i = 0; str[i] != '\0'; i++) {
      hash += (str[i] * pow(31,len-1-i));
    }

    return hash;
}
