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
    Rotate();

    a = rotors.at(2).Encode(a);
    a = rotors.at(1).Encode(a);
    a = rotors.at(0).Encode(a);
    a = reflector.Encode(a);
    a = rotors.at(0).EncodeBack(a);
    a = rotors.at(1).EncodeBack(a);
    a = rotors.at(2).EncodeBack(a);

    return a;
}

void Interface::SetStartPos(std::string pos)
{
    int idx{};
    for (char c : pos)
    {
        //std::cout << c << std::endl;
        rotors.at(idx).SetPosition(c);
        ++idx;
    }
    std::cout << std::endl;
    
}

void Interface::SetPlugs(std::string plugs)
{

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