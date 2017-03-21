#ifndef SERIAL_H
#define SERIAL_H

#include <QWidget>
#include <QtSerialPort/QtSerialPort>
#include <QFile>
#include <Qtimer>

#define ENABLE_PLAYER 1
#define DISABLE_PLAYER 2
#define RUN_PLAYER 3
#define RUN_MODE1 4
#define RUN_MODE3 5
#define STOP_PLAYER 6

/******************************************************************************
*
******************************************************************************/
namespace Ui {
    class Serial;
}

//class QSerialPort


class Serial : public QWidget
{
    Q_OBJECT

public:
    Serial();
    ~Serial();
    /* Arduino micro: VID = 9025, PID = 32823*/
    static const quint16 JRD_VID = 9025;
    static const quint16 JRD_PID = 32823;
    static const quint16 TEST_VID = 4292;
    static const quint16 TEST_PID = 60000;
    bool JRD_is_available = false;
    QString JRD_port_name;

    void update_chart(const QPoint &newPoint);
    void save_file(const QPoint &newPoint);
    void m_serial_test();
    void sendCommand(int mode);
    int serialValue;
    QTimer *SerialTimer;

private:
    QSerialPort *serialPort;
    Ui::Serial *ui;
    QByteArray serialRawData;
    QString serialRawBuffer;
    QStringList serialSplitBuffer;
    QString serialParsedData;
    void setupSerialPort();

private slots:
    void serialReceived();
};

#endif // SERIALTEST2_H
