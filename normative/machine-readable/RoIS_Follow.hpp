#ifndef _OMG_ROIS_FOLLOW_H_
#define _OMG_ROIS_FOLLOW_H_

/**********************/
/* RoIS_Follow.h  */
/**********************/
#include <RoIS_Common.hpp>

namespace Follow
{
  class Command : public RoIS_Common::Command{
    public:
      ReturnCode_t set_parameter(
        RoIS_Identifier target_object_ref,
		Integer distance,
		Integer time_limit
	  );
  };

  class Query : public RoIS_Common::Query{
    public:
	  ReturnCode_t get_parameter(
        RoIS_Identifier& target_object_ref,
		Integer& distance,
		Integer& time_limit
	  );
  };

  class Event : public RoIS_Common::Event{
  };
};

#endif
