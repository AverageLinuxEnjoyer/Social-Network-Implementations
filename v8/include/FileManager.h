#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>

#include "../include/Utilizator.h"
#include "../include/Eveniment.h"
#include "../include/Prietenie.h"
#include "../include/Mesaj.h"

class Retea;

class FileManager {
public:
    FileManager(std::string fisier_utilizatori, std::string fisier_evenimente, std::string fisier_prietenii, std::string fisier_mesaje, Retea *retea);
    ~FileManager();

    void loadFromFile();
    void saveToFile();

    void loadUtilizatoriFromFile();
    void saveUtilizatoriToFile();

    void loadEvenimenteFromFile();
    void saveEvenimenteToFile();

    void loadPrieteniiFromFile();
    void savePrieteniiToFile();

    void loadMesajeFromFile();
    void saveMesajeToFile();

private:
    std::string fisier_utilizatori;
    std::string fisier_evenimente;
    std::string fisier_prietenii;
    std::string fisier_mesaje;

    Retea *retea;
};

#endif // FILEMANAGER_H
