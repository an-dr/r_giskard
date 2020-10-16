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
#include "base/CoreParams.hpp"
#include "base/EmotionalStateDescriptors.hpp"
#include "base/common_types.h"
#include "error_t.h"

using namespace std;

typedef map<string, float> CoreParamsMap_t;

class CoreState {
private:
    const EmotionalStateDescriptorStruct_t *_emotionalState_p;

public:
    CoreParams coreParams;

    SensorValuesMap_t sensorValues;

    const EmotionalStateDescriptorStruct_t *GetState();

    error_t SetState(const EmotionalStateDescriptorStruct_t *state);

    /**
     * @brief Update parameters of the core state using EmotionalStates and InDataDescriptors objects
     * @param emo_states
     * @param in_data_dsc
     * @return NO_ERROR on success or an error code
     */
    error_t ReloadParams(const EmotionalStateDescriptors *emo_states,
                         const InDataDescriptors *in_data_dsc);
};
