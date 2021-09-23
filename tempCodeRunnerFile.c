#include <stdio.h>

void main()
{

    char arr[6] = "Hello";

    char *str = arr;

    str[2] = 'L';

    scanf("%s", str);

    str = "Hi"; //------------1

    str[1] = 'e'; // ------------2

    //scanf("%s", str); // ------------3

    //str = arr; //------------4

    scanf("%s", str); // ------------5
}