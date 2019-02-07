
#ifndef STATE_CHART_H_
#define STATE_CHART_H_

#include "..\src\sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'state_chart'.
*/


/*! Enumeration of all states */ 
typedef enum
{
	State_chart_last_state,
	State_chart_main_region_Manual_Mode,
	State_chart_main_region_Manual_Mode_manual_region_Off,
	State_chart_main_region_Manual_Mode_manual_region_On,
	State_chart_main_region_Automatic_Mode,
	State_chart_main_region_Automatic_Mode_automatic_region_Off,
	State_chart_main_region_Automatic_Mode_automatic_region_On,
	State_chart_main_region_Automatic_Mode_automatic_region_Dark_Waiting,
	State_chart_main_region_Automatic_Mode_automatic_region_Bright_Waiting
} State_chartStates;

/*! Type definition of the data structure for the State_chartIface interface scope. */
typedef struct
{
	sc_boolean key_on_raised;
	sc_boolean key_off_raised;
	sc_boolean key_mode_raised;
	sc_boolean dark_raised;
	sc_boolean bright_raised;
} State_chartIface;

/*! Type definition of the data structure for the State_chartTimeEvents interface scope. */
typedef struct
{
	sc_boolean state_chart_main_region_Automatic_Mode_automatic_region_Dark_Waiting_tev0_raised;
	sc_boolean state_chart_main_region_Automatic_Mode_automatic_region_Bright_Waiting_tev0_raised;
} State_chartTimeEvents;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define STATE_CHART_MAX_ORTHOGONAL_STATES 1

/*! Define indices of states in the StateConfVector */
#define SCVI_STATE_CHART_MAIN_REGION_MANUAL_MODE 0
#define SCVI_STATE_CHART_MAIN_REGION_MANUAL_MODE_MANUAL_REGION_OFF 0
#define SCVI_STATE_CHART_MAIN_REGION_MANUAL_MODE_MANUAL_REGION_ON 0
#define SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC_MODE 0
#define SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC_MODE_AUTOMATIC_REGION_OFF 0
#define SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC_MODE_AUTOMATIC_REGION_ON 0
#define SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC_MODE_AUTOMATIC_REGION_DARK_WAITING 0
#define SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC_MODE_AUTOMATIC_REGION_BRIGHT_WAITING 0

/*! 
 * Type definition of the data structure for the State_chart state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	State_chartStates stateConfVector[STATE_CHART_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	State_chartIface iface;
	State_chartTimeEvents timeEvents;
} State_chart;


/*! Initializes the State_chart state machine data structures. Must be called before first usage.*/
extern void state_chart_init(State_chart* handle);

/*! Activates the state machine */
extern void state_chart_enter(State_chart* handle);

/*! Deactivates the state machine */
extern void state_chart_exit(State_chart* handle);

/*! Performs a 'run to completion' step. */
extern void state_chart_runCycle(State_chart* handle);

/*! Raises a time event. */
extern void state_chart_raiseTimeEvent(const State_chart* handle, sc_eventid evid);

/*! Raises the in event 'key_on' that is defined in the default interface scope. */ 
extern void state_chartIface_raise_key_on(State_chart* handle);

/*! Raises the in event 'key_off' that is defined in the default interface scope. */ 
extern void state_chartIface_raise_key_off(State_chart* handle);

/*! Raises the in event 'key_mode' that is defined in the default interface scope. */ 
extern void state_chartIface_raise_key_mode(State_chart* handle);

/*! Raises the in event 'dark' that is defined in the default interface scope. */ 
extern void state_chartIface_raise_dark(State_chart* handle);

/*! Raises the in event 'bright' that is defined in the default interface scope. */ 
extern void state_chartIface_raise_bright(State_chart* handle);


/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean state_chart_isActive(const State_chart* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean state_chart_isFinal(const State_chart* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean state_chart_isStateActive(const State_chart* handle, State_chartStates state);



#ifdef __cplusplus
}
#endif 

#endif /* STATE_CHART_H_ */
