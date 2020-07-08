//
// Copyright (C) 2012-2020 Michele Segata <segata@ccs-labs.org>
//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#pragma once

#include "plexe/scenarios/BaseScenario.h"
#include "plexe/apps/GeneralPlatooningApp.h"
#include "plexe/messages/ManeuverMessage_m.h"

namespace plexe {

class MergeManeuverScenario : public BaseScenario {

protected:
    // message used to start the maneuver
    cMessage* startManeuver;
    // pointer to protocol
    GeneralPlatooningApp* app;

public:
    static const int MANEUVER_TYPE = 12347;

    virtual void initialize(int stage) override;

protected:
    void sendUnicast(cPacket* msg, int destination);

private:
public:
    MergeManeuverScenario()
    {
        startManeuver = nullptr;
        app = nullptr;
    }
    virtual ~MergeManeuverScenario();

protected:
    virtual void handleSelfMsg(cMessage* msg) override;

    void prepareManeuverCars(int platoonLane);
    void setupFormation();
};

} // namespace plexe
