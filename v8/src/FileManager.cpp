#include "../include/FileManager.h"
#include <fstream>
#include <sstream>
#include "../include/Retea.h"

FileManager::FileManager(std::string fisier_utilizatori, std::string fisier_evenimente, std::string fisier_prietenii, std::string fisier_mesaje, Retea* retea)
{
    this->fisier_utilizatori = fisier_utilizatori;
    this->fisier_evenimente = fisier_evenimente;
    this->fisier_prietenii = fisier_prietenii;
    this->fisier_mesaje = fisier_mesaje;
    this->retea = retea;
}

FileManager::~FileManager()
{
    
}

void FileManager::loadFromFile() {
    loadUtilizatoriFromFile();
    loadEvenimenteFromFile();
    loadPrieteniiFromFile();
    loadMesajeFromFile();
}

void FileManager::saveToFile() {
    saveMesajeToFile();
    savePrieteniiToFile();
    saveEvenimenteToFile();
    saveUtilizatoriToFile();
}

void FileManager::loadUtilizatoriFromFile() {
    std::ifstream f(fisier_utilizatori);
    std::string line;
    while (std::getline(f, line)) {
        std::stringstream ss(line);
        std::string id, nume, prenume, email, parola, isStudent;
        std::getline(ss, id, ',');
        std::getline(ss, nume, ',');
        std::getline(ss, prenume, ',');
        std::getline(ss, email, ',');
        std::getline(ss, parola, ',');
        std::getline(ss, isStudent, ',');
        int id_int = std::stoi(id);
        bool isStudent_bool = std::stoi(isStudent);
        
        retea->adaugaUtilizator(Utilizator(id_int, nume, prenume, email, parola, isStudent_bool));
    }
}

void FileManager::saveUtilizatoriToFile() {
    std::ofstream f(fisier_utilizatori);
    Lista<Utilizator> utilizatori = retea->getUtilizatori();

    for (int i = 0; i < utilizatori.size(); i++) {
        Utilizator utilizator = utilizatori.get(i);
        f << utilizator.getId() << "," << utilizator.getNume() << "," << utilizator.getPrenume() << "," << utilizator.getEmail() << "," << utilizator.getParola() << "," << utilizator.isStudent() << std::endl;
    }
}

void FileManager::loadEvenimenteFromFile() {
    std::ifstream f(fisier_evenimente);
    std::string line;
    while (std::getline(f, line)) {
        std::stringstream ss(line);
        std::string id, nume, data, locatie;
        std::getline(ss, id, ',');
        std::getline(ss, nume, ',');
        std::getline(ss, data, ',');
        std::getline(ss, locatie, ',');
        int id_int = std::stoi(id);
        retea->adaugaEveniment(Eveniment(id_int, nume, data, locatie));
    }
}

void FileManager::saveEvenimenteToFile() {
    std::ofstream f(fisier_evenimente);
    Lista<Eveniment> evenimente = retea->getEvenimente();

    for (int i = 0; i < evenimente.size(); i++) {
        Eveniment eveniment = evenimente.get(i);
        f << eveniment.getId() << "," << eveniment.getNume() << "," << eveniment.getData() << "," << eveniment.getLocatie() << std::endl;
    }
}

void FileManager::loadPrieteniiFromFile() {
    std::ifstream f(fisier_prietenii);
    std::string line;
    while (std::getline(f, line)) {
        std::stringstream ss(line);
        std::string id_utilizator1, id_utilizator2;
        std::getline(ss, id_utilizator1, ',');
        std::getline(ss, id_utilizator2, ',');
        int id_utilizator1_int = std::stoi(id_utilizator1);
        int id_utilizator2_int = std::stoi(id_utilizator2);
        retea->adaugaPrietenie(id_utilizator1_int, id_utilizator2_int);
    }
}

void FileManager::savePrieteniiToFile() {
    std::ofstream f(fisier_prietenii);
    Lista<Prietenie> prietenii = retea->getPrietenii();

    for (int i = 0; i < prietenii.size(); i++) {
        Prietenie prietenie = prietenii.get(i);
        f << prietenie.getId1() << "," << prietenie.getId2() << std::endl;
    }
}

void FileManager::loadMesajeFromFile() {
    std::ifstream f(fisier_mesaje);
    std::string line;
    while (std::getline(f, line)) {
        std::stringstream ss(line);
        std::string id, id_utilizator1, id_utilizator2, text, data;
        std::getline(ss, id, ',');
        std::getline(ss, id_utilizator1, ',');
        std::getline(ss, id_utilizator2, ',');
        std::getline(ss, text, ',');
        std::getline(ss, data, ',');

        int id_int = std::stoi(id);
        int id_utilizator1_int = std::stoi(id_utilizator1);
        int id_utilizator2_int = std::stoi(id_utilizator2);

        retea->adaugaMesaj(Mesaj(id_int, id_utilizator1_int, id_utilizator2_int, text, data));
    }
}

void FileManager::saveMesajeToFile() {
    std::ofstream f(fisier_mesaje);
    Lista<Mesaj> mesaje = retea->getMesaje();

    for (int i = 0; i < mesaje.size(); i++) {
        Mesaj mesaj = mesaje.get(i);
        f << mesaj.getId() << "," << mesaj.getId1() << "," << mesaj.getId2() << "," << mesaj.getText() << "," << mesaj.getData() << std::endl;
    }
}
