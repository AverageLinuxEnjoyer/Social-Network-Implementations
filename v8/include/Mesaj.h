#ifndef MESAJ_H
#define MESAJ_H

#include <string>

class Mesaj {
private:
    int id;
    int id1;
    int id2;
    std::string text;
    std::string data;

public:
    Mesaj();
    Mesaj(int id, int id1, int id2, std::string text, std::string data);

    int getId() const;
    int getId1() const;
    int getId2() const;
    std::string getText() const;
    std::string getData() const;

    void setId(int id);
    void setId1(int id1);
    void setId2(int id2);
    void setText(std::string text);
    void setData(std::string data);

    bool operator==(const Mesaj& other) const;
    bool operator!=(const Mesaj& other) const;
};

#endif // MESAJ_H
