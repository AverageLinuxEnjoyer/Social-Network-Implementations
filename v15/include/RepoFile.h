#ifndef REPOFILE_H
#define REPOFILE_H

#include "Repo.h"

#include <string>
#include <fstream>

template<class T>
class RepoFile : public Repo<T> {
public:
    RepoFile() = default;
    RepoFile(const std::string& fileName);
    RepoFile(const RepoFile<T>& repo) = default;

    virtual ~RepoFile();

private:
    std::string fileName;
};

template<class T>
inline RepoFile<T>::RepoFile(const std::string& fileName)
    : Repo<T>(), fileName(fileName)
{
    std::ifstream f(fileName);
    if (f.is_open()) {
        T elem;
        while (f >> elem) {
            this->elems.push_back(elem);
        }
    }
}

template<class T>
inline RepoFile<T>::~RepoFile()
{
    std::ofstream f(fileName);
    if (f.is_open()) {
        for (int i = 0; i < this->elems.size(); i++) {
            f << this->elems[i] << '\n';
        }
    }
}


#endif // REPOFILE_H
