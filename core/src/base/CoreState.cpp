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

#include "base/CoreState.hpp"
#include "base/common_types.h"


error_t CoreState::SetState(const EmotionalStateStruct_t *state) {
    _emotionalState_p = state;
    return NO_ERROR;
}

const EmotionalStateStruct_t *CoreState::GetState() {
    return _emotionalState_p;
}

error_t CoreState::ReloadParams(const EmotionalStates *emo_states,
                            const InDataDescriptors *in_data_dsc) {
    if ((!emo_states) && (!in_data_dsc)) {
        return ERROR_WRONGSTATE;
    }
    in_params_t p1;
    in_params_t p2;
    if (emo_states) {
        emo_states->GetParams(p1);
    }
    if (in_data_dsc) {
        in_data_dsc->GetParams(p2);
    }
    p1.insert(p2.begin(), p2.end());
    RETURN_ON_ERROR(coreParams.LoadParamsSet(p1));
    return NO_ERROR;
}