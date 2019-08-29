#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QApplication>
#include <QFile>
#include <QDir>
#include <QString>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>

#include <time.h>
#include <cstdlib>      //난수 생성
#define _RAND 10
#define UTC_TIME_ASIA_SEOUL (9 * 60 * 60) //9h
#define SEOUL

class FileManager
{
public:
    FileManager();
    virtual ~FileManager();
    QString getFilePath(QString filepath);              //현재 실행되고 있는 어플리케이션의 경로를 얻어온다.

    void onReadFile(QString filename);    //파일의 내용을 읽어온다.
    void onWriteFile(QString filename);   //파일의 내용을 작성한다.
    void onCreateRandomFile(QString filename); //랜덤함수를 이용하여 파일의 내용을 작성한다.
protected:
private:

public:
    QString m_FileName; //경로와 파일이름을 저장한다.
protected:
private:
    QString m_Path; //파일의 경로를 저장한다.
    QString m_Name; //파일의 이름을 저장한다.
    struct tm *date; //time함수 사용

};

#endif // FILEMANAGER_H
