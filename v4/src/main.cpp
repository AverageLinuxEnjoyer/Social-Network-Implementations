#include "../include/Tests.h"
#include "../include/Service.h"
#include "../include/Ui.h"

int main() {
    teste();

    UI& ui = UI::get_obiect();

    ui.run();
    
    return 0;
}