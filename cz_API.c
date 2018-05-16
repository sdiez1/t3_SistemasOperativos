#include <stdio.h>
#include <stdlib.h>
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

// https://www.linuxquestions.org/questions/programming-9/c-howto-read-binary-file-into-buffer-172985/
void cz_open(char* simdisk, char* mode){
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

    //Read file contents into buffer
    fread(buffer, fileLen, 1, fp);
    for (int c=0; c < fileLen; c++){
        printf("%.2X ", (unsigned char)buffer[c]);

        // put an extra space between every 4 bytes
        if (c % 4 == 3){
        printf(" ");
        }

        // Display 16 bytes per line
        if (c % 16 == 15){
        printf("\n");
    	}
    }
    fclose(fp);
	free(buffer);
}

