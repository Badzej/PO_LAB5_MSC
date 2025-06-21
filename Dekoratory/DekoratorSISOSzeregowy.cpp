#include "DekoratorSISOSzeregowy.h"
#include "../FabrykaObiektowSISO.h"
DekoratorSISOSzeregowy::DekoratorSISOSzeregowy(std::shared_ptr<ObiektSISO> pierwszy_,
                   std::shared_ptr<ObiektSISO> drugi_)
    : pierwszy(std::move(pierwszy_)), drugi(std::move(drugi_)) {}

double DekoratorSISOSzeregowy::symuluj(double u){
    double wyjscie1 = pierwszy->symuluj(u);
    return drugi->symuluj(wyjscie1);
}

double DekoratorSISOSzeregowy::pobierzOstatnieWyjscie() {
    return 0;
}

nlohmann::json DekoratorSISOSzeregowy::serializuj() {
    return{
            {"typ", "dekorator_siso_szeregowy"},
            {"pierwszy", pierwszy->serializuj()},
            {"drugi", drugi->serializuj()}
    };
}

DekoratorSISOSzeregowy::DekoratorSISOSzeregowy(nlohmann::json json):
pierwszy(std::move(FabrykaObiektowSISO::stworzZJson(json["pierwszy"]))),
drugi(std::move(FabrykaObiektowSISO::stworzZJson(json["drugi"]))) {}