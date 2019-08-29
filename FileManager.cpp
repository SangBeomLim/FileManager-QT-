#include "FileManager.h"

//파일매니저 생성자
FileManager::FileManager()
{
#ifdef SEOUL
    QDateTime stCurrentDateTime = QDateTime::currentDateTimeUtc();
    stCurrentDateTime = stCurrentDateTime.addSecs(UTC_TIME_ASIA_SEOUL);
#endif
    m_Path = QApplication::applicationDirPath() + "/log";
    QDir Directory(m_Path);
    if(!Directory.exists()) //폴더가 존재하지 않으면 폴더 생성
    {
        Directory.mkdir(m_Path);
    }

//    //time.h
//    const time_t currentTime = time(NULL);
//    date = localtime(&currentTime);

//    QString str;
//    str.sprintf("/%d-%d-%d %d:%d:%d.log",
//    date->tm_year + 1900, date->tm_mon + 1,date->tm_mday, date->tm_hour, date->tm_min, date->tm_sec);

    QString format = "/yyyy-MM-dd_TEST.log";

    m_Name = stCurrentDateTime.toString(format);
    m_FileName = m_Path + m_Name;


    qDebug() <<m_FileName;
}

//파일매니저 소멸자
FileManager::~FileManager()
{
    m_Name = nullptr;
    m_Path = nullptr;
    m_FileName = nullptr;
}

//파일의 경로를 가져온다.
QString FileManager::getFilePath(QString filepath)
{
    //현재 어플리케이션 실행 경로
    filepath = QApplication::applicationDirPath();
    return filepath;
}

//파일을 생성한다.
void FileManager::onCreateRandomFile(QString filename)
{
    //파일을 생성
    QFile file(filename);
    if(!file.open(QFile::WriteOnly|QFile::Append|QFile::Text)) //파일이 존재하지 않으면...
    {
        qDebug() << "Could not open file for writing";
    }
    else
    {
        QTextStream out(&file);
        out<<"log message file."<< "\n";
        for(int i = 0; i < _RAND; i++)
        {
            out<<rand()<< "\n";
        }
    }

    file.close();
}
//log파일의 내용을 읽어온다.
void FileManager::onReadFile(QString filename)
{
    QFile file(filename);
    if(!file.open(QFile::ReadOnly | QFile::Text))//파일이 존재하지 않으면...
    {
        qDebug() << "Could not open the file for reading";
        return;

    }
    else
    {
        //파일이 존재하면 동작
        qDebug() << "Read a File";
        QTextStream in(&file);
        QString ConfigText;
        while(!in.atEnd())
        {
            ConfigText = in.readLine();
            qDebug() << ConfigText;
        }
    }

    file.close();
}

//log파일의 내용을 저장한다.
void FileManager::onWriteFile(QString filename)
{
    QFile file(filename);
    if(!file.open(QFile::WriteOnly|QFile::Append|QFile::Text)) //파일이 존재하지 않으면...
    {
        qDebug() << "Could not open file for writing";
    }
    else
    {
        QTextStream out(&file);
        out<<"log message file."<< "\n";
        out<<"ini configuration."<< "\n";

    }

    file.close();
}
