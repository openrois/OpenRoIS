#ifndef _OMG_ROIS_SYSTEM_INFORMATION_H_
#define _OMG_ROIS_SYSTEM_INFORMATION_H_

/***********************************/
/* RoIS_System_Information.h */
/***********************************/
#include <RoIS_Common.hpp>
using namespace RoIS_Common;

namespace System_Information {
  class Query {
    public:
      ReturnCode_t robot_position(
        DateTime& timestamp,
        RoIS_IdentifierList& robot_ref,
        std::vector<RoLo::Architecture::Data>& position_data
      );
      ReturnCode_t engine_status(
        Component_Status& status,
        std::vector<DateTime>& operatable_time
      );
  };
};

#endif
