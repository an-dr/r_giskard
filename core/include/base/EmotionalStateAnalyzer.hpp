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

#include "base/CoreState.hpp"
#include "base/EmotionalStates.hpp"
#include "base/common_types.h"

class EmotionalStateAnalyzer {
private:
    EmotionalStateAnalyzer() = default;

public:
    static bool CheckState(const EmotionalStateStruct_t *emo, CoreState *st);

    static error_t CheckParamVsCondition(const string &par_name,
                                         const float &par_val,
                                         const ConditionStruct_t &cond);
};
