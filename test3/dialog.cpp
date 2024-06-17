#include "dialog.h"
#include "ui_dialog.h"
#include <QTableView>
#include <QString>
#include <QFile>
#include <QMessageBox>

int max=160;
int count=1;
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Diapad");
    model=new QStandardItemModel(234,3,this);
    model->setHorizontalHeaderLabels({"Flag:","Country:","Prefiks:"});
    for(int i=0;i<234;i++)
    {
        QStandardItem *itm=new QStandardItem();
        itm->setIcon(QIcon(":/res/"+QString::number(i+1)+".jpg"));
        model->setItem(i,0,itm);

    }
    ui->comboBox->setModel(model);
    ui->comboBox->setModelColumn(1);
    QTableView *view = new QTableView;
    ui->comboBox->setView(view);

    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setFixedWidth(350);


    QString filename="C:/Users/User/Desktop/QT/test3/dat3.txt";
    QFile input(filename);
    if(!input.open(QFile::ReadOnly))
    {
        qDebug()<<"Ne moze da se otvori datotekata";
        return ;
    }
    int i=0;
    QTextStream in(&input);
    while(!in.atEnd())
    {
        QString line = in.readLine(),line1;
        line1=line;
        line.remove(0,12);
        line.chop(17);

        line1.remove(0,6);
        line1.chop(43);
        QStandardItem *itm=new QStandardItem(line);
        model->setItem(i,1,itm);
        itm=new QStandardItem("+"+line1);
        model->setItem(i,2,itm);
        i++;
    }
    ui->lineEdit_2->setMaxLength(max);
    ui->label_2->setStyleSheet("QLabel { text-color : red; color : blue }");


    input.close();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    QMessageBox::warning(this,"Problem","Out of network.");
}


void Dialog::on_pushButton_2_clicked()
{
    //Buy Credit

    ui->label_2->setText(QString::number(ui->label_2->text().toInt()+1));
}


void Dialog::on_pushButton_3_clicked()
{
    //Send
    if(ui->label_2->text().toInt()>0&&ui->label_2->text().toInt()>=count)
    {
        QString q="";
        if(count>1)
            q="s";
        QMessageBox::information(this,"Message","Message" + q +" sent.");
        ui->label_2->setText(QString::number(ui->label_2->text().toInt()-count));
        ui->lineEdit_2->setText("");
        count=1;
        max=160;
        ui->lineEdit_2->setMaxLength(max);
    }
    else
    {
        QMessageBox::warning(this,"Message","Not enought credits!");

    }
}


void Dialog::on_comboBox_currentIndexChanged(int index)
{
    QString filename="C:/Users/User/Desktop/QT/test3/dat3.txt";
    QFile input(filename);
    if(!input.open(QFile::ReadOnly))
    {
        qDebug()<<"Ne moze da se otvori datotekata";
        return ;
    }
    int i=0;
    QTextStream in(&input);
    QString line ;
    while(!in.atEnd() && i<=index)
    {
        line=in.readLine();
        i++;
    }
    line.remove(0,6);
    line.chop(44);
    ui->lineEdit->setText("+"+line);
    input.close();

}





void Dialog::on_comboBox_textActivated(const QString &arg1)
{

}


void Dialog::on_comboBox_textHighlighted(const QString &arg1)
{

}


void Dialog::on_lineEdit_2_textChanged(const QString &arg1)
{

    if(ui->lineEdit_2->text().length()==max)
    {
        count++;
        QMessageBox::information(this,"Information","The text you entered will be sent in "+ QString::number(count)+" messages.");
        max+=160;
        ui->lineEdit_2->setMaxLength(max);
    }
}

