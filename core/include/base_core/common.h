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
#include <set>
#include <string>
#include <vector>

using namespace std;

#define OK 0
#define FAIL (-1)


typedef struct {
    string sensor_name;
    float value;
} sensor_data_t;
typedef map<string, float> sensor_values_t;


typedef enum {
    EQUALS = 0x0,
    NOT_EQUALS,
    GREATER_THAN,
    GREATER_THAN_OR_EQUAL,
    LESS_THAN,
    LESS_THAN_OR_EQUAL
} cond_operator_t;

typedef struct {
    string param;
    cond_operator_t op;
    float value;
} condition_t;
typedef vector<condition_t> conditions_t;
