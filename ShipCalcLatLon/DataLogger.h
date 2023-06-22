#ifndef DATALOGGER_H
#define DATALOGGER_H

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <QDir>

class DataLogger
{
private:
    std::ofstream outFile;
    std::string directoryPath;
    std::string ParticipantId;

    std::string getCurrentDate()
    {
        auto now = std::chrono::system_clock::now();
        std::time_t time = std::chrono::system_clock::to_time_t(now);
        char buffer[20];
        std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&time));
        return buffer;
    }
    bool CreateFolder(const QString &floderPath)
    {
        QDir dir;
        bool flag=false;
        if(!dir.exists(floderPath))
        {
            if(dir.mkdir(floderPath))
                flag = true;
        }
        else
            flag=true;
        return flag;
    }

public:
    DataLogger(const std::string& directory) : directoryPath(directory) {}

    std::string SetFileName(std::string fileName)
    {
        ParticipantId=fileName;
        return ParticipantId;
    }
    std::string FileName()
    {
        return ParticipantId;
    }
    void logData(const std::string& data) {
        std::string currentDate = getCurrentDate();
        std::string filePath = directoryPath + "/" + currentDate+ FileName() + ".txt";

        outFile.open(filePath, std::ios::app);
        if (!outFile.is_open()) {
            std::cout << "Failed to open the file for writing." << std::endl;
            return;
        }

        outFile << data ;//<< std::endl;
        outFile.close();
    }

    std::string readData(const std::string& filePath)
    {
        std::ifstream inFile(filePath);
        std::string data;

        if (!inFile.is_open())
        {
            std::cout << "Failed to open the file for reading." << std::endl;
            return data;
        }

        std::string line;
        while (std::getline(inFile, line))
        {
            data += line + "\n";
        }

        inFile.close();
        return data;
    }
};

#endif // DATALOGGER_H
