#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->openVstPluginButton, SIGNAL(clicked(bool)), this, SLOT(onSelectVstButtonClicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSelectVstButtonClicked()
{
    ui->openedVst3PluginLabel->setText(tr("Hello world"));

    QString openFilesPath;
    QStringList files = QFileDialog::getOpenFileNames(
                                this, tr("QFileDialog::getOpenFileNames()"),
                                openFilesPath,
                                tr("VSTs (*.vst3);;All Files (*)"));
    if (files.count()) {
        openFilesPath = files[0];
        ui->openedVst3PluginLabel->setText(QString("[%1]").arg(files.join(", ")));
    }

    // Load it!!!
}
