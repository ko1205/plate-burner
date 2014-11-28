#include "DPXimage_Header.h"
#include <stdio.h>
#include <iostream>
#include <QApplication>
#include <QImage>

#define Endian32_Swap(value) \
        ((((U32)((value) & 0x000000FF)) << 24) | \
         (((U32)((value) & 0x0000FF00)) << 8) | \
         (((U32)((value) & 0x00FF0000)) >> 8) | \
         (((U32)((value) & 0xFF000000)) >> 24)) 

void flip(void *);

class DpxReader
{
public:
    DpxReader();
    ~DpxReader();
    int getWidth();
    int getHeight();
private:
    int width;
    int height;
};

DpxReader::DpxReader()
{
    FILE *f;
    DPXHeader dpxhd;
    f = fopen("E:\\test_images\\dd\\a.a1.dpx","r");
    fread(&dpxhd,sizeof(dpxhd),1,f);
    width = dpxhd.image.pixels_per_line;
    height = dpxhd.image.lines_per_image_ele;
}

DpxReader::~DpxReader()
{
}

int DpxReader::getWidth()
{
    return width;

}

int DpxReader::getHeight()
{
    return height;

}



int main(int argc, char **argv){
    QApplication app(argc,argv);
    DpxReader dpx;
    QImage image(dpx.getWidth(),dpx.getHeight(),QImage::Format_RGB32);

    return app.exec();
}