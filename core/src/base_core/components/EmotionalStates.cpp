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
#include <cerrno>
#include "EmotionalStates.hpp"

using namespace std;

int EmotionalStates::Add(emotional_state_t newState) {
    emotional_states_t::iterator i;
    for (i = states.begin(); i != states.end(); i++) {
        if (newState.name == i->name) {
            return EEXIST;// state already exists
        }
    }
    states.push_back(newState);
    return OK;
}

int EmotionalStates::Remove(string name) {
    emotional_states_t::iterator i;
    for (i = states.begin(); i != states.end(); i++) {
        if (name == i->name) {
            states.erase(i);
            return OK;
        }
    }
    return ENOENT;// state didn't exists
}

const emotional_state_t *EmotionalStates::Get(string name) {
    emotional_states_t::iterator i;
    for (i = states.begin(); i != states.end(); i++) {
        if (name == i->name) {
            return &*i;
        }
    }
    return nullptr;// state didn't exists
}

int EmotionalStates::GetParams(in_params_t &params_holder) {
    emotional_states_t::iterator i;
    conditions_t::iterator ic;
    for (i = states.begin(); i != states.end(); i++) {
        for (ic = i->conditions.begin(); ic != i->conditions.end(); ic++) {
            params_holder.insert(ic->param);
        }
    }
    return OK;
}

const emotional_states_t &EmotionalStates::list() const {
    return states;
}

int EmotionalStates::size() {
    return states.size();
}

emotional_state_t EmotionalStates::operator[](int num) {
    emotional_states_t::iterator e_st_it;
    e_st_it = std::next(states.begin(), num);
    return *e_st_it;
}

EmotionalStates::EmotionalStates() : states(), mixed_state({"mixed", {}}) {}
