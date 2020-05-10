 #pragma once
 #include "Comanda.h"
 #include "Mancare.h"
 #include "Shopping.h"
 #include "Repo.h"
 #include "Serializer.h"
 #include <unordered_map>
 #include <fstream>
 #include <algorithm>

template <class T> 
class AppRepoFile : public Repo<T> //: public AppRepo
{
protected:
    const char* fileName;
    char delim;
    Serializer<T>* serializer;

public:


    AppRepoFile();
    AppRepoFile(const char*, const char, Serializer<T>*);
    ~AppRepoFile();
    
    void loadFromFile(const char*);
    void saveToFile();
    void addAplicatie(const T&);
    void updateAplicatie(T&, int);
    void removeAplicatie(int);
    int dim();
    std::unordered_map<int, T>& getAll();

};

template<class T>
int AppRepoFile<T>::dim()
{
    this->loadFromFile(fileName, delim);
    return Repo<T>::dim();
}

template<class T>
std::unordered_map<int, T>& AppRepoFile<T>::getAll()
{
    this->loadFromFile(fileName, delim);
    return Repo<T>::getAll();
}

template<class T>
AppRepoFile<T>::AppRepoFile(): Repo<T>()
{
    delim = NULL;
}


template <class T>
AppRepoFile<T>::AppRepoFile(const char* fis, const char delimiter, Serializer<T>* s) : Repo<T>()
{
     fileName = fis;
     delim = delimiter;
     serializer = s;
     loadFromFile(fileName);
}

template <class T>
AppRepoFile<T>::~AppRepoFile()
{}

template <class T>
void AppRepoFile<T>::addAplicatie(const T& e)
{
    this->loadFromFile(fileName);
    Repo<T>::addAplicatie(e);
    this->saveToFile();
}

template <class T>
void AppRepoFile<T>::removeAplicatie(int pos)
{
    this->loadFromFile(fileName);
    Repo<T>::removeAplicatie(pos);
    this->saveToFile();
}

template <class T>
void AppRepoFile<T>::updateAplicatie(T& e, int pos)
{
    this->loadFromFile(fileName);
    Repo<T>::updateAplicatie(e,pos);
    this->saveToFile();
}

template <typename T>
void AppRepoFile<T>::saveToFile()
{
    if(fileName == NULL)
        return;
    std::ofstream fout(fileName);
    for (auto t : this->elems)
        fout << t.second.toStringWithDelimiter(delim) << "\n";
    fout.close();
}

template <class T>
void AppRepoFile<T>::loadFromFile(const char* fileName)
{
    if(fileName == NULL)
        return ;

    this->fileName = fileName;

    std::ifstream fin(fileName);
    Repo<T>::clear();
    std::string line;
   // if(fin.is_open())
    {
        while(std::getline(fin, line))
            Repo<T>::addAplicatie(serializer->fromString(line,delim));
        fin.close();
    }
}
