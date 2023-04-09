#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include "rotor.h"
#include "plug.h"

class Interface
{
public:
private:
    std::vector<Plug> plugs;
    std::vector<Rotor> rotors;
};

#endif // INTERFACE_H