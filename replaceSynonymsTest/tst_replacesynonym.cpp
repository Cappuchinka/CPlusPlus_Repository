#include <QtTest>
#include "../Task4_6/lib.h"
#include "../Task4_6/lib.cpp"
#include <QtCore/QList>

// add necessary includes here

class replaceSynonym : public QObject
{
    Q_OBJECT
    SynonymTable table;
    QString word;
    QString newWord;
    QList<QString> synonyms;

private slots:
    void testReplaceSynonym();
};

void replaceSynonym::testReplaceSynonym()
{
    word = "Good";
    synonyms.append("excellent");
    synonyms.append("amazing");
    synonyms.append("fantastic");
    synonyms.append("legendary");
    synonyms.append("exceptional");
    table.insert(word, synonyms);
    newWord = replaceWithRandomSynonym(word, table);
    QVERIFY2(word != newWord, "Word wasn't replaced to synonym!");
}

QTEST_APPLESS_MAIN(replaceSynonym)

#include "tst_replacesynonym.moc"
