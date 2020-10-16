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

#include <algorithm>
#include "base/EmotionalStateDescriptors.hpp"

using namespace std;

error_t EmotionalStateDescriptors::Add(EmotionalStateDescriptorStruct_t newState) {
    EmotionalStateDescriptorsList_t::iterator st_it;
    for (st_it = states.begin(); st_it != states.end(); st_it++) {
        if (newState.name == st_it->name) {
            return ERROR_EXIST;// state already exists
        }
    }
    states.push_back(newState);
    return NO_ERROR;

}

error_t EmotionalStateDescriptors::Remove(string name) {
    EmotionalStateDescriptorsList_t::iterator st_it;
    for (st_it = states.begin(); st_it != states.end(); st_it++) {
        if (name == st_it->name) {
            states.erase(st_it);
            return NO_ERROR;
        }
    }
    return ERROR_NOTEXIST;// state didn't exists
}

const EmotionalStateDescriptorStruct_t *EmotionalStateDescriptors::Get(string name) const{
    EmotionalStateDescriptorsList_t::const_iterator st_it;
    for (st_it = states.begin(); st_it != states.end(); st_it++) {
        if (name == st_it->name) {
            return &*st_it;
        }
    }
    return nullptr;// state didn't exists
}

error_t EmotionalStateDescriptors::GetParams(in_params_t &params_holder) const{
    EmotionalStateDescriptorsList_t::const_iterator st_it;
    ConditionsVector_t::const_iterator cond_it;
    for (st_it = states.begin(); st_it != states.end(); st_it++) {
        for (cond_it = st_it->conditions.begin(); cond_it != st_it->conditions.end(); cond_it++) {
            params_holder.insert(cond_it->param);
        }
    }
    return NO_ERROR;
}

const EmotionalStateDescriptorsList_t &EmotionalStateDescriptors::list() const {
    return states;
}

int EmotionalStateDescriptors::size() {
    return states.size();
}

EmotionalStateDescriptorStruct_t EmotionalStateDescriptors::operator[](int num) {
    EmotionalStateDescriptorsList_t::iterator e_st_it;
    e_st_it = std::next(states.begin(), num);
    return *e_st_it;
}

EmotionalStateDescriptors::EmotionalStateDescriptors() : states(), mixed_state({"mixed", {}}) {}
