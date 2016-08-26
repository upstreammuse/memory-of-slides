TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
HEADERS += \
   FileShuffler.h \
   ImageView.h
SOURCES += \
   FileShuffler.cpp \
   ImageView.cpp \
   main.cpp
OTHER_FILES += \
   LICENSE.txt
ICON = Danieledesantis-Audio-Video-Outline-Shuffle.icns
TARGET = MemoryOfSlides
