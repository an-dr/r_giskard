/* Copyright (c) 2020 Andrei Gramakov. All rights reserved.
 *
 * This file is licensed under the terms of the MIT license.
 * For a copy, see: https://opensource.org/licenses/MIT
 *
 * site:    https://agramakov.me
 * e-mail:  mail@agramakov.me
 */

#include "base_components/EmotionalStatesManager_tests.hpp"
#include "base_components/InDataDescriptor_tests.hpp"
#include "base_components/CoreState_tests.hpp"
#include "EmotionalCore_tests.h"

//void sensors(void) {
//    InDataDescriptorStruct_t light_sensor_dsc = {
//            .sensor_name = "photoresistor",
//            .val_min = 0,
//            .val_max = 255,
//            .weights= {
//                    {.core_param_name = "activity", .weight = -0.2},
//                    {.core_param_name = "happiness", .weight = 0.3},
//            }
//    };
//    InDataDescriptorsList_t dscs = {light_sensor_dsc};
//}a


int main() {
//    EmotionalStatesManager_test();
//    InDataDescriptor_test();
//    SystemState_test();
    EmotionalCore_test();
    return 0;
}
