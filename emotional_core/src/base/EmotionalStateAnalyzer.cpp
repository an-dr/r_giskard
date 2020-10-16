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

#include "base/EmotionalStateAnalyzer.hpp"

bool EmotionalStateAnalyzer::CheckState(const EmotionalStateDescriptorStruct_t *emo, CoreState *st) {
    int res;
    ConditionsVector_t::const_iterator conds_it;
    CoreParamsMap_t::const_iterator core_param_it;
    for (conds_it = emo->conditions.begin(); conds_it != emo->conditions.end(); conds_it++) {
        for (core_param_it = st->coreParams.GetParams()->begin();
             core_param_it != st->coreParams.GetParams()->end(); core_param_it++) {
            res = CheckParamVsCondition(core_param_it->first, core_param_it->second, *conds_it);
            if (res == ERROR_FAIL) {
                return false;
            }
        }
    }
    return true;
}

error_t EmotionalStateAnalyzer::CheckParamVsCondition(const string &par_name, const float &par_val, const ConditionStruct_t &cond) {
    if (par_name != cond.param) {
        return ERROR_INVAL;
    }

    if (par_val == cond.value) {
        if ((cond.op == EQUALS) || (cond.op == GREATER_THAN_OR_EQUAL) ||
            (cond.op == LESS_THAN_OR_EQUAL)) {
            return NO_ERROR;
        }
    } else if (par_val < cond.value) {
        if ((cond.op == LESS_THAN) || (cond.op == LESS_THAN_OR_EQUAL)) {
            return NO_ERROR;
        }
    } else {
        if ((cond.op == GREATER_THAN) || (cond.op == GREATER_THAN_OR_EQUAL)) {
            return NO_ERROR;
        }
    }
    return ERROR_FAIL;
}
