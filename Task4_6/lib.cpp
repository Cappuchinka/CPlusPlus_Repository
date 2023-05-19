#include "lib.h"

QString replaceWithRandomSynonym(QString& word, SynonymTable& table){
    if (!table.contains(word))
        return word;

    // Получаем список синонимов для данного слова
    const QList<QString>& synonyms = table.value(word);

    // Генерируем случайное число для выбора случайного синонима
    int index = QRandomGenerator::global()->bounded(synonyms.size());

    // Возвращаем случайный синоним
    return synonyms.at(index);
}
