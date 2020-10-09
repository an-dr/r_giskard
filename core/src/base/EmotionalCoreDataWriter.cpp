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

#include "base/EmotionalCoreDataWriter.hpp"


const InDataDescriptorStruct_t *EmotionalCoreDataWriter::GetDescriptorForInData(const SensorDataStruct_t &data,
                                                                            const InDataDescriptors *inDataDescriptors) {
    InDataDescriptorsList_t::const_iterator indsc_it;
    for (indsc_it = inDataDescriptors->list().begin(); indsc_it != inDataDescriptors->list().end(); indsc_it++) {
        if (indsc_it->sensor_name == data.sensor_name) {
            return &*indsc_it;
        }
    }
    return nullptr;
}


error_t EmotionalCoreDataWriter::Write(const SensorDataStruct_t &data,
                                       const InDataDescriptors *inDataDescriptors,
                                       CoreState *coreState) {
    float old_s_val = coreState->sensorValues[data.sensor_name];
    float new_s_val = data.value;
    float delta_s_val = new_s_val - old_s_val;
    const InDataDescriptorStruct_t *in_dsc = GetDescriptorForInData(data, inDataDescriptors);
    if(!in_dsc){
        return ERROR_WRONGSTATE;
    }
    for (auto i = in_dsc->weights.begin(); i != in_dsc->weights.end(); i++) {
        float val_delta = i->weight * delta_s_val;
        coreState->coreParams.IncrementParam(i->core_param_name, val_delta);
    }
    coreState->sensorValues[data.sensor_name] = new_s_val;
    return NO_ERROR;
}
