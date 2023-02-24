#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QFileDialog>
#include <QtGui/QImage>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtEvents>

namespace Ui 
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void open_file_dialog();
    //void on_img_width_change(const QString &text);
    //void on_img_height_change(const QString &text);

protected:
    void resizeEvent(QResizeEvent *event) override;
    
private:
    Ui::MainWindow*      ui;
    QGraphicsPixmapItem* item;
    QGraphicsScene*      scene;
    QGraphicsView*       view;
};

#endif // MAINWINDOW_H
