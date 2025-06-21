#include "FabrykaObiektowSISO.h"
#include <fstream>
#include <memory>
#include "ModelARX.h"
#include "include_ext_lib/json.hpp"
#include "ObiektSISO.h"
#include "RegulatorPID.h"
#include "Dekoratory/DekoratorSISORownolegly.h"
#include "Dekoratory/DekoratorSISOSzeregowy.h"

std::shared_ptr<ObiektSISO> FabrykaObiektowSISO::stworzZJson(const nlohmann::json &j) {
    std::string typ = j["typ"];
    if (typ == "ModelARX") {
        return std::make_shared<ModelARX>(j);
    } else if (typ == "RegulatorPID") {
        return std::make_shared<RegulatorPID>(j);
    } else if (typ == "dekorator_siso_szeregowy") {
        return std::make_shared<DekoratorSISOSzeregowy>(j);
    } else if (typ == "dekorator_siso_rownolegly") {
        return std::make_shared<DekoratorSISORownolegly>(j);
    } else {
        throw std::runtime_error("Nieznany typ sygnału: " + typ);
    }
}


