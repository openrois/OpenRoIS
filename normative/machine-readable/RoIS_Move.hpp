#ifndef _OMG_ROIS_MOVE_H_
#define _OMG_ROIS_MOVE_H_

/*********************/
/* RoIS_Move.h  */
/*********************/
#include <RoIS_Common.hpp>

namespace Move
{
  class Command : public RoIS_Common::Command{
    public:
      ReturnCode_t set_parameter(
        std::vector<Integer> line,
        std::vector<Integer> curve,
        Integer time
      );
    };

  class Query : public RoIS_Common::Query{
    public:
      ReturnCode_t get_parameter(
	    std::vector<Integer>& line,
		std::vector<Integer>& curve,
		Integer& time
	  );
  };

  class Event : public RoIS_Common::Event{
  };
};

#endif

