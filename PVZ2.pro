QT       += core gui widgets multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basiczombie.cpp \
    bucketzombie.cpp \
    bullet.cpp \
    button.cpp \
    card.cpp \
    cherrybomb.cpp \
    conezombie.cpp \
    footballzombie.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    mower.cpp \
    pea.cpp \
    peashooter.cpp \
    plant.cpp \
    potatomine.cpp \
    repeater.cpp \
    screenzombie.cpp \
    shop.cpp \
    shovel.cpp \
    snowpea.cpp \
    snowpeashooter.cpp \
    sun.cpp \
    sunflower.cpp \
    wallnut.cpp \
    zombie.cpp

HEADERS += \
    basiczombie.h \
    bucketzombie.h \
    bullet.h \
    button.h \
    card.h \
    cherrybomb.h \
    conezombie.h \
    footballzombie.h \
    mainwindow.h \
    map.h \
    mower.h \
    pea.h \
    peashooter.h \
    plant.h \
    potatomine.h \
    repeater.h \
    screenzombie.h \
    shop.h \
    shovel.h \
    snowpea.h \
    snowpeashooter.h \
    sun.h \
    sunflower.h \
    wallnut.h \
    zombie.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
