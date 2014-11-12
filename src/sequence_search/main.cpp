#include <QtCore>
#include <iostream>

void searchDir(QString path,const QStringList &nameFilters);
void searchSequence(QString path,const QString &ext);

int main(int argc, char **argv)
{
//    QString path("Z:/___work___/myheart/asset/original_plate/CG_0915/RED");
    QString path("E:/test_images/dd");
    QStringList nameFilters("*.dpx");
    searchDir(path,nameFilters);
	return 0;
}

void searchDir(QString path, const QStringList &nameFilters)
{
    QDir dir(path);
    dir.setFilter(QDir::NoDotAndDotDot|QDir::AllEntries);

    uint AllCount = dir.count();
    if (AllCount){
        QStringList dirList = dir.entryList(QDir::NoDotAndDotDot|QDir::Dirs, QDir::Name|QDir::Type);
        int DirCount = dirList.size();
        for (int i=0;i<dirList.size();i++){
            QString subDir = path;
            subDir.append("/").append(dirList[i]);
            searchDir(subDir,nameFilters);
        }
        if (AllCount == DirCount){
            return;
        }
        QString ext;
        foreach(ext,nameFilters){
            searchSequence(path,ext);
        }
    }
    return ;
}

void searchSequence(QString path,const QString &ext)
{
    QDir dir(path);
    QStringList fileList;
    fileList = dir.entryList(QStringList(ext),QDir::NoDotAndDotDot|QDir::Files);
//    int tmp = fileList.count();
    if (1 < fileList.count()){
        QString filename;
        while (!fileList.isEmpty()){
            filename = fileList.first();
            fileList.removeFirst();
            QRegExp rx("\\d+");
            if(-1 != rx.indexIn(filename)){
                QStringList filetmp = filename.split(rx);
                QString tmp;
                QString rxa("(\\d+)?");
                foreach(tmp,filetmp)
                    rxa = rxa + "(\\D*)" + "(\\d+)?";                
                rx.setPattern(rxa);
                /*int pos = */rx.indexIn(filename);
                filetmp = rx.capturedTexts();

                int Tnum = 0;
                for (Tnum=filetmp.size()-1;Tnum>0;Tnum--){
                    QRegExp rxc("[\\d]+");
                    if(rxc.exactMatch(filetmp[Tnum])){
                        break;
                    }
                }
                QString prefix("");
                QString suffix("");
                for (int i=1;i<filetmp.size();i++){
                    if(i < Tnum){
                        prefix += filetmp[i];
                    }else if(i>Tnum){
                        suffix += filetmp[i];
                    }
                }
                QString pattern="(" + prefix + ")" + "(\\d+)" + "(" + suffix + ")";
                rx.setPattern(pattern);
                int fileCount = 0;
                while (-1 != fileList.indexOf(rx)){
                    for(int i=0;i<fileList.count();i++){
                        if(rx.exactMatch(fileList[i])){
                            fileList.removeAt(i);
                            fileCount++;
                            break;
                        }
                    }
                }
                if(0 == fileCount){
                    std::cout << qPrintable(filename)<< " " << fileCount+100 << std::endl; // 시퀀스 형태의 파일이 하나만 존재
                }else{
                    std::cout << qPrintable(pattern)<< " " << fileCount+1 << std::endl;  // 정상 적인 시퀀스 파일
                }
            
            }else{
            std::cout << qPrintable(path) << "/" << qPrintable(filename) << std::endl;  //파일 네임에 숫자가 없을때
            }
        }
    }else if (0 < fileList.count()){
        std::cout << qPrintable(path) << "/" << qPrintable(fileList.first()) << std::endl;  //폴더에 해당 확장자 파일이 하나만 있을때
    }
}