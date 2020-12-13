#include "mlzpch.h"
#include "MainWindow.h"

namespace MLyser { namespace ui {

    MainWindow::MainWindow(QWidget* parent /*= nullptr*/)
        : QMainWindow(parent)
    {
        setWindowTitle("MLyser");
        setMinimumSize(800, 600);    


    }

    MainWindow::~MainWindow()
    {
    
    }

    void MainWindow::on_button_clicked()
    {
        /*QPushButton* button = new QPushButton(
            tr("button%1").arg(this->layout->count())
        );
        this->layout->addWidget(button);*/
    }

} }