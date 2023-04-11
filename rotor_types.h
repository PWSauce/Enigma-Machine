#ifndef ROTOR_TYPES_H
#define ROTOR_TYPES_H

#include "rotor.h"
#include <vector>

struct RotorTypes
{
    std::vector<Rotor> rotor_Types {Rotor{"EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q'}, 
                                    Rotor{"AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E'}, 
                                    Rotor{"BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V'},
                                    Rotor{"ESOVPZJAYQUIRHXLNFTGKDCMWB", 'J'}, 
                                    Rotor{"VZBRGITYUPSDNHLXAWMJQOFECK", 'Z'}, 
                                    Rotor{"JPGVOUMFYQBENHZRDKASXLICTW", 'Z'},
                                    Rotor{"NZJHGRCXMYSWBOUFAIVLPEKQDT", 'Z'}, 
                                    Rotor{"FKQHTLXOCBJSPDZRAMEWNIUYGV", 'Z'}};
};

#endif // ROTOR_TYPES_H