#include <QString>
#include <QtTest>

class Default : public QObject
{
    Q_OBJECT

public:
    Default();

private Q_SLOTS:
    void test_case1();
};

Default::Default()
{
}

void Default::test_case1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(Default)

#include "tst_default.moc"
