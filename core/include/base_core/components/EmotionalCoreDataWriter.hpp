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

#include "common.h"
#include "CoreState.hpp"
#include "InDataDescriptors.hpp"

class EmotionalCoreDataWriter {
private:
    EmotionalCoreDataWriter() = default;

    static const in_data_descriptor_t *
    GetDescriptorForInData(const sensor_data_t &data, const InDataDescriptors *inDataDescriptors);

public:
    static int WriteData(const sensor_data_t &data, const InDataDescriptors *inDataDescriptors, CoreState *coreState);
};
