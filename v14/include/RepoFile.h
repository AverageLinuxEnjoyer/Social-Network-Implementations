#ifndef REPOFILE_H
#define REPOFILE_H

#include <string>
#include <fstream>
#include "Lista.h"

template<class T>
class RepoFile {
public:
    RepoFile(std::string fileName = "");
    ~RepoFile();

    void setFileName(std::string fileName);
    std::string getFileName();

    void loadFromFile();
    void saveToFile();

    void add(T elem);
    void remove(T elem);
    void remove(int index);
    T& get(int pos);
    int getSize();

private:
    std::string fileName;
    List<T> list;
};

template<class T>
inline RepoFile<T>::RepoFile(std::string fileName) {
    this->fileName = fileName;
};

template<class T>
inline RepoFile<T>::~RepoFile() {};

template<class T>
inline void RepoFile<T>::setFileName(std::string fileName) {
    this->fileName = fileName;
};

template<class T>
inline std::string RepoFile<T>::getFileName() {
    return this->fileName;
};

template<class T>
inline void RepoFile<T>::loadFromFile() {
    std::ifstream file(this->fileName);
    if (file.is_open()) {
        T elem;
        while (file >> elem) {
            this->list.append(elem);
        }
        file.close();
    }
};

template<class T>
inline void RepoFile<T>::saveToFile() {
    std::ofstream file(this->fileName);
    if (file.is_open()) {
        for (int i = 0; i < this->list.size(); i++) {
            file << this->list.get(i) << "\n";
        }
        file.close();
    }
};

template<class T>
inline void RepoFile<T>::add(T elem) {
    this->list.append(elem);
}

template<class T>
inline void RepoFile<T>::remove(T elem) {
    this->list.remove(elem);
}

template<class T>
inline void RepoFile<T>::remove(int index) {
    this->list.remove(index);
}

template<class T>
inline T& RepoFile<T>::get(int pos) {
    return this->list.get(pos);
}

template<class T>
inline int RepoFile<T>::getSize() {
    return this->list.size();
}



#endif // REPOFILE_H
