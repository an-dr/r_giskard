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


#include "CoreState_tests.hpp"
#include <stdio.h>
#include "base/CoreState.hpp"

void SystemState_test() {
    CoreState st;
    EmotionalStateDescriptors es;

    EmotionalStateDescriptorStruct_t state_panic = {
            .name = "panic",
            .conditions = {
                    {"activity", GREATER_THAN, 1},
                    {"happiness", LESS_THAN_OR_EQUAL, .5},
            }};
    EmotionalStateDescriptorStruct_t state_happiness = {
            .name = "happiness",
            .conditions = {
                    {"activity", LESS_THAN, .1},
                    {"happiness", GREATER_THAN, .5},
            }};
    es.Add(state_panic);
    es.Add(state_happiness);

    int res;
    res = st.coreParams.AddParam("curiosity");
    printf("%d\n", res);

    res = st.coreParams.AddParam("comfort", 10.1);
    printf("%d\n", res);

    res = st.coreParams.SetParam("not a param", 100);
    printf("%d\n", res);

    res = st.coreParams.SetParam("curiosity", 100.500);
    printf("%d\n", res);


    printf("%f\n", st.coreParams.GetParam("curiosity"));

    res = st.SetState(es.Get("panic"));
    printf("%d\n", res);

    const EmotionalStateDescriptorStruct_t *current_state = st.GetState();
    printf("%s\n", (current_state->name).c_str());
}
