//
// Created by Guillaume on 5/4/2015.
//

#include "FileHandler.h"

using namespace handlers;

FileHandler::FileHandler()
{
    _fileSource = "";
}

FileHandler::~FileHandler()
{
    //dtor
}

/**
 * R�cup�re les donn�es contenues dans le fichier source pour les �crire dans un vector de string.
 * @param vector_data -> Le vecteur � remplir de donn�es
 * @return vector<std::string>
 * @exception Lance une exception runtime_error si le fichier source n'a pu �tre ouvert
 */
void FileHandler::getDataFromFile(vector<std::string> & vector_data)
{
    if(vector_data.empty())
    {
        if(!this->putFileDataIntoVectorString(vector_data, _fileSource))
        {
            vector_data.clear();
            throw runtime_error("Impossible d'ouvrir le fichier: " + _fileSource);
        }
    }
    else cerr << "vector is not empty" << endl;
}

/**
 * R�cup�re le contenu ligne par ligne du fichier pass� en param�tre et l'ajoute au vector.
 * @param vector_data -> Le vecteur � remplir de donn�es
 * @param file_path -> Une string contenant le chemin complet vers le fichier � lire
 * Exemple: C:/exemple.txt
 * @return "true" si la r�cup�ration et l'ouverture du fichier s'est bien pass�e. "false" sinon.
 */
bool FileHandler::putFileDataIntoVectorString(vector<std::string> & vector_data, const string & file_path)
{
    if(file_path.empty())
        return false;

    string zLine;
    std::ifstream zFile;
    vector_data.clear();

    zFile.open(file_path.c_str());
    if(zFile.is_open())
    {
        while( std::getline(zFile, zLine) ) {
            vector_data.push_back(zLine);
        }
            zFile.close();
    }
    else
    {
        std::cerr << "Impossible d'ouvrir le fichier: " << file_path << std::endl;
        return false;
    }
    return true;
}

/**
 * V�rifie l'existence du fichier en param�tre
 * @param file_path -> Une string contenant le chemin complet vers le fichier � �crire
 * Exemple: C:/exemple.txt
 * @return "true" si le fichier existe, "false" dans le cas contraire.
 */
bool FileHandler::fileExist(const string & file_path)
{
    ifstream zFile(file_path);
    if (zFile)
        return true; //Le fichier existe
    return false;
}

void FileHandler::readFile(const string & filePath, vector<string> & datas)
{
    //On v�rifie si le param�tre n'est pas vide
    if(filePath.empty())
        throw invalid_argument("Le chemin du fichier � ouvrir est vide.");

    //Si le fichier existe
    if(this->fileExist(filePath))
    {
        string line = "";
        datas.clear();
        datas.reserve(this->linesCount(filePath));  //Etape obligatoire pour pr�venir une exception bad_alloc() sur les
        //fichiers de plusieurs millions de lignes.

        //On r�cup�re chaque ligne et on la pousse dans le vecteur pass� en param�tre.
        ifstream file;
        file.open(filePath.c_str());
        if(file.is_open())
        {
            while( std::getline(file, line) )
                datas.push_back(line);
            file.close();
        }
    }
        // Si une erreur a �t� lev�e � l'ouverture du fichier
    else
        throw runtime_error("Impossible d'ouvrir le fichier: " + filePath);
}

int FileHandler::linesCount(const string & filePath)
{
    int countLines = 0;
    string line = "";
    std::ifstream file;

    file.open(filePath.c_str());
    if(file.is_open())
    {
        while (getline(file, line))
            ++countLines;
        file.close();
    }
    return countLines;
}
