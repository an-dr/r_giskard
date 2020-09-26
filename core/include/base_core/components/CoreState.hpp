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

#pragma once

#include <map>
#include <string>
#include "common.h"
#include "CoreParams.hpp"
#include "EmotionalStates.hpp"

using namespace std;

typedef map<string, float> core_params_t;

class CoreState {
private:
    const emotional_state_t *emotional_state;

public:
    CoreParams core_params;

    sensor_values_t sensor_values;

    const emotional_state_t *GetState();

    int SetState(const emotional_state_t *state);

    int SetMixedState();
};
