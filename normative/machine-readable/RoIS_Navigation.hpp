#ifndef _OMG_ROIS_NAVIGATION_H_
#define _OMG_ROIS_NAVIGATION_H_

/***************************/
/* RoIS_Navigation.h  */
/***************************/
#include <RoIS_Common.hpp>

namespace Navigation
{
  class Command : public RoIS_Common::Command{
    public:
	  ReturnCode_t set_parameter(
        std::vector<RoLo::Architecture::Data> target_position,
		Integer time_limit,
		std::string routing_policy
      );
  };

  class Query : public RoIS_Common::Query{
    public:
	  ReturnCode_t get_parameter(
        std::vector<RoLo::Architecture::Data>& target_position,
		Integer& time_limit,
		std::string& routing_policy
	  );
  };

  class Event : public RoIS_Common::Event{
  };
};

#endif

