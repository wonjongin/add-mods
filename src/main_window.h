#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtGui>
#include "ui_main_window.h"
#include "minecraft.h"

/**
 * Main window class for the application
 */
class MainWindow : public QMainWindow
{
  Q_OBJECT

  public:
    MainWindow(QMainWindow* parent = 0);

  protected:
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);
    void dragMoveEvent(QDragEnterEvent* event);


  private:
    Ui::MainWindow ui;
    QStringList oriPaths;

  public slots:
    void addModsBtn();
    void addResPacksBtn();
    void openMinePath();
    void resetList();
};

#endif
