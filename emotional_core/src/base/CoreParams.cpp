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

#include "base/CoreParams.hpp"

using namespace std;

bool CoreParams::IsParamExists(const string &name) {
    if (_coreParams.find(name) != _coreParams.end()) {
        return true;
    } else {
        return false;
    }
}

error_t CoreParams::AddParam(const string &name) {
    if (IsParamExists(name)) {
        return ERROR_EXIST;
    } else {
        _coreParams[name] = 0;
    }
    return NO_ERROR;
}

error_t CoreParams::AddParam(const string &name, float init_value) {
    if (IsParamExists(name)) {
        return ERROR_EXIST;
    } else {
        _coreParams[name] = init_value;
    }
    return NO_ERROR;
}

error_t CoreParams::IncrementParam(const string &name, float value) {
    _coreParams[name] += value;
    return NO_ERROR;
}

error_t CoreParams::LoadParamsSet(const in_params_t &params_set) {
    in_params_t::const_iterator i;
    for (i = params_set.begin(); i != params_set.end(); i++) {
        AddParam(*i);
    }
    return NO_ERROR;
}

float CoreParams::GetParam(const string &name) {
    if (IsParamExists(name)) {
        return _coreParams[name];
    } else {
        return 0;
    }
}

const CoreParamsMap_t *CoreParams::GetParams() {
    return &_coreParams;
}

error_t CoreParams::RemoveAllParams() {
    _coreParams.clear();
    return NO_ERROR;
}

error_t CoreParams::SetParam(const string & name, float value) {
    if (IsParamExists(name)) {
        _coreParams[name] = value;
    } else {
        return ERROR_NOTEXIST;
    }
    return NO_ERROR;
}
