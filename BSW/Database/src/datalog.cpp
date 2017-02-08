#include <datalog.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QDateTime>

DataLog::DataLog(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

DataLog::~DataLog()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

bool DataLog::isOpen() const
{
    return m_db.isOpen();
}

bool DataLog::WriteData(int DesirePos,int ActualPos, int DeviceSup)
{
    bool writeStatus = false;

    if (!DesirePos)
    {
		QTime time = QTime::currentTime();
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO DATALOG (DESIREPOS, ACTUALPOS, DEVICESUP, CURRENTTIME)"
                         " VALUES (:DESIREPOS, :ACTUALPOS, :DEVICESUP, :CURRENTTIME");
        queryAdd.bindValue(":DESIREPOS", DesirePos);
        queryAdd.bindValue(":ACTUALPOS", ActualPos);
        queryAdd.bindValue(":DEVICESUP", DeviceSup);
		queryAdd.bindValue(":CURRENTTIME", time.toString());

        if(queryAdd.exec())
        {
            writeStatus = true;
        }
        else
        {
            qDebug() << "add data failed: " << queryAdd.lastError();
        }
    }
   else
   {
       qDebug() << "add data failed: Desire Position cannot be empty";
   }

    return writeStatus;
}

//bool DataLog::ReadData(int *data)
//{
//	bool readStatus = false;
//	QSqlQuery queryRead;
//	queryRead.prepare("SELECT data FROM DATALOG");
	
//	if (checkQuery.exec())
//    {
//        if (checkQuery.next())
//        {
//            readStatus = true;
//        }
//    }
//    else
//    {
//        qDebug() << "person exists failed: " << checkQuery.lastError();
//    }

//    return readStatus;
//}

#if 0
bool DataLog::ReadDataDaily(int *data)
{
	bool readStatus = false;
	QSqlQuery queryRead;
	queryRead.prepare("SELECT data FROM DATALOG WHERE CurrentTime <= date('now')");
	
	if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            readStatus = true;
        }
    }
    else
    {
        qDebug() << "person exists failed: " << checkQuery.lastError();
    }

    return readStatus;
}

#endif

