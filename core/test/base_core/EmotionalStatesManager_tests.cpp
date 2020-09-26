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

#include "EmotionalStatesManager_tests.hpp"
#include "EmotionalStates.hpp"
#include "common.h"
#include <stdio.h>

int EmotionalStatesManager_test() {
    emotional_state_t state_panic = {
            .name = "panic",
            .conditions = {
                    {"activity",  GREATER_THAN,       1},
                    {"happiness", LESS_THAN_OR_EQUAL, .5},
            }
    };
    emotional_state_t state_happiness = {
            .name = "happiness",
            .conditions = {
                    {"activity",  LESS_THAN,    .1},
                    {"happiness", GREATER_THAN, .5},
            }
    };

    EmotionalStates es;
    printf("%d\n", es.Add(state_panic));
    printf("%d\n", es.Add(state_happiness));
    printf("%d\n", es.Add(state_panic));

    printf("%d\n", es.Remove("panic"));
    printf("%d\n", es.Remove("panic"));

    const emotional_state_t * h = es.Get("happiness");
    printf("%s\n", h->name.c_str());

    const emotional_state_t * thing = es.Get("non-existing stuff");
    if (!thing){
        printf("Not found\n");
    }

    return 0;
}