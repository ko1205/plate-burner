#include "DPXimage_Header.h"
#include <stdio.h>
#include <iostream>

#define Endian32_Swap(value) \
        ((((U32)((value) & 0x000000FF)) << 24) | \
         (((U32)((value) & 0x0000FF00)) << 8) | \
         (((U32)((value) & 0x00FF0000)) >> 8) | \
         (((U32)((value) & 0xFF000000)) >> 24)) 

void flip(void *);

int main(int argc, char **argv){
    FILE *f;
    f = fopen("E:\\test_images\\dd\\a.a1.dpx","r");
    DPXHeader dpxhd;
    fread(&dpxhd,sizeof dpxhd,1,f);

    std::cout << (char*)&dpxhd.file.magic_num << std::endl \
        << dpxhd.file.file_size << std::endl;
    char buff[100];
    scanf("%s",buff);
    return 0;
}