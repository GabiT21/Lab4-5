#pragma once
#include "Mancare.h"
#include <vector>

class ExceptieMancare
{
private:
    std::vector<std::string> errors;

public:
    ExceptieMancare(std::vector<std::string>);
    std::vector<std::string> getEroare();
};

class ValidareMancare: public: