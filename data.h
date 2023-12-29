#ifndef DATA_H
#define DATA_H
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QList>
#include "word.h"

class Data
{
public:

    Data(QString input_path);
    ~Data();


private:

    QString input_path;;

public:

    const QList<Word> RuToEng(QString RuWord) const;
    const QList<Word> EngToRu(QString EnWord) const;
    void AddWord(QString RuWord, QString EnWord);

};

#endif // DATA_H
