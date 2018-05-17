#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cz_API.h"
 
typedef struct czFILES {
    void (*cz_open)(struct czFILES *, char *);
    int (*cz_exists)(struct czFILES *, char *);
    int (*cz_read)(struct czFILES *, char *);
    int (*cz_write)(struct czFILES *, char *);
    int (*cz_close)(struct czFILES *, char *);
    int (*cz_mv)(struct czFILES *, char *);
    int (*cz_cp)(struct czFILES *, char *);
    int (*cz_rm)(struct czFILES *, char *);
    void (*cz_ls)(struct czFILES *, char *);
} czFILE;

typedef struct Memories {
    char directorio[1024];
    char bitmaping[8192];
} Memory;

// https://www.linuxquestions.org/questions/programming-9/c-howto-read-binary-file-into-buffer-172985/
void cz_open(char* simdisk, char* mode){
	Memory memory;
	mode = mode;
	simdisk = simdisk;
	FILE *fp;
    char *buffer;
    unsigned long fileLen;
    fp = fopen(simdisk, mode);
    if (!fp){
        fprintf(stderr, "Unable to open file %s", simdisk);
        return;
    }

    fseek(fp, 0, SEEK_END);
    fileLen=ftell(fp);
    fseek(fp, 0, SEEK_SET);

    buffer = (char *)malloc(fileLen+1);
    if (!buffer){
        fprintf(stderr, "Memory error!");
        fclose(fp);
        return;
    }

    fread(buffer, fileLen, 1, fp);

	for (int c=0; c < 1023; c++){
    	memcpy(&memory.directorio[c], &buffer[c], sizeof(buffer[c]));
    }
    for (int c=1024; c < 9215; c++){
    	memcpy(&memory.bitmaping[c-1024], &buffer[c], sizeof(buffer[c]));
    }    
    fclose(fp);
	free(buffer);
}






    //if (a=1){
	//    for (int c=0; c < 1024; c++){
	//        strcpy(memory.directorio[c], buffer[c]);
	        //("%.2X ", (unsigned char)buffer[c]);

	        //if (c % 4 == 3){
	        //printf(" ");
	        //}
	        //if (c % 16 == 15){
	        //printf("\n");
	//    }
	//}