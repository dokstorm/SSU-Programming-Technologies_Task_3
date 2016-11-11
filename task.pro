TEMPLATE = app
SOURCES += main.cpp \
    app.cpp
contains(QT_VERSION, ^5.*) {
    QT += widgets
}

HEADERS += \
    app.h
