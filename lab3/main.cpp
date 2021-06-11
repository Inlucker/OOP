#include "mainwindow.h"

#include <QApplication>

#include "facade.h"
#include "commands.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


/*TODO:
 * Need to delete curCamera from sceneManager, when deleting it from composite
 *
 *
 *
 * */
