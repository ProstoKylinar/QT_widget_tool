#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVBoxLayout>
#include <QApplication>
#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <iostream>
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <fstream>
#include <string>

class MainWindow : public QWidget {
Q_OBJECT
    QVBoxLayout *globalLayout;
    QLabel *Layout1Label_1;
    QLabel *Layout1Label_2;
    QLabel *Lbl_3;
    QComboBox *box_ciph;
    QComboBox *box_hash;
    QHBoxLayout *Hbl_1;


    QLineEdit *country;
    QLineEdit *state;
    QLineEdit *city;
    QLineEdit *organizationName;
    QLineEdit *organizationUnit;
    QLineEdit *commonName;
    QVBoxLayout *inputLayout;

    QPushButton *btn;
    QPushButton *btn_choose_file;
    QTextEdit *textField;


    void set_layout1();
    void set_inputField();
    void key_generate();
    void csr_slots();
    void csr_generate(std::string str);
    void generate();

private slots:
    void hash_box();
    void on_btn_choose_file_clicked();


public:
    MainWindow();
    ~MainWindow();
};

#endif // MAINWINDOW_H
