#pragma once
#include "Repo.h"
#include "RepoFile.h"
#include "Utils.h"
#include "Serializer.h"
#include <fstream>

template  <class T>
class RepoFileCSV : public AppRepoFile<T>
{
public:
	RepoFileCSV() : AppRepoFile<T>(){
		AppRepoFile<T>::delim = ',';
	}
	RepoFileCSV(const char* filename, Serializer<T>* S)
	{
		this->fileName = filename;
		this->serializer = S;
		this->delim = ',';
	}
};