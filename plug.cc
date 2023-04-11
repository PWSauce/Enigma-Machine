#include "plug.h"
#include <string>

Plug::Plug()
    : a(), b()
{ }

Plug::Plug(char a_conn, char b_conn)
    : a(a_conn), b(b_conn)
{}

Plug::Plug(std::string const& connections)
    : a(), b()
{
    a = connections.at(0);
    b = connections.at(2);
}

std::string Plug::Get_Conn() const
{
    std::string s{};
    s.push_back(a);
    s.push_back(b);

    return s;
}
