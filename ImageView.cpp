#include "ImageView.h"

ImageView::ImageView(QWidget* parent) :
   QLabel(parent)
{
   setAlignment(Qt::AlignCenter);
   setStyleSheet("background-color:black");
}

void ImageView::setImage(QString const& filename)
{
   QPixmap pix(filename);
   if (pix.isNull())
   {
      emit setImageFailed(filename);
      return;
   }
   pix = pix.scaled(frameGeometry().width(), frameGeometry().height(),
                    Qt::KeepAspectRatio, Qt::SmoothTransformation);
   setPixmap(pix);
}
