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
#include "base/CoreState.hpp"
#include "base/EmotionalStates.hpp"
#include "base/InDataDescriptors.hpp"
#include "base/common_types.h"
#include "error_t.h"

class EmotionalCore {
private:
    CoreState _coreState;/// @brief stores current core's state

protected:
    EmotionalStates *emotionalStates_p     = nullptr;/// @brief pointer to an object storing possible emotional states
    InDataDescriptors *inDataDescriptors_p = nullptr;/// @brief pointer to an object storing description of input data

public:
    EmotionalCore() = default;

    /**
     * @brief Set the pointer to a EmotionalStates object
     * @param es_p the pointer
     * @return
     */
    error_t SetEmotionalStates(EmotionalStates *es_p);

    /**
     * @brief Set the pointer to a InDataDescriptors object
     * @param ind_p the pointer
     * @return
     */
    error_t SetInDataDescriptors(InDataDescriptors *ind_p);

    /**
     * @brief Set current emotional state based on set EmotionalStates object and current _coreState
     * @return
     */
    error_t UpdateCurrentEmotionalState();

    /**
     * @brief Update current emotional state using set InDataDescriptors and input data
     * @param data sensor name and current value
     * @return
     */
    error_t WriteData(SensorDataStruct_t data);

    /**
     * @brief Get a constant pointer to current emotional state
     * @return pointer to the state
     */
    const EmotionalStateStruct_t *GetState();

    //    TODO:
    //    EmotionalCore(const InDataDescriptorsList_t &descriptors, const EmotionalStatesList_t &states);
    //    EmotionalStateStruct_t GetState();
    //    EmotionalCore(vector<EmotionalStateStruct_t> states);
    //    EmotionalCore(vector<InDataDescriptorStruct_t> descriptors);
    //    int AddEmotionalStates(vector<EmotionalStateStruct_t> states);
};
