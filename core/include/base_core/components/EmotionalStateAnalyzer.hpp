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

#include "common.h"
#include "CoreState.hpp"
#include "EmotionalStates.hpp"

class EmotionalStateAnalyzer {
private:
    EmotionalStateAnalyzer() = default;

public:
    static bool CheckState(const emotional_state_t *emo, CoreState *st);

    static int CheckParamVsCondition(const string &par_name, const float &par_val, const condition_t &cond);
};
