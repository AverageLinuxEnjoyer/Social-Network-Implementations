#include "../include/tests.h"
#include "../include/service.h"
#include "../include/ui.h"

int main() {
    tests();

    Service service(true);
    UI ui(service);
    ui.run();
    
    return 0;
}