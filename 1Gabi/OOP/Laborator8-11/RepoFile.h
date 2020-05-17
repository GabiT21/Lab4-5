 #pragma once
 #include "Repo.h"
 #include <fstream>
 #include <iostream>
 #include <map>
 #include "Serializer.h"
 #include "Utils.h"

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
    T getItemFromPos(int);
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

template <class T>
T AppRepoFile<T>::getItemFromPos(int pos)
{
    return Repo<T>::getItemFromPos(pos);
}

template <typename T>
void AppRepoFile<T>::saveToFile()
{
    if(fileName == NULL)
        return;
    std::ofstream fout(fileName);
    std::unordered_map<int, T> elems = this->getAll();
    for (auto t : elems)
       // fout << serializer->fromString(t->second, delim) << "\n";
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
    while(std::getline(fin, line))
        Repo<T>::addAplicatie(serializer->fromString(line,delim));
    fin.close();
}




//ce era inaite

// // #pragma once
// // #include "Comanda.h"
// // #include "Mancare.h"
// // #include "Shopping.h"
// // #include "Repo.h"
// // #include <unordered_map>
// // #include <iostream>
// // #include <algorithm>

// // template <class T> class AppRepoFile : public Repo<T> //: public AppRepo
// // {
// // protected:
// //     const char* fileName;

// // public:
// //     // AppRepoFile();
// //     // AppRepoFile(const char*);
// //     // virtual void saveToFile();
// //     // virtual void loadFromFile();
// //     // ~AppRepoFile();


// //     AppRepoFile();
// //     AppRepoFile(const char*);
// //     ~AppRepoFile();
// //     void loadFromFile();
// //     void saveToFile();
// //     void addAplicatie(const T&);
// //     void updateAplicatie(T&, int);
// //     void removeAplicatie(int);
// //     int dim();
// //     std::unordered_map<int, T>& getAll();

// // };

// // template<class T>
// // AppRepoFile<T>::AppRepoFile(): Repo<T>()
// // {}

// // template <class T>
// // AppRepoFile<T>::AppRepoFile(const char* fis)
// // {
// //     fileName = fis;
// // }

// // template <class T>
// // AppRepoFile<T>::~AppRepoFile()
// // {}

// // template <class T>
// // void AppRepoFile<T>::saveToFile()
// // {}

// // template <class T>
// // void AppRepoFile<T>::loadFromFile()
// // {}




