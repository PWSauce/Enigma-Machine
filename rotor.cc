#include "rotor.h"
#include <iostream>

Rotor::Rotor(std::string const& out, char notch)
    : out(out), pos('A'), notch(notch)
{}

Rotor::Rotor(std::string const& out, char pos, char notch)
    : out(out), pos(pos), notch(notch)
{}

bool Rotor::Rotate()
{
    if (pos == 'Z')
        pos = 'A';
    else
        pos++;

    if (pos == notch)
    {
        return true;
    }

    return false;
}

char Rotor::Encode(char in)
{
    char a{};
    if (in + (pos - 'A') > 'Z')
    {
        int i {in + (pos - 'A') - 91};
        a = 'A' + i;
    }
    else
        a = in + (pos - 'A');
    
    a = out.at(a - 'A');

    if (a - (pos - 'A') < 'A')
    {
        int i {a - (pos - 'A') - 64};
        a = 'Z' + i;
    }
    else
        a = a - (pos - 'A');

    return a;
}

char Rotor::EncodeBack(char in)
{
    int idx{};
    char a{};
    int position{pos - 'A'};

    if (in + position > 'Z')
    {
        
        int i{in + position - 91};
        a = 'A' + i;
    }
    else
        a = in + position;
    
    for (; idx < static_cast<int>(out.size()); ++idx)
    {
        if (out.at(idx) == a)
        {
            break;
        }
    }
    
    a = 'A' + idx;
    if ((a - position) < 'A')
    {
        int i{a - position - 64};
        a = 'Z' + i;
    }
    else
        a = a - (pos - 'A');
    
    return a;
}

char Rotor::Position() const
{
    return pos;
}

void Rotor::SetPosition(char p)
{
    pos = p;
}

void Rotor::Print() const
{
    std::cout << out << std::endl;
}

std::string Rotor::Cipher() const
{
    return out;
}