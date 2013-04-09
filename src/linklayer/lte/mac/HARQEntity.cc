//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "HARQEntity.h"
#include "HARQControlInfo_m.h"
#include "MAC.h"

HARQEntity::HARQEntity() {
    // TODO Auto-generated constructor stub

}

HARQEntity::~HARQEntity() {
    // TODO Auto-generated destructor stub
}

void HARQEntity::init(MAC *module, unsigned nrOfProcs) {
    bcastProc = new HARQProcess(module);

    for (unsigned i = 0; i < nrOfProcs; i++) {
        procs[i] = new HARQProcess(module);
    }
}

void HARQEntity::processUplinkGrant(unsigned ulGrant, unsigned ttiId) {
//    HARQProcess *proc = procs[ttiId % HARQ_MAX_PROCS];
//    if (msg3.size()) {
//        MACProtocolDataUnit *pdu = msg3.back();
//        msg3.pop_back();
//        proc->send(ulGrant, pdu);
//    }
}

void HARQEntity::indicateDownlinkAssignment(TransportBlock *tb) {
    HARQControlInfo *ctrl = check_and_cast<HARQControlInfo*>(tb->getControlInfo());
    EV << "LTE-MAC: Received a downlink assignment.\n";
    if (ctrl->getHarqProcId() == HARQ_BCAST_PROC_ID) {
        EV << "LTE-MAC: Allocating assignment to broadcast HARQ process.\n";
        bcastProc->allocate(tb);
    }
}

