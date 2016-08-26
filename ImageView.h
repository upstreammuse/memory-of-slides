#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <QLabel>

class ImageView : public QLabel
{
   Q_OBJECT

public:
   explicit ImageView(QWidget* parent = 0);

signals:
   void setImageFailed(QString const& filename) const;

public slots:
   void setImage(QString const& filename);
};

#endif
