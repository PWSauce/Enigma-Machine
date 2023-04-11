#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include "rotor.h"
#include "plug.h"

class Interface
{
public:
    Interface();
    Interface(std::vector<Rotor> const& rotors, Rotor const& refl);
    Interface(std::vector<Rotor> const& rotors, std::vector<Plug> const& plugs, Rotor const& refl);

    char Encode(char c);

    void SetStartPos();
    void SetPlugs();
    std::string EncodeMessage(std::string const& message);

    void Menu();

    void Print() const;
private:
    std::string PrintPositions() const;
    std::string PrintPlugs() const;
    void Rotate();
    
    std::vector<Rotor> rotors;
    std::vector<Plug> plugs;
    Rotor reflector {"YRUHQSLDPXNGOKMIEBFZCWVJAT"};
};

#endif // INTERFACE_H