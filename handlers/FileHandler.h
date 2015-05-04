//
// Created by Guillaume on 5/4/2015.
//

#ifndef LABYRINTHE_FILEHANDLER_H
#define LABYRINTHE_FILEHANDLER_H
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;
namespace handlers {
    class FileHandler
    {
    public:
        FileHandler();
        virtual ~FileHandler();

        bool fileExist(const string & file_path);
        void getDataFromFile(vector<std::string> & vector_data);
        bool putFileDataIntoVectorString(vector<std::string> & vector_data, const string & file_path);

        void    setFileSource(std::string full_path)    { _fileSource = full_path; }
        string  getFileSource()                         { return _fileSource; }

        void readFile(const string & filePath, vector<string> & datas);
        int linesCount(const string & filePath);
    protected:
    private:
        std::string _fileSource;              //Chemin du fichier source
    };
}


#endif //LABYRINTHE_FILEHANDLER_H
