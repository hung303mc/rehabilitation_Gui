#include "passivemode.h"
#include <QTimer>

Passive::Passive(){
    Arduino = new Port;
    Arduino->Status =0;
}
