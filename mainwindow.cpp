#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QFile>
#include <QImageWriter>
#include <QImageReader>
#include <QDebug>
#include <QFileDialog>
#include <QException>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList formats;
    foreach (QByteArray ar, QImageWriter::supportedImageFormats())
    {
        formats << QString(ar);
    }
    ui->comboBox->addItems(formats);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    name_src = dialog.getOpenFileName(this,
        tr("Open file"));
    ui->lineEdit->setText(name_src);
}

void MainWindow::on_pushButton_clicked()
{
    QPixmap * pict_src = new QPixmap(name_src);

    name_res = QFileDialog::getSaveFileName(this,
        tr("Save place"), ui->lineEdit_2->text(), tr("*.%1").arg( ui->comboBox->currentText()));
    try
    {
        QFile fres;
        fres.setFileName(name_res + "." +  ui->comboBox->currentText());
        if (!fres.open(QFile::ReadWrite))
            QMessageBox::warning(this, tr("Error"),
                                 tr("Can't open file!"));
        pict_src->save(&fres);
        fres.close();
    }
    catch(QException ex)
    {
        QMessageBox::warning(this, tr("Error"),
                             tr("Error! Error! Error!"));
    }
}
