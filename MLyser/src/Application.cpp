#include "mlzpch.h"

#include <QtWidgets/qapplication.h>

#include "UI/MainWindow.h"
#include "Utils/Log.h"

int main(int argc, char *argv[])
{
    // Setting the path for finding the QPA plugins (situated at the location of the executable)
    QCoreApplication::addLibraryPath("plugins/");

    /* Creating the main Application */
    QApplication app(argc, argv);

    /* Creating the main window */
    MLyser::ui::MainWindow window;
    window.show();
    
    /* Initialize Application Systems */
    // Logging System
    MLyser::utils::Log::InitLogger();
    
    return app.exec();
}
