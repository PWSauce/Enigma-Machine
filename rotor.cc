#include "rotor.h"
#include <iostream>

Rotor::Rotor(std::string out)
    : out(out), startPos(out.at(0))
{}

bool Rotor::Rotate()
{
    out.insert(out.begin(), out.at(25));  
    out.pop_back(); 

    if (out.at(0) == startPos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char Rotor::Encode(char in)
{
    int idx {static_cast<int>(in - 'A')};
    char c {out.at(idx)};
    return c;
}

char Rotor::EncodeBack(char in)
{
    for (size_t i {}; i < out.size(); ++i)
    {
        if (out.at(i) == in)
        {
            return 'A' + i;
        }
    }
}

char Rotor::Position() const
{
    return out.at(0);
}

void Rotor::Print() const
{
    std::cout << out << std::endl;
}