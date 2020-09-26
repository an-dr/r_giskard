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
#include <vector>
#include "common.h"
#include "CoreState.hpp"
#include "EmotionalStates.hpp"
#include "InDataDescriptors.hpp"

using namespace std;

class EmotionalCore {
private:
    CoreState coreState;

protected:
    EmotionalStates *emotionalStates = nullptr;
    InDataDescriptors *inDataDescriptors = nullptr;

    int ReloadParams();
    //    int CheckCondition(condition_t cond, emotional_state_t state);
public:
    EmotionalCore() = default;

    //    EmotionalCore(const in_data_descriptors_t &descriptors, const emotional_states_t &states);

    int SetEmotionalStates(EmotionalStates *e_states);

    int SetInDataDescriptors(InDataDescriptors *in_descriptors);

    int UpdateCurrentEmotionalState();

    int WriteData(const sensor_data_t & data);

    const emotional_state_t *GetState();

    //    TODO:
    //    emotional_state_t GetState();
    //    EmotionalCore(vector<emotional_state_t> states);
    //    EmotionalCore(vector<in_data_descriptor_t> descriptors);
    //    int AddEmotionalStates(vector<emotional_state_t> states);
};
