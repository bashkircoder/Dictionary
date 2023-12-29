#ifndef WORD_H
#define WORD_H
#include <QString>

class Word
{
public:
    Word(QString word);
    ~Word();

private:

    QString word;
    int id;

public:

    const QString &getRuWord() const;


};

#endif // WORD_H
