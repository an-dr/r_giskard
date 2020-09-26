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

#include "EmotionalCore.h"
#include "EmotionalCoreDataWriter.hpp"
#include "EmotionalStateAnalyzer.hpp"

int EmotionalCore::SetEmotionalStates(EmotionalStates *e_states) {
    emotionalStates = e_states;
    ReloadParams();
    return OK;
}

int EmotionalCore::SetInDataDescriptors(InDataDescriptors *in_descriptors) {
    inDataDescriptors = in_descriptors;
    ReloadParams();
    return OK;
}

int EmotionalCore::ReloadParams() {
    if ((!emotionalStates) && (!inDataDescriptors)) {
        return ENOENT;
    }
    in_params_t p1;
    in_params_t p2;
    if (emotionalStates) {
        emotionalStates->GetParams(p1);
    }
    if (inDataDescriptors) {
        inDataDescriptors->GetParams(p2);
    }
    p1.insert(p2.begin(), p2.end());
    coreState.core_params.LoadParamsSet(p1);
    return OK;
}

int EmotionalCore::UpdateCurrentEmotionalState() {
    if (!emotionalStates) {
        return ENOENT;
    }
    emotional_states_t::const_iterator e_states_it;
    for (e_states_it = emotionalStates->list().begin(); e_states_it != emotionalStates->list().end(); e_states_it++) {
        if (EmotionalStateAnalyzer::CheckState(&*e_states_it, &coreState)) {
            coreState.SetState(&*e_states_it);
            return OK;
        }
    }
    coreState.SetState(&emotionalStates->mixed_state);
    return ENOENT;
}

int EmotionalCore::WriteData(const sensor_data_t & data) {
    EmotionalCoreDataWriter::WriteData(data, inDataDescriptors, &coreState);
    UpdateCurrentEmotionalState();
    return OK;
}

const emotional_state_t *EmotionalCore::GetState() {
    return coreState.GetState();
}
