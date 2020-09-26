// *************************************************************************
//
// Copyright (c) 2020 Andrei Gramakov. All rights reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
// site:    https://agramakov.me
// e-mail:  mail@agramakov.me
//
// *************************************************************************

#include "InDataDescriptor_tests.hpp"
#include <cstdio>
#include "InDataDescriptors.hpp"

int InDataDescriptor_test() {
    in_data_descriptor_t light_sensor = {
            .sensor_name = "photoresistor",
            .val_min = 0,
            .val_max = 255,
            //            .params= {
            //                    {.core_param_name = "activity", .weight = -0.2},
            //                    {.core_param_name = "happiness", .weight = 0.3},
            //            }
    };
    in_data_descriptor_t proximity = {
            .sensor_name = "ultrasound",
            .val_min = 0,
            .val_max = 255,
            //            .params= {
            //                    {.core_param_name = "activity", .weight = -0.7},
            //                    {.core_param_name = "happiness", .weight = -0.3},
            //            }
    };

    InDataDescriptors idd;
    printf("%d\n", idd.Add(light_sensor));
    printf("%d\n", idd.Add(proximity));
    printf("%d\n", idd.Add(light_sensor));

    printf("%d\n", idd.Remove("photoresistor"));
    printf("%d\n", idd.Remove("panic"));

    const in_data_descriptor_t *h = idd.Get("ultrasound");
    printf("%s\n", h->sensor_name.c_str());

    const in_data_descriptor_t *thing = idd.Get("non-existing stuff");
    if (!thing) {
        printf("Not found\n");
    }

    return 0;
}