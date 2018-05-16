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


void cz_open(char* simdisk, char* mode){
	mode = mode;
	simdisk = simdisk;
	FILE *fp;
    size_t size;
    unsigned char buffer[1024];
    fp = fopen(simdisk, mode);    
    if (fp == NULL){
        printf("Error: There was an Error reading the file %s \n", simdisk);           
        exit(1);
    }
    else if (fread(buffer, sizeof(buffer), 1, fp) != size){
        printf("Error: There was an Error reading the file %s -321\n", simdisk);
        exit(1);
    }
    else
    {
    	int i;
        for(i = 0; i < size; i++){       
        	printf("%02x", buffer[i]);
    	}
    }
    fclose(fp);
	free(buffer);
}



/*
	if (mode == "r"){
		// buscar filename en directorio
		if (filename){
			// retorna czFILE* que lo represente
		}
		else{
			return NULL;
		}
	}
	if (mode == "w"){
		// buscar filename en directorio
		if (filename){
			return NULL;
		}
		else{
			// create filename
			// retornar nuevo czFILE*
		}
	}
}

FILE *write_ptr;

write_ptr = fopen("test.bin","wb");  // w for write, b for binary

fwrite(buffer,sizeof(buffer),1,write_ptr); // write 10 bytes from our buffer


int cz_exists(char* filename){
	filename
}
*/