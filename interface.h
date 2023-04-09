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

    void SetStartPos(std::string pos);
    void SetPlugs(std::string plugs);

    void Print() const;
private:
    void Rotate();
    std::vector<Plug> plugs;
    std::vector<Rotor> rotors;
    Rotor reflector;
};

#endif // INTERFACE_H