#include "main_window.h"
#include "moc_main_window.cpp"
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include "minecraft.h"
#include "util.h"

/**
 * Constructor
 */
MainWindow::MainWindow(QMainWindow* parent)
  : QMainWindow(parent)
{
  this->ui.setupUi(this);
  setAcceptDrops(true);
  ui.pushButtonMinePath->setText(Minecraft::getMinecraftPath());
  connect(ui.pushButtonModsAdd, SIGNAL(clicked()), this, SLOT(addModsBtn()));
  connect(ui.pushButtonResPack, SIGNAL(clicked()), this, SLOT(addResPacksBtn()));
  connect(ui.pushButtonMinePath, SIGNAL(clicked()), this, SLOT(openMinePath()));
  connect(ui.pushButtonReset, SIGNAL(clicked()), this, SLOT(resetList()));
}

void MainWindow::dragEnterEvent(QDragEnterEvent* event)
{
    event->acceptProposedAction();
}

void MainWindow::dragMoveEvent(QDragEnterEvent* event)
{
    event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent* event)
{
    const QMimeData* mimeData = event->mimeData();
    QPixmap pixmap;
    ui.labelMods->clear();
    this->oriPaths.clear();
    QStringList fileNames;

    if (mimeData->hasUrls())
    {
        QList<QUrl> paths = mimeData->urls();
        foreach(QUrl path, paths)
        {
            QString pathstr = path.toLocalFile();
            QStringList pathList = pathstr.split("/");
            QString fileName = pathList.at(pathList.length()-1);
            // QString tmp = ui.labelMods->text();
            // qDebug() << tmp;
            // ui.labelMods->setText(tmp + "\n" + fileName);
            fileNames << fileName;
            this->oriPaths << path.toLocalFile();
            pixmap.load(path.toLocalFile());

            if(!pixmap.isNull())
            {
                ui.labelMods->setPixmap(pixmap);
            }
        }
        QString str = fileNames.join("\n");
        ui.labelMods->setText(str);
    }
}

void MainWindow::addModsBtn()
{
  // QMessageBox::information(this, "모드", "Hello");
  foreach(QString oriPath, this->oriPaths)
  {
    Minecraft::intoMinecraftPath(0 , oriPath);
    qDebug() << oriPath << ": is copied!";
  }
  ui.labelMods->setText("완료되었습니다.\n넣을 모드나 리소스팩을 를 여기에 끌어다 놓으세요");
}
void MainWindow::addResPacksBtn()
{
  // QMessageBox::information(this, "리소스팩", "Hello");
  foreach(QString oriPath, this->oriPaths)
  {
    Minecraft::intoMinecraftPath(1 , oriPath);
  }
  ui.labelMods->setText("완료되었습니다.\n넣을 모드나 리소스팩을 를 여기에 끌어다 놓으세요");
}
void MainWindow::openMinePath()
{
  revealFile(this, Minecraft::getMinecraftPath()+"/mods");
}
void MainWindow::resetList()
{
  ui.labelMods->setText("넣을 모드나 리소스팩을 를 여기에 끌어다 놓으세요");
  this->oriPaths.clear();
}