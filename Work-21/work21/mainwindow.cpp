#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::set_layout1() {
    Layout1Label_1 = new QLabel;
    Layout1Label_2 = new QLabel;
    Layout1Label_1->setText("Алгоритм шифрования");
    Layout1Label_2->setText("Алгоритм хеширования");
    box_ciph->addItem("");
    box_ciph->addItem("gost256");
    box_ciph->addItem("gost512");
    box_ciph->addItem("rsa1024");
    Hbl_1->addWidget(Layout1Label_1);
    Hbl_1->addWidget(box_ciph);
    Hbl_1->addWidget(Layout1Label_2);
    Hbl_1->addWidget(box_hash);
}

void MainWindow::hash_box() {
    box_hash->clear();
    if (box_ciph->currentText()=="gost256"){
        box_hash->addItem("gost256");
    } else if (box_ciph->currentText()=="gost512") {
         box_hash->addItem("gost512");
        }
    else if (box_ciph->currentText()=="rsa1024"){
        box_hash->addItem("SHA3-256");
        box_hash->addItem("SHA3-512");
    }
}

void MainWindow::key_generate() {
    switch(box_ciph->currentIndex()) {
    case 1:
        system("openssl genpkey -algorithm gost2012_256"
               " -pkeyopt paramset:A -out private.key");
        break;
    case 2:
        system("openssl genpkey -algorithm gost2012_512"
               " -pkeyopt paramset:A -out private.key");
        break;
    case 3:
        system("openssl genrsa -out private.key 1024");
        break;
    default:
        break;
    }
}

void MainWindow::csr_generate(std::string str1) {

    if (box_hash->currentText() == "SHA3-256") {
        std::string str = "openssl req -new -x509 -SHA3-256 -days 365 -key private.key -out ca.cer -subj " + str1;
        system(str.c_str());
    } else if (box_hash->currentText() == "SHA3-512") {
        std::string str = "openssl req -new -x509 -SHA3-512 -days 365 -key private.key -out ca.cer -subj " + str1;
        system(str.c_str());
    } else if(box_hash->currentText() == "gost256") {
        std::string str = "openssl req -new -x509 -md_gost12_256 -days 365 -key private.key -out ca.cer -subj " + str1;
        system(str.c_str());
    } else if (box_hash->currentText() == "gost512") {
        std::string str = "openssl req -new -x509 -md_gost12_512 -days 365 -key private.key -out ca.cer -subj " + str1;
        system(str.c_str());
    }
}

void MainWindow::csr_slots() {
    std::map<QString, QLineEdit *> map = {{"Country(2 signs)", country},
                                          {"Region", state},
                                          {"City", city},
                                          {"Organization Name", organizationName},
                                          {"Organizational Unit Name", organizationUnit},
                                          {"Common Name",             commonName}};
    for (auto i = map.begin(); i != map.end(); ++i) {
        QHBoxLayout *horizontal = new QHBoxLayout;
        QLabel *label = new QLabel;
        label->setText(i->first);
        horizontal->addWidget(label);
        horizontal->addWidget(i->second);
        inputLayout->addLayout(horizontal);
    }
}

void MainWindow::generate() {
    key_generate();
    std::string str;
    str = ("\"/C=" + country->text().toStdString() + "/ST=" + state->text().toStdString() + "/L=" + city->text().toStdString() + "/O=" + organizationName->text().toStdString() + "/OU=" + organizationUnit->text().toStdString() + "/CN=" + commonName->text().toStdString() + "\"");
    csr_generate(str);
    std::fstream csr("ca.cer");
    std::string line;
    textField->clear();
    while (std::getline(csr, line)) {
        QString str2 = QString::fromStdString(line);
        textField->append(str2);
    }
    csr.close();
}

MainWindow::MainWindow() {

    Hbl_1 = new QHBoxLayout;
    box_ciph = new QComboBox;
    box_hash = new QComboBox;
    connect(box_ciph, SIGNAL(currentIndexChanged(int)), this, SLOT(hash_box()));
    set_layout1();

    inputLayout = new QVBoxLayout;
    country = new QLineEdit;
    state = new QLineEdit;
    city = new QLineEdit;
    organizationName = new QLineEdit;
    organizationUnit = new QLineEdit;
    commonName = new QLineEdit;
    csr_slots();

    btn = new QPushButton("Lets do it", nullptr);
    connect(btn, &QPushButton::clicked, this, &MainWindow::generate);
    textField = new QTextEdit;

    globalLayout = new QVBoxLayout;
    globalLayout->addLayout(Hbl_1);
    globalLayout->addLayout(inputLayout);
    globalLayout->addWidget(btn);
    globalLayout->addWidget(textField);

    setLayout(globalLayout);

}


MainWindow::~MainWindow() {
}
