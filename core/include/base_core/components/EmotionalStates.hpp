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

#include <list>
#include <string>
#include "common.h"
#include "InDataDescriptors.hpp"

typedef struct {
    string name;
    conditions_t conditions;
} emotional_state_t;
typedef list<emotional_state_t> emotional_states_t;

class EmotionalStates {
private:
    emotional_states_t states;

public:
    const emotional_state_t mixed_state;

    EmotionalStates();

    int Add(emotional_state_t newState);

    int Remove(string name);

    const emotional_state_t *Get(string name);

    const emotional_states_t &list() const;

    int GetParams(in_params_t &params_holder);

    int size();

    emotional_state_t operator[](int num);
};
