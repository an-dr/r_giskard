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

#include <list>
#include <string>
#include "common.h"

typedef set<string> in_params_t;

typedef struct {
    string core_param_name;
    float weight;
} in_data_param_descriptor_t;

typedef vector<in_data_param_descriptor_t> in_data_param_descriptors_t;

/**
 * The value from the sensor can affect several core parameters at once
 */
typedef struct {
    string sensor_name;
    int val_min;
    int val_max;
    in_data_param_descriptors_t params;
} in_data_descriptor_t;
typedef list<in_data_descriptor_t> in_data_descriptors_t;

class InDataDescriptors {
private:
    in_data_descriptors_t descriptors;

public:
    InDataDescriptors() = default;

    int Add(const in_data_descriptor_t &newDescriptor);

    int Remove(const string &name);

    const in_data_descriptor_t *Get(const string &name);

    const in_data_descriptors_t &list() const;

    int GetParams(in_params_t &params_holder);

    int size() const;

    in_data_descriptor_t operator[](int num);
};
