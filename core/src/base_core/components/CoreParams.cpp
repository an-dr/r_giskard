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

#include "CoreParams.hpp"

bool CoreParams::IsParamExists(string name) {
    if (core_params.find(name) != core_params.end()) {
        return true;
    } else {
        return false;
    }
}

int CoreParams::AddParam(string name) {
    if (IsParamExists(name)) {
        return EEXIST;
    } else {
        core_params[name] = 0;
    }
    return OK;
}

int CoreParams::AddParam(string name, float init_value) {
    if (IsParamExists(name)) {
        return EEXIST;
    } else {
        core_params[name] = init_value;
    }
    return OK;
}

int CoreParams::IncrementParam(string name, float value) {
    core_params[name] += value;
    return OK;
}

int CoreParams::LoadParamsSet(const in_params_t &params_set) {
    in_params_t::const_iterator i;
    for (i = params_set.begin(); i != params_set.end(); i++) {
        AddParam(*i);
    }
    return OK;
}

float CoreParams::GetParam(string name) {
    if (IsParamExists(name)) {
        return core_params[name];
    } else {
        return 0;
    }
}

const core_params_t *CoreParams::GetParams() {
    return &core_params;
}

int CoreParams::RemoveAllParams() {
    core_params.clear();
    return OK;
}

int CoreParams::SetParam(string name, float value) {
    if (IsParamExists(name)) {
        core_params[name] = value;
    } else {
        return ENOENT;
    }
    return OK;
}
