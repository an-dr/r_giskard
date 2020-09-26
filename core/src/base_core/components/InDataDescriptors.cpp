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

#include "InDataDescriptors.hpp"

int InDataDescriptors::Add(const in_data_descriptor_t &newDescriptor) {
    in_data_descriptors_t::iterator i;
    for (i = descriptors.begin(); i != descriptors.end(); i++) {
        if (newDescriptor.sensor_name == i->sensor_name) {
            return EEXIST;// state already exists
        }
    }
    descriptors.push_back(newDescriptor);
    return OK;
}

int InDataDescriptors::Remove(const string &name) {
    in_data_descriptors_t::iterator i;
    for (i = descriptors.begin(); i != descriptors.end(); i++) {
        if (name == i->sensor_name) {
            descriptors.erase(i);
            return OK;
        }
    }
    return ENOENT;// state didn't exists
}

const in_data_descriptor_t *InDataDescriptors::Get(const string &name) {
    in_data_descriptors_t::iterator i;
    for (i = descriptors.begin(); i != descriptors.end(); i++) {
        if (name == i->sensor_name) {
            return &*i;
        }
    }
    return nullptr;// state didn't exists
}

const in_data_descriptors_t &InDataDescriptors::list() const {
    return descriptors;
}

int InDataDescriptors::GetParams(in_params_t &params_holder) {
    params_holder.clear();
    in_data_descriptors_t::iterator i;
    for (i = descriptors.begin(); i != descriptors.end(); i++) {
        in_data_param_descriptors_t::iterator ip;
        for (ip = i->params.begin(); ip != i->params.end(); ip++) {
            params_holder.insert(ip->core_param_name);
        }
    }
    return OK;
}

int InDataDescriptors::size() const {
    return descriptors.size();
}

in_data_descriptor_t InDataDescriptors::operator[](int num) {
    in_data_descriptors_t::iterator desc_it;
    desc_it = std::next(descriptors.begin(), num);
    return *desc_it;
}
