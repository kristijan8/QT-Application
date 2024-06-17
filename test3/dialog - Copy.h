#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QDialog>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_textHighlighted(const QString &arg1);

    void on_comboBox_textActivated(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    Ui::Dialog *ui;
    QStandardItemModel *model;
};
#endif // DIALOG_H
