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

#include <stdio.h>
#include "simulator.hpp"

int SimApp::Start() {
    printf("I'm started!\n");
    return 0;
}

int SimApp::AddParam(rg_param p) {
    this->params.push_back(p);
    std::vector<rg_param> *ps = &(this->params);
    for (std::vector<rg_param>::iterator i = ps->begin(); i < ps->end(); i++) {
        printf("Param: %s\n", i->c_str());
    }
    return 0;
}