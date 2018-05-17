#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cz_API.h"

int main(int argc, char** argv)
{   
    char simdisk[50];
    char mode[50];
    strcpy(simdisk,argv[1]);
    strcpy(mode, "r");
    cz_main(simdisk);
    cz_open("filename.txt", "r");
}

