#include "../include/Mesaj.h"

int Mesaj::nr_mesaje = 0;

Mesaj::Mesaj()
{
    this->nr = ++Mesaj::nr_mesaje;
    this->text = "";
    this->expeditor = Utilizator();
    this->destinatar = Utilizator();
}

Mesaj::Mesaj(string text, Utilizator expeditor, Utilizator destinatar)
{
    this->text = text;
    this->expeditor = expeditor;
    this->destinatar = destinatar;
}

Mesaj::Mesaj(const Mesaj& mesaj)
{
    this->nr = mesaj.nr;
    this->text = mesaj.text;
    this->expeditor = mesaj.expeditor;
    this->destinatar = mesaj.destinatar;
}

Mesaj& Mesaj::operator=(const Mesaj& mesaj) {
    this->nr = mesaj.nr;
    this->text = mesaj.text;
    this->expeditor = mesaj.expeditor;
    this->destinatar = mesaj.destinatar;

    return *this;
}


int Mesaj::get_nr() const
{
    return this->nr;
}

string Mesaj::get_text() const
{
    return this->text;
}

Utilizator Mesaj::get_expeditor() const
{
    return this->expeditor;
}

Utilizator Mesaj::get_destinatar() const
{
    return this->destinatar;
}

void Mesaj::set_nr(int nr)
{
    this->nr = nr;
}

void Mesaj::set_text(string text)
{
    this->text = text;
}

void Mesaj::set_expeditor(Utilizator expeditor)
{
    this->expeditor = expeditor;
}

void Mesaj::set_destinatar(Utilizator destinatar)
{
    this->destinatar = destinatar;
}

bool Mesaj::operator==(const Mesaj& mesaj) const
{
    return this->nr == mesaj.nr && this->text == mesaj.text && this->expeditor == mesaj.expeditor && this->destinatar == mesaj.destinatar;
}

bool Mesaj::operator!=(const Mesaj& mesaj) const
{
    return !(*this == mesaj);
}

bool Mesaj::operator<(const Mesaj& mesaj) const
{
    return this->nr < mesaj.nr;
}

bool Mesaj::operator>(const Mesaj& mesaj) const
{
    return this->nr > mesaj.nr;
}
