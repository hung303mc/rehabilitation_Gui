#ifndef JRDGUI_H
#define JRDGUI_H

#include <QMainWindow>
#include "game.h"

namespace Ui {
class JrdGui;
}

class JrdGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit JrdGui(QWidget *parent = 0);
    ~JrdGui();
private:
    Ui::JrdGui *ui;
};

#endif // JRDGUI_H
