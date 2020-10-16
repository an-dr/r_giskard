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
#include "base/InDataDescriptors.hpp"
#include "base/common_types.h"
#include "error_t.h"

typedef struct {
    std::string name;
    ConditionsVector_t conditions;
} EmotionalStateDescriptorStruct_t;
typedef std::list<EmotionalStateDescriptorStruct_t> EmotionalStateDescriptorsList_t;

class EmotionalStateDescriptors {
private:
    EmotionalStateDescriptorsList_t states;

public:
    const EmotionalStateDescriptorStruct_t mixed_state;

    EmotionalStateDescriptors();

    error_t Add(EmotionalStateDescriptorStruct_t newState);

    error_t Remove(std::string name);

    const EmotionalStateDescriptorStruct_t *Get(std::string name) const;

    const EmotionalStateDescriptorsList_t &list() const;

    error_t GetParams(in_params_t &params_holder) const;

    int size();

    EmotionalStateDescriptorStruct_t operator[](int num);
};
