#include "word.h"




Word::Word(QString word)
{

    this->word = word;
}

Word::~Word(){}

const QString &Word::getRuWord() const
{
    return word;
}



