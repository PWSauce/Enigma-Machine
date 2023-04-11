#ifndef ROTOR_TYPES_H
#define ROTOR_TYPES_H

#include "rotor.h"
#include <vector>

struct RotorTypes
{
    std::vector<Rotor> rotor_Types {Rotor{"EKMFLGDQVZNTOWYHXUSPAIBRCJ"}, 
                                    Rotor{"AJDKSIRUXBLHWTMCQGZNPYFVOE"}, 
                                    Rotor{"BDFHJLCPRTXVZNYEIWGAKMUSQO"},
                                    Rotor{"ESOVPZJAYQUIRHXLNFTGKDCMWB"}, 
                                    Rotor{"VZBRGITYUPSDNHLXAWMJQOFECK"}, 
                                    Rotor{"JPGVOUMFYQBENHZRDKASXLICTW"},
                                    Rotor{"NZJHGRCXMYSWBOUFAIVLPEKQDT"}, 
                                    Rotor{"FKQHTLXOCBJSPDZRAMEWNIUYGV"}};
} Rotor_Types;

#endif // ROTOR_TYPES_H