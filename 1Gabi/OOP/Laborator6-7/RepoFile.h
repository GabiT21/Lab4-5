// #pragma once
// #include "Aplicatie.h"
// #include "Repo.h"
// #include <unordered_map>
// #include <iostream>
// #include <algorithm>

// class RepoFile : public Repo
// {
// private:
//     std::unordered_map < int, Aplicatie> elems;
// 	int base_id;
//     const char* fis;

// public:
//     RepoFile();
//     RepoFile(const char* fileName);
//     void loadFromFile(const char* fileName);
//     void addAplicatie(const Aplicatie&);
//     void updateAplicatie(Aplicatie&, int);
//     void removeAplicatie(int);
//     int dim() const;
//     const std::unordered_map<int, Aplicatie>& getAll() const;
//     void saveToFile();
//     void capacitate(Aplicatie[], int, int&);
//     //void clearFile();
//     ~RepoFile();

// };