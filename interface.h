#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include "rotor.h"
#include "plug.h"

class Interface
{
public:
    Interface(std::vector<Rotor> const& rotors, Rotor const& refl);
    Interface(std::vector<Rotor> const& rotors, std::vector<Plug> const& plugs, Rotor const& refl);

    char Encode(char c);

    void SetStartPos(std::string const& pos);
    void SetPlugs(std::string const& plugs);

    void Print() const;
private:
    void Rotate();
    char PlugChange(char c);
    std::vector<Rotor> rotors;
    std::vector<Plug> plugs;
    Rotor reflector;
};

#endif // INTERFACE_H