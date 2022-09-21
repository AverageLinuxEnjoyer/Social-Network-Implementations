#include "../include/Teste.h"
#include "../include/RepoFile.h"
#include "../include/UI.h"

int main() {
    teste();

    RepoFile<Utilizator> repo_utilizatori("utilizatori.txt");
    RepoFile<Eveniment> repo_evenimente("evenimente.txt");

    ServiceUtilizatori service_utilizatori(repo_utilizatori,  "mesaje.txt");
    ServiceEvenimente service_evenimente(repo_evenimente, "participanti.txt");

    UI ui(service_utilizatori, service_evenimente);

    ui.run();
}