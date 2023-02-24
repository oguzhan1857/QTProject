#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->openImage_PushButton, SIGNAL(clicked()), this, SLOT(open_file_dialog()));
    // QObject::connect(ui->imgWidth_LineEdit,    SIGNAL(textChanged(const QString&)), this, SLOT(on_img_width_change(const QString&)));
    // QObject::connect(ui->imgHeight_LineEdit,   SIGNAL(textChanged(const QString&)), this, SLOT(on_img_height_change(const QString&)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete item;
    delete scene;
    delete view;
}

// void MainWindow::on_img_width_change(const QString &text)
// {
// }

// void MainWindow::on_img_height_change(const QString &text)
// {
// }

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
}

void MainWindow::open_file_dialog()
{
    QString file_name = QFileDialog::getOpenFileName(nullptr, "Select Image", "", "Images (*.png *.jpg)");

    if (file_name.isEmpty())
        return;

    ui->fileName_LineEdit->setText(file_name);

    QImage image(file_name);

    // memleak
    scene = new QGraphicsScene();
    view  = new QGraphicsView(scene);
    item  = new QGraphicsPixmapItem(QPixmap::fromImage(image));

    float w = item->boundingRect().width();
    float h = item->boundingRect().height();

    if(!ui->imgWidth_LineEdit->text().isEmpty())
        w = ui->imgWidth_LineEdit->text().toFloat();
    else
        ui->imgWidth_LineEdit->setText(QString::number(w));

    if(!ui->imgHeight_LineEdit->text().isEmpty())
        h = ui->imgHeight_LineEdit->text().toFloat();
    else
        ui->imgHeight_LineEdit->setText(QString::number(h));

    item->setPixmap(item->pixmap().scaled(w, h, Qt::IgnoreAspectRatio));
    scene->addItem(item);
    view->show();
}