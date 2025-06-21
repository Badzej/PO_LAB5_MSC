
#include "DekoratorSISORownolegly.h"

#include "../FabrykaObiektowSISO.h"

DekoratorSISORownolegly::DekoratorSISORownolegly(std::shared_ptr<ObiektSISO> pierwszy_,
                                                 std::shared_ptr<ObiektSISO> drugi_)
    : pierwszy(std::move(pierwszy_)), drugi(std::move(drugi_)) {
}

double DekoratorSISORownolegly::symuluj(double u) {
    return pierwszy->symuluj(u) + drugi->symuluj(u);
}

double DekoratorSISORownolegly::pobierzOstatnieWyjscie() {
    return 0;
}

nlohmann::json DekoratorSISORownolegly::serializuj() {
    return{
        {"typ", "dekorator_siso_rownolegly"},
        {"pierwszy", pierwszy->serializuj()},
        {"drugi", drugi->serializuj()}
    };
}

DekoratorSISORownolegly::DekoratorSISORownolegly(nlohmann::json json):
    pierwszy(std::move(FabrykaObiektowSISO::stworzZJson(json["pierwszy"]))),
    drugi(std::move(FabrykaObiektowSISO::stworzZJson(json["drugi"]))) {}