#ifndef DATALOG_H
#define DATALOG_H

#include <QSqlDatabase>

class DataLog
{
public:
    /**
     * @brief Constructor
     *
     * Constructor sets up connection with db and opens it
     * @param path - absolute path to db file
     */
    DataLog(const QString& path);

    /**
     * @brief Destructor
     *
     * Close the db connection
     */
    ~DataLog();

    bool isOpen() const;

    /**
     * @brief Add data to db
     * @param DesirePos - Data of Desire Position to add
	 * @param ActualPos - Data of Actual Position to add
	 * @param DeviceSup - Data of Device Support to add
     * @return true - Data added successfully, false - Data not added
     */
    bool WriteData(int DesirePos, int ActualPos, int DeviceSup);
	
	/**
     * @brief Read data from db
     * @param data - Data of Desire Position/Actual Position/Device Support to accessed
     * @return true - Data accessed successfully, false - Data not accessed
     */
//    bool DataLog::ReadData(int &data);
	
	#if 0
	bool DataLog::ReadDataDaily(int *data);
	bool DataLog::ReadDataMonthly(int *data);
	bool DataLog::ReadDataQuarterly(int *data); 
	bool DataLog::ReadDataYearly(int *data);  
	#endif

private:
    QSqlDatabase m_db;
};

#endif // DATALOG_H
