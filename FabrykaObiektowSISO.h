#pragma once
#include <memory>

#include "include_ext_lib/json.hpp"
#include "ObiektSISO.h"

/**
 * @author Błażej Styrnol
 * @class FabrykaObiektowSISO
 * @brief Klasa fabryki odpowiedzialna za tworzenie obiektów SISO na podstawie danych JSON.
 */
class FabrykaObiektowSISO {
public:
    /**
     * @brief Tworzy obiekt SISO na podstawie danych JSON.
     * @param j Obiekt JSON zawierający konfigurację
     * @return Wskaźnik do utworzonego obiektu SISO
     */
    static std::shared_ptr<ObiektSISO> stworzZJson(const nlohmann::json& j);
};
