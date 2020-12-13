#pragma once

#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qmenubar.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qboxlayout.h>

namespace MLyser { namespace ui { 
    
    /// The Main Window of the app
    class MainWindow : public QMainWindow
    {
    public:
        MainWindow(QWidget* parent = nullptr);
        ~MainWindow();

        void on_button_clicked();

    private:
        QBoxLayout* layout;

    };
} }
