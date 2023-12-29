#include "data.h"


Data::Data(QString input_path) {

    this->input_path = input_path;


}

Data::~Data(){ }

const QList<Word> Data::RuToEng(QString RuWord) const
{

    QList<Word> Result = *new QList<Word>();

    auto _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName(input_path);

    if (!_db.open()){

    }

    auto sql = "SELECT word FROM table_words JOIN table_languages ON table_words.language_id = table_languages.id JOIN table_translates ON table_words.id = table_translates.id WHERE table_translates.translate LIKE '%" + RuWord + "%' AND table_languages.language = 'en'";
    QSqlQuery query(sql);
    while (query.next()){


        auto word = query.value(0).toString();


        Result.push_back(Word(word));

    }

    _db.close();
    return Result;
}

const QList<Word> Data::EngToRu(QString EnWord) const
{

    QList<Word> Result = *new QList<Word>();

    auto _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName(input_path);

    if (!_db.open()){

    }

    auto sql = "SELECT translate FROM table_translates JOIN table_languages ON table_translates.language_id = table_languages.id JOIN table_words ON table_translates.word_id = table_words.id WHERE table_words.word LIKE '%" + EnWord + "%' AND table_languages.language = 'ru';";
    QSqlQuery query(sql);
    while (query.next()){

        auto word = query.value(0).toString();


        Result.push_back(Word(word));

    }

    _db.close();
    return Result;

}

void Data::AddWord(QString RuWord, QString EnWord)
{

    auto _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName(input_path);

    if (!_db.open()){

    }

    auto sql = "INSERT INTO table_words(word, language_id) VALUES ('" + EnWord + "', (SELECT id FROM table_languages WHERE language = 'en'));";
    QSqlQuery query(sql);

    auto sql_1 = "INSERT INTO table_translates(TRANSLATE, LANGUAGE_ID, WORD_ID) VALUES ('" + RuWord + "', (SELECT id FROM table_languages WHERE language = 'ru'),(SELECT id FROM table_words WHERE word = '" + EnWord + "'))";
    QSqlQuery query_1(sql_1);

    _db.close();
}

