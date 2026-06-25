#ifndef _OMG_ROIS_VIDEO_STREAMING_H_
#define _OMG_ROIS_VIDEO_STREAMING_H_

/**************************************/
/* RoIS_Video_Streaming.h  */
/**************************************/
#include <RoIS_Common.hpp>

namespace Video_Streaming
{
  class Command : public RoIS_Common::Command{
    public:
	  ReturnCode_t set_parameter(
		std::string encoding_parameters,
		std::string transport_parameters
	  );
          ReturnCode_t connect_stream(
	        std::string& stream_id
	  );
          ReturnCode_t disconnect_stream(
	        std::string stream_id
	  );
          ReturnCode_t suspend_stream(
	        std::string stream_id
	  );
          ReturnCode_t resume_stream(
	        std::string stream_id
	  );
  };

  class Query : public RoIS_Common::Query{
    public:
	  ReturnCode_t get_parameter(
		std::string& available_encodings,
		std::string& available_transports,
	  );
	  ReturnCode_t get_stream_status(
		std::string stream_id,
		Stream_Status& status
	  );
  };

  class Event : public RoIS_Common::Event{
    public:
	  void notify_stream_status(
		std::string stream_id,
		DateTime timestamp,
		Stream_Status status
	  );
  };
};

#endif

