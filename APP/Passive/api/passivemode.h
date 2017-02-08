#ifndef PASSIVEMODE_H
#define PASSIVEMODE_H
#include <QWidget>

typedef struct{
    bool Status = 0;
    QString PortName;
}Port ;

class Passive: public QWidget{
    Q_OBJECT
public:
    Passive();
    QTimer * TimerPort;
    Port * Arduino;
public slots:
    void UpdatePortStatus();

};

#endif // PASSIVEMODE_H
