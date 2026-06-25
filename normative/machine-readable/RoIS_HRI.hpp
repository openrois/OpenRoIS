#ifndef _OMG_ROIS_HRI_H_
#define _OMG_ROIS_HRI_H_

/************************************/
/* RoIS_HRI.h (for HRI Engine) */
/************************************/
#include <vector>
#include <string>

namespace RoIS_HRI
{
  enum ReturnCode_t
  {
	OK,
	ERROR,
	BAD_PARAMETER,
	UNSUPPORTED,
	OUT_OF_RESOURCES,
	TIMEOUT
  };
  typedef std::string RoIS_Identifier;
  typedef std::vector<RoIS_Identifier> RoIS_IdentifierList;
  typedef std::string Condition_t;
  typedef std::string HRI_Engine_Profile;
  typedef std::string CommandUnitSequence;
  typedef std::string DateTime;
  typedef long Integer;
  
  struct Result {
	std::string name;
	RoIS_Identifier data_type_ref;
	std::string value;
  };
  struct Parameter {
	std::string name;
	RoIS_Identifier data_type_ref;
	std::string value;
  };
  struct Argument {
	std::string name;
	RoIS_Identifier data_type_ref;
	std::string value;
  };
  typedef std::vector<Result> ResultList;
  typedef std::vector<Parameter> ParameterList;
  typedef std::vector<Argument> ArgumentList;

  /* For System Interface */
  class SystemIF{
  public:
	ReturnCode_t connect();
	ReturnCode_t disconnect();
	ReturnCode_t get_profile(
							 Condition_t condition,
							 HRI_Engine_Profile& profile
							 );
	ReturnCode_t get_error_detail(
								  std::string error_id,
								  Condition_t condition,
								  ResultList& results
								  );
  };
  
  /* For Command Interface */
  class CommandIF{
  public:
	ReturnCode_t search(
						Condition_t condition,
						RoIS_IdentifierList& component_ref_list
						);
	ReturnCode_t bind(
					  RoIS_Identifier component_ref
					  );
	ReturnCode_t bind_any(
						  Condition_t condition,
						  RoIS_Identifier& component_ref
						  );
	ReturnCode_t release(
						 RoIS_Identifier component_ref
						 );
	ReturnCode_t get_parameter(
							   RoIS_Identifier component_ref,
							   ParameterList& parameters
							   );
	ReturnCode_t set_parameter(
							   RoIS_Identifier component_ref,
							   ParameterList parameters,
							   std::string& command_id
							   );
	ReturnCode_t execute(
						 CommandUnitSequence command_unit_list
						 );
	ReturnCode_t get_command_result(
									std::string command_id,
									Condition_t condition,
									ResultList& results
									);
  };
  
  /* For Query Interface */
  class QueryIF{
  public:
	ReturnCode_t query(
					   std::string query_type,
					   Condition_t condition,
					   ResultList& results
					   );
  };
  
  /* For Event Interface */
  class EventIF{
  public:
	ReturnCode_t subscribe(
						   std::string event_type,
						   Condition_t condition,
						   std::string& subscribe_id
						   );
	ReturnCode_t unsubscribe(
							 std::string subscribe_id
							 );
	ReturnCode_t get_event_detail(
								  std::string event_id,
								  Condition_t condition,
								  ResultList& results
								  );
  };
};

/* RLS related element defined here */
/* see also: http://www.omg.org/spec/RLS/20110501/Architecture.hpp */

namespace RoLo
{
  namespace Architecture
  {
    typedef std::string Data;
  };
};

#endif
