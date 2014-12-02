#include <QImage>
#include <QString>

class DpxReader
{
public:
    DpxReader();
    DpxReader(QString &path);
    ~DpxReader();
    int getWidth();
    int getHeight();
    QImage getQImage();
    void setPath(QString &path);
    unsigned int *bits;
private:
    int width;
    int height;
//    unsigned char *bits;
};