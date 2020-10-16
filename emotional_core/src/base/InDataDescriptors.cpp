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

#include "base/InDataDescriptors.hpp"

using namespace std;

error_t InDataDescriptors::Add(const InDataDescriptorStruct_t &newDescriptor) {
    InDataDescriptorsList_t::iterator ind_it;
    for (ind_it = descriptors.begin(); ind_it != descriptors.end(); ind_it++) {
        if (newDescriptor.sensor_name == ind_it->sensor_name) {
            return ERROR_EXIST;// state already exists
        }
    }
    descriptors.push_back(newDescriptor);
    return NO_ERROR;
}

error_t InDataDescriptors::Remove(const string &name) {
    InDataDescriptorsList_t::iterator ind_it;
    for (ind_it = descriptors.begin(); ind_it != descriptors.end(); ind_it++) {
        if (name == ind_it->sensor_name) {
            descriptors.erase(ind_it);
            return NO_ERROR;
        }
    }
    return ERROR_NOTEXIST;// state didn't exists
}

const InDataDescriptorStruct_t *InDataDescriptors::Get(const string &name) {
    InDataDescriptorsList_t::iterator ind_it;
    for (ind_it = descriptors.begin(); ind_it != descriptors.end(); ind_it++) {
        if (name == ind_it->sensor_name) {
            return &*ind_it;
        }
    }
    return nullptr;// state didn't exists
}

const InDataDescriptorsList_t &InDataDescriptors::list() const {
    return descriptors;
}

error_t InDataDescriptors::GetParams(in_params_t &params_holder) const {
    params_holder.clear();
    InDataDescriptorsList_t::const_iterator ind_it;
    for (ind_it = descriptors.begin(); ind_it != descriptors.end(); ind_it++) {
        SensorDataWeightsVector_t::const_iterator ip;
        for (ip = ind_it->weights.begin(); ip != ind_it->weights.end(); ip++) {
            params_holder.insert(ip->core_param_name);
        }
    }
    return NO_ERROR;
}

int InDataDescriptors::size() const {
    return descriptors.size();
}

InDataDescriptorStruct_t InDataDescriptors::operator[](int num) {
    InDataDescriptorsList_t::iterator desc_it;
    desc_it = std::next(descriptors.begin(), num);
    return *desc_it;
}