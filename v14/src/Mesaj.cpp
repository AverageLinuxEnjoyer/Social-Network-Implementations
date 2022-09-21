#include "../include/Mesaj.h"
#include <iomanip>

Mesaj::Mesaj()
{
    
}

Mesaj::Mesaj(std::string nume_expeditor, std::string nume_destinatar, std::string content_mesaj)
{
    this->nume_expeditor = nume_expeditor;
    this->nume_destinatar = nume_destinatar;
    this->content_mesaj = content_mesaj;
}

Mesaj::~Mesaj()
{
    
}


std::string Mesaj::getNumeExpeditor()
{
    return this->nume_expeditor;
}

std::string Mesaj::getNumeDestinatar()
{
    return this->nume_destinatar;
}

std::string Mesaj::getContentMesaj()
{
    return this->content_mesaj;
}

void Mesaj::setNumeExpeditor(std::string nume_expeditor)
{
    this->nume_expeditor = nume_expeditor;
}

void Mesaj::setNumeDestinatar(std::string nume_destinatar)
{
    this->nume_destinatar = nume_destinatar;
}

void Mesaj::setContentMesaj(std::string content_mesaj)
{
    this->content_mesaj = content_mesaj;
}

bool Mesaj::operator==(const Mesaj& other)
{
    return this->nume_expeditor == other.nume_expeditor && this->nume_destinatar == other.nume_destinatar && this->content_mesaj == other.content_mesaj;
}

std::ostream& operator<<(std::ostream& os, const Mesaj& m)
{
    os << m.nume_expeditor << " " << m.nume_destinatar << " " << std::quoted(m.content_mesaj);
    return os;
}

std::istream& operator>>(std::istream& is, Mesaj& m)
{
    is >> m.nume_expeditor >> m.nume_destinatar >> std::quoted(m.content_mesaj);
    return is;
}