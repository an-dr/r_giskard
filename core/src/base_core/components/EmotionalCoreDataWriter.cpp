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

#include "EmotionalCoreDataWriter.hpp"


const in_data_descriptor_t *EmotionalCoreDataWriter::GetDescriptorForInData(const sensor_data_t &data,
                                                                            const InDataDescriptors *inDataDescriptors) {
    in_data_descriptors_t::const_iterator indsc_it;
    for (indsc_it = inDataDescriptors->list().begin(); indsc_it != inDataDescriptors->list().end(); indsc_it++) {
        if (indsc_it->sensor_name == data.sensor_name) {
            const in_data_descriptor_t *d_p = &(*indsc_it);
            return d_p;
        }
    }
    return nullptr;
}


int EmotionalCoreDataWriter::WriteData(const sensor_data_t &data,
                                       const InDataDescriptors *inDataDescriptors,
                                       CoreState *coreState) {
    float old_s_val = coreState->sensor_values[data.sensor_name];
    float new_s_val = data.value;
    float delta_s_val = new_s_val - old_s_val;
    const in_data_descriptor_t *in_dsc = GetDescriptorForInData(data, inDataDescriptors);

    for (auto i = in_dsc->params.begin(); i != in_dsc->params.end(); i++) {
        float val_delta = i->weight * delta_s_val;
        coreState->core_params.IncrementParam(i->core_param_name, val_delta);
    }
    coreState->sensor_values[data.sensor_name] = new_s_val;
    return OK;
}
