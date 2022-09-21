#ifndef DATA_H
#define DATA_H

#include <time.h>
#include <iostream>
using namespace std;

struct Data {
    int zi;
    int luna;
    int an;
    
    static Data getDataDeAzi() {
        Data data;
        time_t t = time(0);
        struct tm * now = localtime( & t );
        data.zi = now->tm_mday;
        data.luna = now->tm_mon + 1;
        data.an = now->tm_year + 1900;
        return data;
    }
    bool operator==(const Data& data) const {
        return zi == data.zi && luna == data.luna && an == data.an;
    }
    bool operator!=(const Data& data) const {
        return !(*this == data);
    }
    bool operator<(const Data& data) const {
        if (an < data.an) {
            return true;
        } else if (an == data.an) {
            if (luna < data.luna) {
                return true;
            } else if (luna == data.luna) {
                if (zi < data.zi) {
                    return true;
                }
            }
        }
        return false;
    }

    bool operator>(const Data& data) const {
        return !(*this < data);
    }
    // consideram ca toate lunile au 30 zile
    Data operator+(int nrZile) const {
        Data data = *this;
        int nrLuni = 0;
        int nrAni = 0;
        while (nrZile > 0) {
            if (data.zi == 30) {
                data.zi = 1;
                data.luna++;
            } else {
                data.zi++;
            }
            if (data.luna == 13) {
                data.luna = 1;
                data.an++;
            }
            nrZile--;
        } 

        return data; 
    }
    // consideram ca toate lunile au 30 zile
    Data operator-(int nrZile) const {
        Data data = *this;
        int nrLuni = 0;
        int nrAni = 0;
        while (nrZile > 0) {
            if (data.zi == 1) {
                data.zi = 30;
                data.luna--;
            } else {
                data.zi--;
            }
            if (data.luna == 0) {
                data.luna = 12;
                data.an--;
            }
            nrZile--;
        } 

        return data; 
    }
    Data operator+(const Data& data) const {
        Data dataNoua = *this;
        dataNoua.zi += data.zi;
        dataNoua.luna += data.luna;
        dataNoua.an += data.an;
        while (dataNoua.luna > 12) {
            dataNoua.luna -= 12;
            dataNoua.an++;
        }
        while (dataNoua.zi > 30) {
            dataNoua.zi -= 30;
            dataNoua.luna++;
        }

        return dataNoua;
    }
    Data operator-(const Data& data) const {
        Data dataNoua = *this;
        dataNoua.zi -= data.zi;
        dataNoua.luna -= data.luna;
        dataNoua.an -= data.an;
        while (dataNoua.luna < 1) {
            dataNoua.luna += 12;
            dataNoua.an--;
        }
        while (dataNoua.zi < 1) {
            dataNoua.zi += 30;
            dataNoua.luna--;
        }

        return dataNoua;
    }
    friend ostream& operator<<(ostream& out, const Data& data) {
        out << data.zi << "." << data.luna << "." << data.an;
        return out;
    }
    friend istream& operator>>(istream& in, Data& data) {
        string s;
        in >> s;
        
        int zi, luna, an;
        sscanf(s.c_str(), "%d.%d.%d", &zi, &luna, &an);
        data.zi = zi;
        data.luna = luna;
        data.an = an;

        return in;
    }
};

#endif // DATA_H
