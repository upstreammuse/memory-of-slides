#ifndef FILESHUFFLER_H
#define FILESHUFFLER_H

#include <QFileInfo>
#include <QObject>
#include <QStringList>

class QTimer;

class FileShuffler : public QObject
{
   Q_OBJECT

public:
   explicit FileShuffler(QFileInfo const& location, QObject* parent = 0);

signals:
   void nextFile(QString const& filename);

public slots:
   void selectNextFile();
   void start();

private:
   qlonglong m_ageMsec;
   QStringList m_files;
   QTimer* m_timer;
};

#endif
