#ifndef MESAJ_H
#define MESAJ_H

#include <string>
#include <fstream>

class Mesaj {
public:
    Mesaj();
    Mesaj(int sender_id, int receiver_id, std::string content);
    Mesaj(const Mesaj& other);
    ~Mesaj();

    Mesaj& operator=(const Mesaj& other);

    int senderId() const;
    int receiverId() const;

    std::string getText() const;
    void setText(const std::string &text_);

    friend std::ostream& operator<<(std::ostream& os, const Mesaj& mesaj);
    friend std::istream& operator>>(std::istream& is, Mesaj& mesaj);

private:
    int sender_id;
    int receiver_id;
    std::string text;
};

#endif // MESAJ_H
