#include "mainwindow.h"
#include <QApplication>
#include "FileManager.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    FileManager file;
    file.onCreateRandomFile(file.m_FileName); //난수를 이용하여 로그파일을 작성한다.

    file.onReadFile(file.m_FileName); //저장된 파일을 읽어와서 Debug창에 띄운다.


    return a.exec();
}
