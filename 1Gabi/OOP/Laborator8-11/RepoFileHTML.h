#pragma once
#include "Repo.h"
#include "RepoFile.h"
#include "Utils.h"
#include "Serializer.h"
#include <fstream>

template  <class T>
class RepoFileHTML : public AppRepoFile<T>
{
public:
	RepoFileHTML() : AppRepoFile<T>() {
		delim = "<br>";
	}
	RepoFileHTML(const char* filename, Serializer<T>* S)
	{
		this->fileName = filename;
		this->serializer = S;
		this->delim = "<br>";
	}
};