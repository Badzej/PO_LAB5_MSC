#pragma once
#include <memory>
#include "..\ObiektSISO.h"
#include <iostream>
#include "ObslugaWejscia.h"
#include "..\RegulatorPID.h"
#include "..\ModelARX.h"
#include "..\Dekoratory\DekoratorSISORownolegly.h"
#include "..\Dekoratory\DekoratorSISOSzeregowy.h"

class KreatorObiektuSISO {
public:
    static std::shared_ptr<ObiektSISO> budujBlokSISO();
    static std::shared_ptr<ObiektSISO> stworzObiektSISO();
    static std::shared_ptr<ObiektSISO> budujLancuchDekoratorow(int typ);
};
