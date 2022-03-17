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

    connect(&model,
            &model::updateSpinBox,
            ui->spinBox,
            &QSpinBox::setValue);

    connect(&model,
            &model::sequenceRed,
            ui->sequenceBox,
            &QLabel::setStyleSheet);

    connect(&model,
            &model::sequenceBlue,
            ui->sequenceBox,
            &QLabel::setStyleSheet);




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
    timer->start(2500);
}

