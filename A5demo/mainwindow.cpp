#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model.h"

MainWindow::MainWindow(model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->startButton,
            &QPushButton::clicked,
            &model,
            &model::startGame);

    connect(ui->redButton,
            &QPushButton::clicked,
            &model,
            &model::checkRed);

    connect(&model,
           &model::deactivateStartButton,
           this,
           &MainWindow::disableButton);

    connect(&model,
            &model::activateStartButton,
            this,
            &MainWindow::enableButton);

    connect(&model,
            &model::highlightRed,
            ui->redButton,
            &QPushButton::setStyleSheet);

    connect(&model,
            &model::highlightBlue,
            ui->blueButton,
            &QPushButton::setStyleSheet);

    connect(&model,
            &model::revertRed,
            ui->redButton,
            &QPushButton::setStyleSheet);

    connect(&model,
            &model::revertBlue,
            ui->blueButton,
            &QPushButton::setStyleSheet);




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->startButton->setEnabled(false);
    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer,
            &QTimer::timeout,
            [this]()
    {});
    timer->start(1000);
}

void MainWindow::disableButton()
{
  ui->startButton->setEnabled(false);
}

void MainWindow::enableButton()
{
  ui->startButton->setEnabled(true);
}
