#ifndef _OMG_ROIS_SERVICE_H_
#define _OMG_ROIS_SERVICE_H_

/*************************************************/
/* RoIS_Service.h (for Service Application) */
/*************************************************/
#include <vector>
#include <string>

namespace RoIS_Service
{
  enum Completed_Status
  {
	OK,
	ERROR,
	ABORT,
	OUT_OF_RESOURCES,
	TIMEOUT
  };

  enum ErrorType
  {
	ENGINE_INTERNAL_ERROR,
	COMPONENT_INTERNAL_ERROR,
	COMPONENT_NOT_RESPONDING,
	USER_DEFINED_ERROR
  };

  typedef std::string DateTime;
 
  /* For Service Application Interface */
  class ServiceApplicationBase{
    public:
	  void notify_error(
		std::string error_id,
		ErrorType error_type
	  );
	  void completed(
		std::string command_id,
		Completed_Status status
	  );
	  void notify_event(
		std::string event_id,
		std::string event_type,
		std::string subscribe_id,
		DateTime expire
	  );
  };
};

#endif
