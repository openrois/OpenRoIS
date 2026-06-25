#ifndef _OMG_ROIS_REACTION_H_
#define _OMG_ROIS_REACTION_H_

/*************************/
/* RoIS_Reaction.h  */
/*************************/
#include <RoIS_Common.hpp>

namespace Reaction
{
  class Command : public RoIS_Common::Command{
    public:
	  ReturnCode_t set_parameter(
		RoIS_IdentifierList reaction_ref
	  );
  };

  class Query : public RoIS_Common::Query{
    public:
	  ReturnCode_t get_parameter(
		RoIS_IdentifierList& available_reactions,
		RoIS_Identifier& reaction_ref
	  );
  };

  class Event : public RoIS_Common::Event{
  };
};

#endif
