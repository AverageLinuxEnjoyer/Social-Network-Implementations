#include "../include/retea.h"
#include "../include/ui.h"

int main() {
    Retea retea(true);
    UserInterface ui(retea);
    ui.run();
    
    return 0;
}