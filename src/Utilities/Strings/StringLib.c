#include <stdlib.h>
#include <string.h>

#include "StringLib.h"

char* CreateEmptyString() {
    return strdup("");
}

char* CreateEmptyStringN(int len) {
    char* n_str = (char*)malloc((len+1)*sizeof(char));
        n_str[len] = '\0';
    return n_str;
}

char* AppendCharToString(char* str, char toAppend) {
    size_t len = strlen(str);
    char* newString = (char*)realloc(str, (len == 0 ? len+2 : len+1)*sizeof(char));
    newString[len] = toAppend;
    newString[len+1] = '\0';
    return newString;
}

char* JoinStrings(char* str1, char* str2) {
    size_t str1_len = strlen(str1);
    size_t str2_len = strlen(str2);
    size_t comb_len = str1_len + str2_len;
    char* joined = (char*)malloc((comb_len+1)*sizeof(char));
    for (int i = 0; i < str1_len; i++) 
        joined[i] = str1[i];
    for (int i = str1_len; i < comb_len; i++) 
        joined[i] = str2[i-str1_len];
    joined[comb_len] = '\0';
    return joined;
}

char* ClearString(char* str) {
    str = (char*)realloc(str, sizeof(char));
    str[0] = '\0';
    return str;
}