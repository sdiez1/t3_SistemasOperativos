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



// Convertir de String a Binario
// https://stackoverflow.com/questions/41384262/convert-string-to-binary-in-c
char* stringToBinary(char* s) {
    if(s == NULL) return 0; /* no input string */
    size_t len = strlen(s);
    char *binary = malloc(len*8 + 1); // each char is one byte (8 bits) and + 1 at the end for null terminator
    binary[0] = '\0';
    for(size_t i = 0; i < len; ++i) {
        char ch = s[i];
        for(int j = 7; j >= 0; --j){
            if(ch & (1 << j)) {
                strcat(binary,"1");
            } else {
                strcat(binary,"0");
            }
        }
    }
    return binary;
}

// Inicializa nuestro programa
void cz_main(char* simdisk){
	Memory memory;
	simdisk = simdisk;
	FILE *fp;
    char *buffer;
    unsigned long fileLen;  // https://www.linuxquestions.org/questions/programming-9/c-howto-read-binary-file-into-buffer-172985/
    fp = fopen(simdisk, "rb");
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


void cz_open(char* filename, char* mode){
	filename = stringToBinary(filename);
	mode = mode;
	string[11];
	for (int c=0; c < 1023; c = c+16){
		for (int i = 1; i < 11; ++i){
			
			memcpy(string, array, x);
		}
    	memcpy(&memory.directorio[c], &buffer[c], sizeof(buffer[c]));
    }
	printf("%s\n", filename);
	printf("%s\n", "011001100110100101101100011001010110111001100001011011010110010100101110011101000111100001110100");

}




/*
PRINT 
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
BIN TO STTRING
	
		int main(void)
{
    char *data = "01010110";
    char c = strtol(data, 0, 2);
    printf("%s = %c = %d = 0x%.2X\n", data, c, c, c);
    return(0);
}
*/