#include "interface.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

Interface::Interface(std::vector<Rotor> const& rotors, Rotor const& refl)
    : rotors(rotors), reflector(refl)
{}

Interface::Interface(std::vector<Rotor> const& rotors, std::vector<Plug> const& plugs, Rotor const& refl)
    : rotors(rotors), plugs(plugs), reflector(refl)
{}

char Interface::Encode(char a)
{
    for (Plug & b : plugs)
    {
        std::string p {b.Get_Conn()};

        if (p.at(0) == a)
        {
            a = p.at(1);
            break;
        }
        if (p.at(1) == a)
        {
            a = p.at(0);
            break;
        }
    }

    Rotate();

    a = rotors.at(2).Encode(a);
    a = rotors.at(1).Encode(a);
    a = rotors.at(0).Encode(a);
    a = reflector.Encode(a);
    a = rotors.at(0).EncodeBack(a);
    a = rotors.at(1).EncodeBack(a);
    a = rotors.at(2).EncodeBack(a);

    for (Plug & b : plugs)
    {
        std::string p {b.Get_Conn()};

        if (p.at(0) == a)
        {
            a = p.at(1);
            break;
        }
        if (p.at(1) == a)
        {
            a = p.at(0);
            break;
        }
    }

    return a;
}

void Interface::SetStartPos(std::string pos)
{
    int idx{};
    for (char c : pos)
    {
        rotors.at(idx).SetPosition(c);
        ++idx;
    }
    
}

void Interface::SetPlugs(std::string pl)
{
    std::stringstream ss {pl};
    std::string p {};

    while(getline(ss, p, ' '))
    {
        plugs.push_back(Plug(p.at(0), p.at(1)));
    }
}

void Interface::Rotate()
{
    if (rotors.at(2).Rotate())
    {
        if (rotors.at(1).Rotate())
        {
            rotors.at(0).Rotate();
        }
    }
}

void Interface::Print() const
{
    for (auto const& a : rotors)
    {
        a.Print();
    }
}