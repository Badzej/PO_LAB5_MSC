#pragma once
#include <memory>
#include "..\ObiektSISO.h"
#include <iostream>
#include "ObslugaWejscia.h"
#include "..\RegulatorPID.h"
#include "..\ModelARX.h"
#include "..\Dekoratory\DekoratorSISORownolegly.h"
#include "..\Dekoratory\DekoratorSISOSzeregowy.h"
/**
 * @class KreatorObiektuSISO
 * @brief Kreator obiektów SISO do budowy struktur symulacji
 */
class KreatorObiektuSISO {
public:
    /**
     * @brief Buduje pojedynczy blok lub złożoną strukturę SISO
     * @return Utworzony obiekt SISO
     */
    static std::shared_ptr<ObiektSISO> budujBlokSISO();

    /**
     * @brief Tworzy pojedynczy obiekt SISO (PID lub ARX)
     * @return Utworzony obiekt SISO
     */
    static std::shared_ptr<ObiektSISO> stworzObiektSISO();

    /**
     * @brief Łączy obiekty w strukturę szeregową/równoległą
     * @param typ 2-szeregowa, 3-równoległa
     * @return Złożony obiekt SISO
     */
    static std::shared_ptr<ObiektSISO> budujLancuchDekoratorow(int typ);
};
