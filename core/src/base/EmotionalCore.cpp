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

#include "base/EmotionalCore.h"
#include "base/EmotionalCoreDataWriter.hpp"
#include "base/EmotionalStateAnalyzer.hpp"

error_t EmotionalCore::SetEmotionalStates(EmotionalStates *es_p) {
    emotionalStates_p = es_p;
    RETURN_ON_ERROR(_coreState.ReloadParams(emotionalStates_p, inDataDescriptors_p));
    return NO_ERROR;
}

error_t EmotionalCore::SetInDataDescriptors(InDataDescriptors *ind_p) {
    inDataDescriptors_p = ind_p;
    _coreState.ReloadParams(emotionalStates_p, inDataDescriptors_p);
    return NO_ERROR;
}


error_t EmotionalCore::UpdateCurrentEmotionalState() {
    if (!emotionalStates_p) {
        throw logic_error("EmotionalStates object is not set!");
    }
    EmotionalStatesList_t::const_iterator est_it;
    for (est_it = emotionalStates_p->list().begin(); est_it != emotionalStates_p->list().end(); est_it++) {
        if (EmotionalStateAnalyzer::CheckState(&*est_it, &_coreState)) {
            _coreState.SetState(&*est_it);
            return NO_ERROR;
        }
    }
    _coreState.SetState(&emotionalStates_p->mixed_state);
    return NO_ERROR;
}

error_t EmotionalCore::WriteData(SensorDataStruct_t data) {
    EmotionalCoreDataWriter::Write(data, inDataDescriptors_p, &_coreState);
    RETURN_ON_ERROR(UpdateCurrentEmotionalState());
    return NO_ERROR;
}

const EmotionalStateStruct_t *EmotionalCore::GetState() {
    return _coreState.GetState();
}
