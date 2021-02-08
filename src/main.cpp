#include <QApplication>
#include "main_window.h"

/**
 * Entry Point
 */
int main(int argc, char* argv[])
{
  QApplication app(argc, argv);
  // QApplication::setStyle("macintosh");
  MainWindow mainWindow;

  mainWindow.show();

  return app.exec();
}
