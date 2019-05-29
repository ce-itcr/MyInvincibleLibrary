TEMPLATE = subdirs

SUBDIRS += \
    app \
    src \
    test

app.depends = src
test.depends = src

DISTFILES += \
    README.md \
    LICENSE \
    defaults.pri
