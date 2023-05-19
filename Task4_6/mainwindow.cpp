#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_runButton_clicked()
{
    QString word;
    QList<QString> synonyms;
    QList<QString> words;

    QList<QString> resultWords;

    QTextStream inputFileTextStream1(&fileInput1);
    QTextStream inputFileTextStream2(&fileInput2);

    if (!fileInput1.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug("Хочется чисто человеческого. Попить пивка.");
    }

    if (!fileInput2.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug("Губит людей не пиво! Губит людей вода!");
    }

    while (!inputFileTextStream1.atEnd() && !inputFileTextStream1.atEnd())
    {
        word = inputFileTextStream1.readLine();
        words.append(word);
        QString line = inputFileTextStream2.readLine();
        synonyms = line.split("; ");
        table.insert(word, synonyms);
    }

    QString outPutFileName = QFileDialog::getSaveFileName(this, "Как сохраняем файл?", defaultPath, "TXT Files (*.txt)");
    QFile outputFile(outPutFileName);

    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug("Нет пива - нет записи!");
    }

    QTextStream outputFileStream(&outputFile);

    QString outResult;
    QString wordsString;
    for (QString w : words) {
        QString synonym = replaceWithRandomSynonym(w, table);
        resultWords.append(synonym);
        wordsString.append(w + "\n");
        outResult.append(synonym + "\n");
        outputFileStream << synonym << "\n";
    }

    ui->logLabel->setText("Запись проведена");
    ui->outLabel->setText(outResult);
    ui->wordsLabel->setText(wordsString);
    fileInput1.close();
    fileInput2.close();
    outputFile.close();
}

void MainWindow::on_openFirstFile_clicked()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Выберите файл со словами", defaultPath, "TXT Files (*.txt)");
    ui->firstNameLabel->setText(fileName);
    fileInput1.setFileName(fileName);
}


void MainWindow::on_openSecondFile_clicked()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Выберите файл со синонимами", defaultPath, "TXT Files (*.txt)");
    ui->secondNameLabel->setText(fileName);
    fileInput2.setFileName(fileName);
}

