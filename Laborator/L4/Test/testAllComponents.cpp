//
// Created by Luca Tudor on 30.04.2023.
//

#include "testAllComponents.h"

#include "../Entity/test/testEntity.h"
#include "../Date/test/testDate.h"
#include "../Controller/test/testController.h"

void testAllComponents() {
    testEntity();
    testDate();
    testController();
}