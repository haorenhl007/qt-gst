#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class DialogAccount : public QDialog
{
    Q_OBJECT

public:
    DialogAccount(QWidget *parent = 0);
    ~DialogAccount();

private slots:
    void on_pushButtonLogin_clicked();

    void on_setAlpha_clicked();
    void on_setPos_clicked();

private:
    QLabel *labelUserName, *labelPassWord;
    QLineEdit *lineEditUserName, *lineEditPassWord;
    QPushButton *pushButtonLogin;

    QPushButton *setAlpha1, *setAlpha2;
};

#endif // LOGINDLG_H
