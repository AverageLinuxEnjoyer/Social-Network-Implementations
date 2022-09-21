#include "../include/interfata.h"

void Interfata::run() {
    int optiune;
    do {
        std::cout << "1. Afisare utilizatori" << std::endl;
        std::cout << "2. Adaugare utilizatori" << std::endl;
        std::cout << "3. Modificare utilizatori" << std::endl;
        std::cout << "4. Stergere utilizatori" << std::endl;
        std::cout << "5. Afisare evenimente" << std::endl;
        std::cout << "6. Adaugare evenimente" << std::endl;
        std::cout << "7. Modificare evenimente" << std::endl;
        std::cout << "8. Stergere evenimente" << std::endl;
        std::cout << "9. Afisare evenimente participate" << std::endl;
        std::cout << "10. Participare eveniment" << std::endl;
        std::cout << "11. Anulare participare" << std::endl;
        std::cout << "12. Afisare prieteni" << std::endl;
        std::cout << "13. Adaugare prieteni" << std::endl;
        std::cout << "14. Stergere prieteni" << std::endl;
        std::cout << "15. Afisare mesaje" << std::endl;
        std::cout << "16. Adaugare mesaje" << std::endl;
        std::cout << "0. Iesire" << std::endl;
        std::cout << "Introduceti optiunea: ";

        std::cin >> optiune;
        switch (optiune) {
            case 1:
                meniu_afisare_utilizatori();
                break;
            case 2:
                meniu_adaugare_utilizatori();
                break;
            case 3:
                meniu_modificare_utilizatori();
                break;
            case 4:
                meniu_stergere_utilizatori();
                break;
            case 5:
                meniu_afisare_evenimente();
                break;
            case 6:
                meniu_adaugare_evenimente();
                break;
            case 7:
                meniu_modificare_evenimente();
                break;
            case 8:
                meniu_stergere_evenimente();
                break;
            case 9:
                meniu_afisare_evenimente_participate();
                break;
            case 10:
                meniu_participare_eveniment();
                break;
            case 11:
                meniu_anulare_participare();
                break;
            case 12:
                meniu_afisare_prieteni();
                break;
            case 13:
                meniu_adaugare_prieteni();
                break;
            case 14:
                meniu_stergere_prieteni();
                break;
            case 15:
                meniu_afisare_mesaje();
                break;
            case 16:
                meniu_adaugare_mesaje();
                break;
            case 0:
                break;
            default:
                std::cout << "Optiune invalida!\n";
                break;
        }
    } while (optiune != 0);
}

void Interfata::meniu_afisare_utilizatori() {
    std::vector<Utilizator> utilizatori = retea.getUtilizatori();

    std::cout << "Utilizatori:\n";
    for (Utilizator utilizator : utilizatori) {
        std::cout << utilizator.getId() << " " << utilizator.getNume() << " " << utilizator.getPrenume() << " " << utilizator.getVarsta() << " " << utilizator.getAdresa() << " " << utilizator.getTelefon() << " " << utilizator.getEmail() << " " << utilizator.getParola() << "\n";
    }
}

void Interfata::meniu_adaugare_utilizatori() {
    int id;
    std::string nume, prenume, adresa, telefon, email, parola;
    int varsta;

    std::cout << "Introduceti id-ul: ";
    std::cin >> id;
    std::cout << "Introduceti numele: ";
    std::cin >> nume;
    std::cout << "Introduceti prenumele: ";
    std::cin >> prenume;
    std::cout << "Introduceti varsta: ";
    std::cin >> varsta;
    std::cout << "Introduceti adresa: ";
    std::cin >> adresa;
    std::cout << "Introduceti telefonul: ";
    std::cin >> telefon;
    std::cout << "Introduceti emailul: ";
    std::cin >> email;
    std::cout << "Introduceti parola: ";
    std::cin >> parola;

    Utilizator u;
    u.setId(id)
    .setNume(nume)
    .setPrenume(prenume)
    .setVarsta(varsta)
    .setAdresa(adresa)
    .setTelefon(telefon)
    .setEmail(email)
    .setParola(parola);

    if (retea.adaugareUtilizator(u))
        std::cout << "Utilizatorul a fost adaugat cu succes!\n";
    else
        std::cout << "Exista deja un utilizator cu acest id.!\n";
}

void Interfata::meniu_modificare_utilizatori() {
    std::string nume, prenume, adresa, telefon, email, parola;
    int varsta;
    int id;

    std::cout << "Introduceti id-ul utilizatorului: ";
    std::cin >> id;

    std::cout << "Introduceti numele nou: ";
    std::cin >> nume;
    std::cout << "Introduceti prenumele nou: ";
    std::cin >> prenume;
    std::cout << "Introduceti varsta noua: ";
    std::cin >> varsta;
    std::cout << "Introduceti adresa noua: ";
    std::cin >> adresa;
    std::cout << "Introduceti numarul de telefon nou: ";
    std::cin >> telefon;
    std::cout << "Introduceti emailul nou: ";
    std::cin >> email;
    std::cout << "Introduceti parola noua: ";
    std::cin >> parola;

    Utilizator u;
    u.setId(id)
    .setNume(nume)
    .setPrenume(prenume)
    .setVarsta(varsta)
    .setAdresa(adresa)
    .setTelefon(telefon)
    .setEmail(email)
    .setParola(parola);

    if (retea.modificareUtilizator(id, u))
        std::cout << "Utilizatorul a fost modificat cu succes!\n";
    else
        std::cout << "Utilizatorul nu exista!\n";
}

void Interfata::meniu_stergere_utilizatori() {
    int id;

    std::cout << "Introduceti id-ul utilizatorului: ";
    std::cin >> id;

    if (retea.stergereUtilizator(id))
        std::cout << "Utilizatorul a fost sters cu succes!\n";
    else
        std::cout << "Utilizatorul nu exista!\n";
}

void Interfata::meniu_afisare_evenimente() {
    std::vector<Eveniment> evenimente = retea.getEvenimente();

    std::cout << "Evenimente:\n";
    for (Eveniment eveniment : evenimente) {
        std::cout << eveniment.getId() << " " << eveniment.getNume() << " " << eveniment.getLocatie() << " " << eveniment.getData() << " " << eveniment.getOra() << " " << eveniment.getTip() << " " << eveniment.getDescriere() << "\n";
    }
}

void Interfata::meniu_adaugare_evenimente() {
    int id;
    std::string nume, data, locatie, descriere;

    std::cout << "Introduceti id-ul: ";
    std::cin >> id;
    std::cout << "Introduceti numele: ";
    std::cin >> nume;
    std::cout << "Introduceti data: ";
    std::cin >> data;
    std::cout << "Introduceti locatia: ";
    std::cin >> locatie;
    std::cout << "Introduceti descrierea: ";
    std::cin >> descriere;

    Eveniment e;
    e.setId(id)
    .setNume(nume)
    .setData(data)
    .setLocatie(locatie)
    .setDescriere(descriere);

    if (retea.adaugareEveniment(e))
        std::cout << "Evenimentul a fost adaugat cu succes!\n";
    else
        std::cout << "Exista deja un eveniment cu acest id.!\n";
}

void Interfata::meniu_modificare_evenimente() {
    std::string nume, data, locatie, descriere;
    int id;

    std::cout << "Introduceti id-ul evenimentului: ";
    std::cin >> id;

    std::cout << "Introduceti numele nou: ";
    std::cin >> nume;
    std::cout << "Introduceti data noua: ";
    std::cin >> data;
    std::cout << "Introduceti locatia noua: ";
    std::cin >> locatie;
    std::cout << "Introduceti descrierea noua: ";
    std::cin >> descriere;

    Eveniment e;
    e.setId(id)
    .setNume(nume)
    .setData(data)
    .setLocatie(locatie)
    .setDescriere(descriere);

    if (retea.modificareEveniment(id, e))
        std::cout << "Evenimentul a fost modificat cu succes!\n";
    else
        std::cout << "Evenimentul nu exista!\n";
}

void Interfata::meniu_stergere_evenimente() {
    int id;

    std::cout << "Introduceti id-ul evenimentului: ";
    std::cin >> id;

    if (retea.stergereEveniment(id))
        std::cout << "Evenimentul a fost sters cu succes!\n";
    else
        std::cout << "Evenimentul nu exista!\n";
}

void Interfata::meniu_afisare_evenimente_participate() {
    int id_user;

    std::cout << "Introduceti id-ul utilizatorului: ";
    std::cin >> id_user;


    std::vector<Eveniment> evenimente = retea.getEvenimenteParticipate(id_user);

    if (evenimente.size() == 0)
    {
        std::cout << "Acest utilizator nu participa la nici un eveniment!\n";
        return;
    }

    std::cout << "Evenimente Participate:\n";
    for (Eveniment eveniment : evenimente) {
        std::cout << eveniment.getId() << " " << eveniment.getNume() << " " << eveniment.getData() << " " << eveniment.getLocatie() << " " << eveniment.getDescriere() << "\n";
    }
}

void Interfata::meniu_participare_eveniment() {
    int id_user, id_eveniment;

    std::cout << "Introduceti id-ul utilizatorului: ";
    std::cin >> id_user;

    std::cout << "Introduceti id-ul evenimentului: ";
    std::cin >> id_eveniment;

    if (retea.participareEveniment(id_user, id_eveniment))
        std::cout << "Utilizatorul a fost adaugat ca participant la eveniment!\n";
    else
        std::cout << "Utilizatorul nu exista, evenimentul nu exista, sau utilizatorul participa deja la acest eveniment.\n";
}

void Interfata::meniu_anulare_participare() {
    int id_user, id_eveniment;

    std::cout << "Introduceti id-ul utilizatorului: ";
    std::cin >> id_user;

    std::cout << "Introduceti id-ul evenimentului: ";
    std::cin >> id_eveniment;

    if (retea.anulareParticipare(id_user, id_eveniment))
        std::cout << "Participare anulata!\n";
    else
        std::cout << "Utilizatorul nu exista, evenimentul nu exista, sau utilizatorul nu participa la acest eveniment.\n";
}

void Interfata::meniu_afisare_prieteni() {
    int id_user;

    std::cout << "Introduceti id-ul utilizatorului: ";
    std::cin >> id_user;

    std::vector<Utilizator> prieteni = retea.getPrieteni(id_user);

    if (prieteni.size() == 0)
    {
        std::cout << "Acest utilizator nu are prieteni!\n";
        return;
    }

    std::cout << "Prieteni:\n";
    for (Utilizator prieten : prieteni) {
        std::cout << prieten.getId() << " " << prieten.getNume() << " " << prieten.getPrenume() << " " << prieten.getVarsta() << " " << prieten.getAdresa() << " " << prieten.getTelefon() << " " << prieten.getEmail() << " " << prieten.getParola() << "\n";        
    }
}

void Interfata::meniu_adaugare_prieteni() {
    int id_user1;
    int id_user2;

    std::cout << "Introduceti id-ul primului utilizator: ";
    std::cin >> id_user1;

    std::cout << "Introduceti id-ul celui de-al doilea utilizator: ";
    std::cin >> id_user2;

    if (retea.adaugarePrietenie(id_user1, id_user2))
        std::cout << "Prietenia u fost adaugata cu succes!\n";
    else
        std::cout << "Prietenia nu a putut fi adaugata!\n";
}

void Interfata::meniu_stergere_prieteni() {
    int id_user1;
    int id_user2;

    std::cout << "Introduceti id-ul primului utilizator: ";
    std::cin >> id_user1;

    std::cout << "Introduceti id-ul celui de-al doilea utilizator: ";
    std::cin >> id_user2;

    if (retea.stergerePrietenie(id_user1, id_user2))
        std::cout << "Prietenia a fost stearsa cu succes!\n";
    else
        std::cout << "Unul din utilizatori nu exista sau acestia nu sunt prieteni.!\n";
}

void Interfata::meniu_afisare_mesaje() {
    int id_user1;
    int id_user2;

    std::cout << "Introduceti id-ul primului utilizator: ";
    std::cin >> id_user1;

    std::cout << "Introduceti id-ul celui de-al doilea utilizator: ";
    std::cin >> id_user2;

    std::vector<Mesaj> mesaje = retea.getMesaje(id_user1, id_user2);

    if (mesaje.size() == 0)
    {
        std::cout << "Utilizatorii nu exista sau nu exista mesaje intre ei.\n";
        return;
    }

    std::cout << "Mesaje:\n";
    for (Mesaj mesaj : mesaje) {
        Utilizator u1 = retea.getDupaId(mesaj.getIdUser1());
        Utilizator u2 = retea.getDupaId(mesaj.getIdUser2());

        std::cout << "( " << u1.getNume() << " -> " << u2.getNume() << " )" << ": " << mesaj.getContinut() << "\n";
    }
}

void Interfata::meniu_adaugare_mesaje() {
    int id_user1;
    int id_user2;
    std::string continut;

    std::cout << "Introduceti id-ul primului utilizator: ";
    std::cin >> id_user1;

    std::cout << "Introduceti id-ul celui de-al doilea utilizator: ";
    std::cin >> id_user2;

    std::cout << "Introduceti continutul mesajului: ";
    std::cin.ignore();
    std::getline(std::cin, continut);

    if (retea.adaugareMesaj(Mesaj(id_user1, id_user2, continut)))
        std::cout << "Mesajul a fost adaugat cu succes!\n";
    else
        std::cout << "Mesajul nu a putut fi adaugat!\n";
}

