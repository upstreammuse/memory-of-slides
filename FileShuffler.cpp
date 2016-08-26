#include "FileShuffler.h"

#include <QDateTime>
#include <QDirIterator>
#include <QSettings>
#include <QTimer>

#include <ctime>

FileShuffler::FileShuffler(QFileInfo const& location, QObject* parent) :
   QObject(parent),
   m_timer(new QTimer(this))
{
   QDirIterator it(location.canonicalFilePath(), QDir::Files,
                   QDirIterator::Subdirectories);
   while (it.hasNext())
   {
      m_files.append(it.next());
   }
   qsrand(time(0));

   QSettings settings(location.canonicalFilePath() + "/MOS.ini",
                      QSettings::IniFormat);
   m_ageMsec = settings.value("ageMsec", qlonglong(2592000000LL)).toLongLong();
   settings.setValue("ageMsec", m_ageMsec);
   int viewMsec(settings.value("viewMsec", 5000).toInt());
   settings.setValue("viewMsec", viewMsec);
   m_timer->setInterval(viewMsec);

   connect(m_timer, SIGNAL(timeout()), this, SLOT(selectNextFile()));
}

void FileShuffler::selectNextFile()
{
   for (bool success(false); !success; /*inside*/)
   {
      int index(qrand() % m_files.size());
      QString filename(m_files.at(index));

      QSettings settings(QFileInfo(filename).canonicalPath() + "/MOS.ini",
                         QSettings::IniFormat);
      QDateTime lastViewed(
               settings.value(filename.toUtf8().toHex()).toDateTime());

      if (lastViewed.addMSecs(m_ageMsec) < QDateTime::currentDateTimeUtc())
      {
         settings.setValue(filename.toUtf8().toHex(),
                           QDateTime::currentDateTimeUtc());
         emit nextFile(filename);
         success = true;
      }
   }
}

void FileShuffler::start()
{
   m_timer->start();
}
