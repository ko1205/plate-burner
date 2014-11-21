#include "cliplistmodel.h"
#include <QStringList>
#include <QDir>
#include <QApplication>

ClipListModel::ClipListModel(QObject *parent)
    :QAbstractTableModel(parent)
{

}

ClipListModel::ClipListModel(const QString &path, const QStringList &namefilter, QObject *parent)
    :QAbstractTableModel(parent)
{
    searchDir(path,namefilter);
}

ClipListModel::~ClipListModel()
{

}

int ClipListModel::rowCount(const QModelIndex &parent) const
{
    return ClipInfo.size();
}

int ClipListModel::columnCount(const QModelIndex &parent) const
{
    return 7;
}

QVariant ClipListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role == Qt::TextAlignmentRole){
        return int(Qt::AlignLeft | Qt::AlignVCenter);
    }else if (role == Qt::DisplayRole){
        switch(index.column())
        {
        case 1:
            return ClipInfo[index.row()].filename;
        case 2:
            return ClipInfo[index.row()].filepath;
        case 3:
            return ClipInfo[index.row()].duration;
        case 4:
            return ClipInfo[index.row()].start;
        case 5:
            return ClipInfo[index.row()].end;
        default:
            return QVariant();
        }
    }
    return QVariant();

}

QVariant ClipListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QAbstractTableModel::headerData(section,orientation,role);
}

void ClipListModel::searchDir(const QString path, const QStringList &nameFilters)
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

void ClipListModel::searchSequence(const QString path,const QString &ext)
{
    QDir dir(path);
    QStringList fileList;
    clipinfo tempinfo;
    int start;
    int end;
    fileList = dir.entryList(QStringList(ext),QDir::NoDotAndDotDot|QDir::Files);
    if (1 < fileList.count()){
        QString filename;
        while (!fileList.isEmpty()){
            filename = fileList.first();
            fileList.removeFirst();

///////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////나중에 함수로 재구성 ///////////////////////////////////////////
            start = 0;
            end = 0;
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
                        start = end = filetmp[Tnum].toInt();
                        break;
                    }
                }
///////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
               
                
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
 //                       if(rx.exactMatch(fileList[i])){
                        if(-1 !=rx.indexIn(fileList[i])){
                            QStringList aaa = rx.capturedTexts();
                            start = (start > aaa[2].toInt()) ? aaa[2].toInt() : start;
                            end = (end < aaa[2].toInt()) ? aaa[2].toInt() : end;
                            fileList.removeAt(i);
                            fileCount++;
                            break;
                        }
                    }
                }
                if(0 == fileCount){
//                    std::cout << qPrintable(filename)<< " " << fileCount+100 << std::endl; // 시퀀스 형태의 파일이 하나만 존재
                    tempinfo.filename=filename;
                    tempinfo.filepath=path;
                    tempinfo.duration = 1;
                    tempinfo.start = start;
                    tempinfo.end = end;
                    ClipInfo.append(tempinfo);
                    emit readClip(filename);
                
                }else{
//                    std::cout << qPrintable(pattern)<< " " << fileCount+1 << std::endl;  // 정상 적인 시퀀스 파일
                    tempinfo.filename=pattern;
                    tempinfo.filepath=path;
                    tempinfo.duration = fileCount+1;
                    tempinfo.start = start;
                     tempinfo.end = end;
                    ClipInfo.append(tempinfo);
                    emit readClip(pattern);
                }
            
            }else{
//            std::cout << qPrintable(path) << "/" << qPrintable(filename) << std::endl;  //파일 네임에 숫자가 없을때
                tempinfo.filename=filename;
                tempinfo.filepath=path;
                tempinfo.duration = 1;
                tempinfo.start = start;
                tempinfo.end = end;
                ClipInfo.append(tempinfo);
                emit readClip(filename);

            }
        }
    }else if (0 < fileList.count()){
//        std::cout << qPrintable(path) << "/" << qPrintable(fileList.first()) << std::endl;  //폴더에 해당 확장자 파일이 하나만 있을때

///////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////나중에 함수로 재구성 ///////////////////////////////////////////
        start = 0;
        end = 0;
        QRegExp rx("\\d+");
        if(-1 != rx.indexIn(fileList.first())){
            QStringList filetmp = fileList.first().split(rx);
            QString tmp;
            QString rxa("(\\d+)?");
            foreach(tmp,filetmp)
                rxa = rxa + "(\\D*)" + "(\\d+)?";                
            rx.setPattern(rxa);
            /*int pos = */rx.indexIn(fileList.first());
            filetmp = rx.capturedTexts();

            int Tnum = 0;
            for (Tnum=filetmp.size()-1;Tnum>0;Tnum--){
                QRegExp rxc("[\\d]+");
                if(rxc.exactMatch(filetmp[Tnum])){
                    start = end = filetmp[Tnum].toInt();
                    break;
                }
            }
        }
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

        tempinfo.filename=fileList.first();
        tempinfo.filepath=path;
        tempinfo.duration = 1;
        tempinfo.start = start;
        tempinfo.end = end;
        ClipInfo.append(tempinfo);

    }
//    QApplication::processEvents();  //statusbar showMessage와 label의 setText함수 비교용(setText는 이벤트 발생으로 이함수없이 갱신 않됨)
}
