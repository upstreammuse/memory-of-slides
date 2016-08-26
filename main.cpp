#include <QApplication>
#include <QDirIterator>
#include <QFileDialog>
#include <QFileInfo>
#include <QLabel>

#include "FileShuffler.h"
#include "ImageView.h"

int main(int argc, char** argv)
{
   QApplication app(argc, argv);

   QFileInfo location(QFileDialog::getExistingDirectory());

   FileShuffler shuffler(location);
   ImageView view;
   QObject::connect(&shuffler, SIGNAL(nextFile(QString)),
                    &view, SLOT(setImage(QString)));
   QObject::connect(&view, SIGNAL(setImageFailed(QString)),
                    &shuffler, SLOT(selectNextFile()));
   view.showFullScreen();
   shuffler.start();

   return app.exec();
}
