#include "DPXimage_Header.h"
#include "dpxReader.h"
#include <stdio.h>
#include <iostream>
#include <QApplication>
#include <QLabel>
#include <time.h>
#include <string.h>

#define Endian32_Swap(value) \
        ((((U32)((value) & 0x000000FF)) << 24) | \
         (((U32)((value) & 0x0000FF00)) << 8) | \
         (((U32)((value) & 0x00FF0000)) >> 8) | \
         (((U32)((value) & 0xFF000000)) >> 24)) 

void flip(void *);

DpxReader::DpxReader()
{
    FILE *f;
    DPXHeader dpxhd;
    f = fopen("E:\\test_images\\dd\\a.a1.dpx","r");
    fread(&dpxhd,sizeof(dpxhd),1,f);
    rewind(f);
    fseek(f,dpxhd.file.offset,SEEK_SET);
    width = dpxhd.image.pixels_per_line;
    height = dpxhd.image.lines_per_image_ele;

    bits = new unsigned int[width*height];
    fread(bits,width*height*4,1,f);
    fclose(f);
}

DpxReader::DpxReader(QString &path)
{
    setPath(path);
}

DpxReader::~DpxReader()
{
    delete[] bits;
}

void DpxReader::setPath(QString &path)
{
    if(bits)
        delete[] bits;
    FILE *f; 
    DPXHeader dpxhd;
    QString Tpath = path.replace("/","\\");
    f = fopen(Tpath.toLocal8Bit(),"r");
    fread(&dpxhd,sizeof(dpxhd),1,f);
    rewind(f);
    fseek(f,dpxhd.file.offset,SEEK_SET);
    width = dpxhd.image.pixels_per_line;
    height = dpxhd.image.lines_per_image_ele;

    bits = new unsigned int[width*height];
    fread(bits,width*height*4,1,f);
    fclose(f);
}

int DpxReader::getWidth()
{
    return width;

}

int DpxReader::getHeight()
{
    return height;

}

QImage DpxReader::getQImage()
{
    QImage image(getWidth(),getHeight(),QImage::Format_RGB32);
    clock_t start_time,end_time;
    start_time = clock();
    unsigned char *buff = image.bits();
    for(int i = 0; i < width*height;i++)
    {
        bits[i] = ((bits[i]&0x00000FFC)>>4)|((bits[i]&0x003FC000)>>6)|((bits[i]&0xFF000000)>>8);
    }
    //for(int y = 0; y < getHeight(); y++){
    //    for(int x = 0; x < getWidth(); x++){
    //        int index(y*getWidth() + x);
    //        unsigned int temp = bits[index]; 
    //        image.setPixel(x,y,((temp&0x00000FFC)>>4)|((temp&0x003FC000)>>6)|((temp&0xFF000000)>>8));
    //    }
    //}
    memcpy(buff,bits,getHeight()*getWidth()*4);
    end_time = clock();
    std::cout << ((double)(end_time-start_time)) / CLOCKS_PER_SEC << std::endl;
    image = image.scaled(200,250,Qt::KeepAspectRatio,Qt::FastTransformation);
    
    return image;
}



//int main(int argc,char **argv)
//{
//    QApplication app(argc,argv);
//    DpxReader dpx;
//    QLabel label;
//    label.setPixmap(QPixmap::fromImage(dpx.getQImage()));
//    label.show();
//
//    return app.exec();
//}