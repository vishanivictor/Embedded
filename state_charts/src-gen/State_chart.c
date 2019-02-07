
#include <stdlib.h>
#include <string.h>
#include "..\src\sc_types.h"
#include "State_chart.h"
#include "State_chartRequired.h"
/*! \file Implementation of the state machine 'state_chart'
*/

/* prototypes of all internal functions */
static sc_boolean state_chart_check_main_region_Manual_Mode_tr0_tr0(const State_chart* handle);
static sc_boolean state_chart_check_main_region_Manual_Mode_manual_region_Off_tr0_tr0(const State_chart* handle);
static sc_boolean state_chart_check_main_region_Manual_Mode_manual_region_On_tr0_tr0(const State_chart* handle);
static sc_boolean state_chart_check_main_region_Automatic_Mode_tr0_tr0(const State_chart* handle);
static sc_boolean state_chart_check_main_region_Automatic_Mode_automatic_region_Off_tr0_tr0(const State_chart* handle);
static sc_boolean state_chart_check_main_region_Automatic_Mode_automatic_region_On_tr0_tr0(const State_chart* handle);
static sc_boolean state_chart_check_main_region_Automatic_Mode_automatic_region_Dark_Waiting_tr0_tr0(const State_chart* handle);
static sc_boolean state_chart_check_main_region_Automatic_Mode_automatic_region_Dark_Waiting_tr1_tr1(const State_chart* handle);
static sc_boolean state_chart_check_main_region_Automatic_Mode_automatic_region_Bright_Waiting_tr0_tr0(const State_chart* handle);
static sc_boolean state_chart_check_main_region_Automatic_Mode_automatic_region_Bright_Waiting_tr1_tr1(const State_chart* handle);
static void state_chart_effect_main_region_Manual_Mode_tr0(State_chart* handle);
static void state_chart_effect_main_region_Manual_Mode_manual_region_Off_tr0(State_chart* handle);
static void state_chart_effect_main_region_Manual_Mode_manual_region_On_tr0(State_chart* handle);
static void state_chart_effect_main_region_Automatic_Mode_tr0(State_chart* handle);
static void state_chart_effect_main_region_Automatic_Mode_automatic_region_Off_tr0(State_chart* handle);
static void state_chart_effect_main_region_Automatic_Mode_automatic_region_On_tr0(State_chart* handle);
static void state_chart_effect_main_region_Automatic_Mode_automatic_region_Dark_Waiting_tr0(State_chart* handle);
static void state_chart_effect_main_region_Automatic_Mode_automatic_region_Dark_Waiting_tr1(State_chart* handle);
static void state_chart_effect_main_region_Automatic_Mode_automatic_region_Bright_Waiting_tr0(State_chart* handle);
static void state_chart_effect_main_region_Automatic_Mode_automatic_region_Bright_Waiting_tr1(State_chart* handle);
static void state_chart_enact_main_region_Manual_Mode_manual_region_Off(State_chart* handle);
static void state_chart_enact_main_region_Manual_Mode_manual_region_On(State_chart* handle);
static void state_chart_enact_main_region_Automatic_Mode_automatic_region_Off(State_chart* handle);
static void state_chart_enact_main_region_Automatic_Mode_automatic_region_On(State_chart* handle);
static void state_chart_enact_main_region_Automatic_Mode_automatic_region_Dark_Waiting(State_chart* handle);
static void state_chart_enact_main_region_Automatic_Mode_automatic_region_Bright_Waiting(State_chart* handle);
static void state_chart_exact_main_region_Automatic_Mode_automatic_region_Dark_Waiting(State_chart* handle);
static void state_chart_exact_main_region_Automatic_Mode_automatic_region_Bright_Waiting(State_chart* handle);
static void state_chart_enseq_main_region_Manual_Mode_default(State_chart* handle);
static void state_chart_enseq_main_region_Manual_Mode_manual_region_Off_default(State_chart* handle);
static void state_chart_enseq_main_region_Manual_Mode_manual_region_On_default(State_chart* handle);
static void state_chart_enseq_main_region_Automatic_Mode_default(State_chart* handle);
static void state_chart_enseq_main_region_Automatic_Mode_automatic_region_Off_default(State_chart* handle);
static void state_chart_enseq_main_region_Automatic_Mode_automatic_region_On_default(State_chart* handle);
static void state_chart_enseq_main_region_Automatic_Mode_automatic_region_Dark_Waiting_default(State_chart* handle);
static void state_chart_enseq_main_region_Automatic_Mode_automatic_region_Bright_Waiting_default(State_chart* handle);
static void state_chart_enseq_main_region_default(State_chart* handle);
static void state_chart_enseq_main_region_Manual_Mode_manual_region_default(State_chart* handle);
static void state_chart_enseq_main_region_Automatic_Mode_automatic_region_default(State_chart* handle);
static void state_chart_exseq_main_region_Manual_Mode(State_chart* handle);
static void state_chart_exseq_main_region_Manual_Mode_manual_region_Off(State_chart* handle);
static void state_chart_exseq_main_region_Manual_Mode_manual_region_On(State_chart* handle);
static void state_chart_exseq_main_region_Automatic_Mode(State_chart* handle);
static void state_chart_exseq_main_region_Automatic_Mode_automatic_region_Off(State_chart* handle);
static void state_chart_exseq_main_region_Automatic_Mode_automatic_region_On(State_chart* handle);
static void state_chart_exseq_main_region_Automatic_Mode_automatic_region_Dark_Waiting(State_chart* handle);
static void state_chart_exseq_main_region_Automatic_Mode_automatic_region_Bright_Waiting(State_chart* handle);
static void state_chart_exseq_main_region(State_chart* handle);
static void state_chart_exseq_main_region_Manual_Mode_manual_region(State_chart* handle);
static void state_chart_exseq_main_region_Automatic_Mode_automatic_region(State_chart* handle);
static void state_chart_react_main_region_Manual_Mode_manual_region_Off(State_chart* handle);
static void state_chart_react_main_region_Manual_Mode_manual_region_On(State_chart* handle);
static void state_chart_react_main_region_Automatic_Mode_automatic_region_Off(State_chart* handle);
static void state_chart_react_main_region_Automatic_Mode_automatic_region_On(State_chart* handle);
static void state_chart_react_main_region_Automatic_Mode_automatic_region_Dark_Waiting(State_chart* handle);
static void state_chart_react_main_region_Automatic_Mode_automatic_region_Bright_Waiting(State_chart* handle);
static void state_chart_react_main_region_Manual_Mode_manual_region__entry_Default(State_chart* handle);
static void state_chart_react_main_region_Automatic_Mode_automatic_region__entry_Default(State_chart* handle);
static void state_chart_react_main_region__entry_Default(State_chart* handle);
static void state_chart_clearInEvents(State_chart* handle);
static void state_chart_clearOutEvents(State_chart* handle);


void state_chart_init(State_chart* handle)
{
		sc_integer i;
	
		for (i = 0; i < STATE_CHART_MAX_ORTHOGONAL_STATES; ++i)
		{
			handle->stateConfVector[i] = State_chart_last_state;
		}
		
		
		handle->stateConfVectorPosition = 0;
	
		state_chart_clearInEvents(handle);
		state_chart_clearOutEvents(handle);
	
}

void state_chart_enter(State_chart* handle)
{
	/* Default enter sequence for statechart state_chart */
	state_chart_enseq_main_region_default(handle);
}

void state_chart_exit(State_chart* handle)
{
	/* Default exit sequence for statechart state_chart */
	state_chart_exseq_main_region(handle);
}

sc_boolean state_chart_isActive(const State_chart* handle)
{
	sc_boolean result = bool_false;
	int i;
	
	for(i = 0; i < STATE_CHART_MAX_ORTHOGONAL_STATES; i++)
	{
		result = result || handle->stateConfVector[i] != State_chart_last_state;
	}
	
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean state_chart_isFinal(const State_chart* handle)
{
   return bool_false;
}

static void state_chart_clearInEvents(State_chart* handle)
{
	handle->iface.key_on_raised = bool_false;
	handle->iface.key_off_raised = bool_false;
	handle->iface.key_mode_raised = bool_false;
	handle->iface.dark_raised = bool_false;
	handle->iface.bright_raised = bool_false;
	handle->timeEvents.state_chart_main_region_Automatic_Mode_automatic_region_Dark_Waiting_tev0_raised = bool_false;
	handle->timeEvents.state_chart_main_region_Automatic_Mode_automatic_region_Bright_Waiting_tev0_raised = bool_false;
}

static void state_chart_clearOutEvents(State_chart* handle)
{
}

void state_chart_runCycle(State_chart* handle)
{
	
	state_chart_clearOutEvents(handle);
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < STATE_CHART_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case State_chart_main_region_Manual_Mode_manual_region_Off:
		{
			state_chart_react_main_region_Manual_Mode_manual_region_Off(handle);
			break;
		}
		case State_chart_main_region_Manual_Mode_manual_region_On:
		{
			state_chart_react_main_region_Manual_Mode_manual_region_On(handle);
			break;
		}
		case State_chart_main_region_Automatic_Mode_automatic_region_Off:
		{
			state_chart_react_main_region_Automatic_Mode_automatic_region_Off(handle);
			break;
		}
		case State_chart_main_region_Automatic_Mode_automatic_region_On:
		{
			state_chart_react_main_region_Automatic_Mode_automatic_region_On(handle);
			break;
		}
		case State_chart_main_region_Automatic_Mode_automatic_region_Dark_Waiting:
		{
			state_chart_react_main_region_Automatic_Mode_automatic_region_Dark_Waiting(handle);
			break;
		}
		case State_chart_main_region_Automatic_Mode_automatic_region_Bright_Waiting:
		{
			state_chart_react_main_region_Automatic_Mode_automatic_region_Bright_Waiting(handle);
			break;
		}
		default:
			break;
		}
	}
	
	state_chart_clearInEvents(handle);
}

void state_chart_raiseTimeEvent(const State_chart* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(State_chartTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean state_chart_isStateActive(const State_chart* handle, State_chartStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case State_chart_main_region_Manual_Mode :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_MANUAL_MODE] >= State_chart_main_region_Manual_Mode
				&& handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_MANUAL_MODE] <= State_chart_main_region_Manual_Mode_manual_region_On);
			break;
		case State_chart_main_region_Manual_Mode_manual_region_Off :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_MANUAL_MODE_MANUAL_REGION_OFF] == State_chart_main_region_Manual_Mode_manual_region_Off
			);
			break;
		case State_chart_main_region_Manual_Mode_manual_region_On :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_MANUAL_MODE_MANUAL_REGION_ON] == State_chart_main_region_Manual_Mode_manual_region_On
			);
			break;
		case State_chart_main_region_Automatic_Mode :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC_MODE] >= State_chart_main_region_Automatic_Mode
				&& handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC_MODE] <= State_chart_main_region_Automatic_Mode_automatic_region_Bright_Waiting);
			break;
		case State_chart_main_region_Automatic_Mode_automatic_region_Off :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC_MODE_AUTOMATIC_REGION_OFF] == State_chart_main_region_Automatic_Mode_automatic_region_Off
			);
			break;
		case State_chart_main_region_Automatic_Mode_automatic_region_On :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC_MODE_AUTOMATIC_REGION_ON] == State_chart_main_region_Automatic_Mode_automatic_region_On
			);
			break;
		case State_chart_main_region_Automatic_Mode_automatic_region_Dark_Waiting :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC_MODE_AUTOMATIC_REGION_DARK_WAITING] == State_chart_main_region_Automatic_Mode_automatic_region_Dark_Waiting
			);
			break;
		case State_chart_main_region_Automatic_Mode_automatic_region_Bright_Waiting :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC_MODE_AUTOMATIC_REGION_BRIGHT_WAITING] == State_chart_main_region_Automatic_Mode_automatic_region_Bright_Waiting
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

void state_chartIface_raise_key_on(State_chart* handle)
{
	handle->iface.key_on_raised = bool_true;
}
void state_chartIface_raise_key_off(State_chart* handle)
{
	handle->iface.key_off_raised = bool_true;
}
void state_chartIface_raise_key_mode(State_chart* handle)
{
	handle->iface.key_mode_raised = bool_true;
}
void state_chartIface_raise_dark(State_chart* handle)
{
	handle->iface.dark_raised = bool_true;
}
void state_chartIface_raise_bright(State_chart* handle)
{
	handle->iface.bright_raised = bool_true;
}



/* implementations of all internal functions */

static sc_boolean state_chart_check_main_region_Manual_Mode_tr0_tr0(const State_chart* handle)
{
	return handle->iface.key_mode_raised;
}

static sc_boolean state_chart_check_main_region_Manual_Mode_manual_region_Off_tr0_tr0(const State_chart* handle)
{
	return handle->iface.key_on_raised;
}

static sc_boolean state_chart_check_main_region_Manual_Mode_manual_region_On_tr0_tr0(const State_chart* handle)
{
	return handle->iface.key_off_raised;
}

static sc_boolean state_chart_check_main_region_Automatic_Mode_tr0_tr0(const State_chart* handle)
{
	return handle->iface.key_mode_raised;
}

static sc_boolean state_chart_check_main_region_Automatic_Mode_automatic_region_Off_tr0_tr0(const State_chart* handle)
{
	return handle->iface.dark_raised;
}

static sc_boolean state_chart_check_main_region_Automatic_Mode_automatic_region_On_tr0_tr0(const State_chart* handle)
{
	return handle->iface.bright_raised;
}

static sc_boolean state_chart_check_main_region_Automatic_Mode_automatic_region_Dark_Waiting_tr0_tr0(const State_chart* handle)
{
	return handle->timeEvents.state_chart_main_region_Automatic_Mode_automatic_region_Dark_Waiting_tev0_raised;
}

static sc_boolean state_chart_check_main_region_Automatic_Mode_automatic_region_Dark_Waiting_tr1_tr1(const State_chart* handle)
{
	return handle->iface.bright_raised;
}

static sc_boolean state_chart_check_main_region_Automatic_Mode_automatic_region_Bright_Waiting_tr0_tr0(const State_chart* handle)
{
	return handle->iface.dark_raised;
}

static sc_boolean state_chart_check_main_region_Automatic_Mode_automatic_region_Bright_Waiting_tr1_tr1(const State_chart* handle)
{
	return handle->timeEvents.state_chart_main_region_Automatic_Mode_automatic_region_Bright_Waiting_tev0_raised;
}

static void state_chart_effect_main_region_Manual_Mode_tr0(State_chart* handle)
{
	state_chart_exseq_main_region_Manual_Mode(handle);
	state_chart_enseq_main_region_Automatic_Mode_default(handle);
}

static void state_chart_effect_main_region_Manual_Mode_manual_region_Off_tr0(State_chart* handle)
{
	state_chart_exseq_main_region_Manual_Mode_manual_region_Off(handle);
	state_chart_enseq_main_region_Manual_Mode_manual_region_On_default(handle);
}

static void state_chart_effect_main_region_Manual_Mode_manual_region_On_tr0(State_chart* handle)
{
	state_chart_exseq_main_region_Manual_Mode_manual_region_On(handle);
	state_chart_enseq_main_region_Manual_Mode_manual_region_Off_default(handle);
}

static void state_chart_effect_main_region_Automatic_Mode_tr0(State_chart* handle)
{
	state_chart_exseq_main_region_Automatic_Mode(handle);
	state_chart_enseq_main_region_Manual_Mode_default(handle);
}

static void state_chart_effect_main_region_Automatic_Mode_automatic_region_Off_tr0(State_chart* handle)
{
	state_chart_exseq_main_region_Automatic_Mode_automatic_region_Off(handle);
	state_chart_enseq_main_region_Automatic_Mode_automatic_region_Dark_Waiting_default(handle);
}

static void state_chart_effect_main_region_Automatic_Mode_automatic_region_On_tr0(State_chart* handle)
{
	state_chart_exseq_main_region_Automatic_Mode_automatic_region_On(handle);
	state_chart_enseq_main_region_Automatic_Mode_automatic_region_Bright_Waiting_default(handle);
}

static void state_chart_effect_main_region_Automatic_Mode_automatic_region_Dark_Waiting_tr0(State_chart* handle)
{
	state_chart_exseq_main_region_Automatic_Mode_automatic_region_Dark_Waiting(handle);
	state_chart_enseq_main_region_Automatic_Mode_automatic_region_On_default(handle);
}

static void state_chart_effect_main_region_Automatic_Mode_automatic_region_Dark_Waiting_tr1(State_chart* handle)
{
	state_chart_exseq_main_region_Automatic_Mode_automatic_region_Dark_Waiting(handle);
	state_chart_enseq_main_region_Automatic_Mode_automatic_region_Off_default(handle);
}

static void state_chart_effect_main_region_Automatic_Mode_automatic_region_Bright_Waiting_tr0(State_chart* handle)
{
	state_chart_exseq_main_region_Automatic_Mode_automatic_region_Bright_Waiting(handle);
	state_chart_enseq_main_region_Automatic_Mode_automatic_region_On_default(handle);
}

static void state_chart_effect_main_region_Automatic_Mode_automatic_region_Bright_Waiting_tr1(State_chart* handle)
{
	state_chart_exseq_main_region_Automatic_Mode_automatic_region_Bright_Waiting(handle);
	state_chart_enseq_main_region_Automatic_Mode_automatic_region_Off_default(handle);
}

/* Entry action for state 'Off'. */
static void state_chart_enact_main_region_Manual_Mode_manual_region_Off(State_chart* handle)
{
	/* Entry action for state 'Off'. */
	state_chartIface_setLight(handle, bool_false);
}

/* Entry action for state 'On'. */
static void state_chart_enact_main_region_Manual_Mode_manual_region_On(State_chart* handle)
{
	/* Entry action for state 'On'. */
	state_chartIface_setLight(handle, bool_true);
}

/* Entry action for state 'Off'. */
static void state_chart_enact_main_region_Automatic_Mode_automatic_region_Off(State_chart* handle)
{
	/* Entry action for state 'Off'. */
	state_chartIface_setLight(handle, bool_false);
}

/* Entry action for state 'On'. */
static void state_chart_enact_main_region_Automatic_Mode_automatic_region_On(State_chart* handle)
{
	/* Entry action for state 'On'. */
	state_chartIface_setLight(handle, bool_true);
}

/* Entry action for state 'Dark Waiting'. */
static void state_chart_enact_main_region_Automatic_Mode_automatic_region_Dark_Waiting(State_chart* handle)
{
	/* Entry action for state 'Dark Waiting'. */
	state_chart_setTimer(handle, (sc_eventid) &(handle->timeEvents.state_chart_main_region_Automatic_Mode_automatic_region_Dark_Waiting_tev0_raised) , 1 * 1000, bool_false);
}

/* Entry action for state 'Bright Waiting'. */
static void state_chart_enact_main_region_Automatic_Mode_automatic_region_Bright_Waiting(State_chart* handle)
{
	/* Entry action for state 'Bright Waiting'. */
	state_chart_setTimer(handle, (sc_eventid) &(handle->timeEvents.state_chart_main_region_Automatic_Mode_automatic_region_Bright_Waiting_tev0_raised) , 1 * 1000, bool_false);
}

/* Exit action for state 'Dark Waiting'. */
static void state_chart_exact_main_region_Automatic_Mode_automatic_region_Dark_Waiting(State_chart* handle)
{
	/* Exit action for state 'Dark Waiting'. */
	state_chart_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.state_chart_main_region_Automatic_Mode_automatic_region_Dark_Waiting_tev0_raised) );		
}

/* Exit action for state 'Bright Waiting'. */
static void state_chart_exact_main_region_Automatic_Mode_automatic_region_Bright_Waiting(State_chart* handle)
{
	/* Exit action for state 'Bright Waiting'. */
	state_chart_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.state_chart_main_region_Automatic_Mode_automatic_region_Bright_Waiting_tev0_raised) );		
}

/* 'default' enter sequence for state Manual Mode */
static void state_chart_enseq_main_region_Manual_Mode_default(State_chart* handle)
{
	/* 'default' enter sequence for state Manual Mode */
	state_chart_enseq_main_region_Manual_Mode_manual_region_default(handle);
}

/* 'default' enter sequence for state Off */
static void state_chart_enseq_main_region_Manual_Mode_manual_region_Off_default(State_chart* handle)
{
	/* 'default' enter sequence for state Off */
	state_chart_enact_main_region_Manual_Mode_manual_region_Off(handle);
	handle->stateConfVector[0] = State_chart_main_region_Manual_Mode_manual_region_Off;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state On */
static void state_chart_enseq_main_region_Manual_Mode_manual_region_On_default(State_chart* handle)
{
	/* 'default' enter sequence for state On */
	state_chart_enact_main_region_Manual_Mode_manual_region_On(handle);
	handle->stateConfVector[0] = State_chart_main_region_Manual_Mode_manual_region_On;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Automatic Mode */
static void state_chart_enseq_main_region_Automatic_Mode_default(State_chart* handle)
{
	/* 'default' enter sequence for state Automatic Mode */
	state_chart_enseq_main_region_Automatic_Mode_automatic_region_default(handle);
}

/* 'default' enter sequence for state Off */
static void state_chart_enseq_main_region_Automatic_Mode_automatic_region_Off_default(State_chart* handle)
{
	/* 'default' enter sequence for state Off */
	state_chart_enact_main_region_Automatic_Mode_automatic_region_Off(handle);
	handle->stateConfVector[0] = State_chart_main_region_Automatic_Mode_automatic_region_Off;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state On */
static void state_chart_enseq_main_region_Automatic_Mode_automatic_region_On_default(State_chart* handle)
{
	/* 'default' enter sequence for state On */
	state_chart_enact_main_region_Automatic_Mode_automatic_region_On(handle);
	handle->stateConfVector[0] = State_chart_main_region_Automatic_Mode_automatic_region_On;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Dark Waiting */
static void state_chart_enseq_main_region_Automatic_Mode_automatic_region_Dark_Waiting_default(State_chart* handle)
{
	/* 'default' enter sequence for state Dark Waiting */
	state_chart_enact_main_region_Automatic_Mode_automatic_region_Dark_Waiting(handle);
	handle->stateConfVector[0] = State_chart_main_region_Automatic_Mode_automatic_region_Dark_Waiting;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Bright Waiting */
static void state_chart_enseq_main_region_Automatic_Mode_automatic_region_Bright_Waiting_default(State_chart* handle)
{
	/* 'default' enter sequence for state Bright Waiting */
	state_chart_enact_main_region_Automatic_Mode_automatic_region_Bright_Waiting(handle);
	handle->stateConfVector[0] = State_chart_main_region_Automatic_Mode_automatic_region_Bright_Waiting;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region main region */
static void state_chart_enseq_main_region_default(State_chart* handle)
{
	/* 'default' enter sequence for region main region */
	state_chart_react_main_region__entry_Default(handle);
}

/* 'default' enter sequence for region manual region */
static void state_chart_enseq_main_region_Manual_Mode_manual_region_default(State_chart* handle)
{
	/* 'default' enter sequence for region manual region */
	state_chart_react_main_region_Manual_Mode_manual_region__entry_Default(handle);
}

/* 'default' enter sequence for region automatic region */
static void state_chart_enseq_main_region_Automatic_Mode_automatic_region_default(State_chart* handle)
{
	/* 'default' enter sequence for region automatic region */
	state_chart_react_main_region_Automatic_Mode_automatic_region__entry_Default(handle);
}

/* Default exit sequence for state Manual Mode */
static void state_chart_exseq_main_region_Manual_Mode(State_chart* handle)
{
	/* Default exit sequence for state Manual Mode */
	state_chart_exseq_main_region_Manual_Mode_manual_region(handle);
}

/* Default exit sequence for state Off */
static void state_chart_exseq_main_region_Manual_Mode_manual_region_Off(State_chart* handle)
{
	/* Default exit sequence for state Off */
	handle->stateConfVector[0] = State_chart_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state On */
static void state_chart_exseq_main_region_Manual_Mode_manual_region_On(State_chart* handle)
{
	/* Default exit sequence for state On */
	handle->stateConfVector[0] = State_chart_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Automatic Mode */
static void state_chart_exseq_main_region_Automatic_Mode(State_chart* handle)
{
	/* Default exit sequence for state Automatic Mode */
	state_chart_exseq_main_region_Automatic_Mode_automatic_region(handle);
}

/* Default exit sequence for state Off */
static void state_chart_exseq_main_region_Automatic_Mode_automatic_region_Off(State_chart* handle)
{
	/* Default exit sequence for state Off */
	handle->stateConfVector[0] = State_chart_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state On */
static void state_chart_exseq_main_region_Automatic_Mode_automatic_region_On(State_chart* handle)
{
	/* Default exit sequence for state On */
	handle->stateConfVector[0] = State_chart_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Dark Waiting */
static void state_chart_exseq_main_region_Automatic_Mode_automatic_region_Dark_Waiting(State_chart* handle)
{
	/* Default exit sequence for state Dark Waiting */
	handle->stateConfVector[0] = State_chart_last_state;
	handle->stateConfVectorPosition = 0;
	state_chart_exact_main_region_Automatic_Mode_automatic_region_Dark_Waiting(handle);
}

/* Default exit sequence for state Bright Waiting */
static void state_chart_exseq_main_region_Automatic_Mode_automatic_region_Bright_Waiting(State_chart* handle)
{
	/* Default exit sequence for state Bright Waiting */
	handle->stateConfVector[0] = State_chart_last_state;
	handle->stateConfVectorPosition = 0;
	state_chart_exact_main_region_Automatic_Mode_automatic_region_Bright_Waiting(handle);
}

/* Default exit sequence for region main region */
static void state_chart_exseq_main_region(State_chart* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of state_chart.main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case State_chart_main_region_Manual_Mode_manual_region_Off :
		{
			state_chart_exseq_main_region_Manual_Mode_manual_region_Off(handle);
			break;
		}
		case State_chart_main_region_Manual_Mode_manual_region_On :
		{
			state_chart_exseq_main_region_Manual_Mode_manual_region_On(handle);
			break;
		}
		case State_chart_main_region_Automatic_Mode_automatic_region_Off :
		{
			state_chart_exseq_main_region_Automatic_Mode_automatic_region_Off(handle);
			break;
		}
		case State_chart_main_region_Automatic_Mode_automatic_region_On :
		{
			state_chart_exseq_main_region_Automatic_Mode_automatic_region_On(handle);
			break;
		}
		case State_chart_main_region_Automatic_Mode_automatic_region_Dark_Waiting :
		{
			state_chart_exseq_main_region_Automatic_Mode_automatic_region_Dark_Waiting(handle);
			break;
		}
		case State_chart_main_region_Automatic_Mode_automatic_region_Bright_Waiting :
		{
			state_chart_exseq_main_region_Automatic_Mode_automatic_region_Bright_Waiting(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region manual region */
static void state_chart_exseq_main_region_Manual_Mode_manual_region(State_chart* handle)
{
	/* Default exit sequence for region manual region */
	/* Handle exit of all possible states (of state_chart.main_region.Manual_Mode.manual_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case State_chart_main_region_Manual_Mode_manual_region_Off :
		{
			state_chart_exseq_main_region_Manual_Mode_manual_region_Off(handle);
			break;
		}
		case State_chart_main_region_Manual_Mode_manual_region_On :
		{
			state_chart_exseq_main_region_Manual_Mode_manual_region_On(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region automatic region */
static void state_chart_exseq_main_region_Automatic_Mode_automatic_region(State_chart* handle)
{
	/* Default exit sequence for region automatic region */
	/* Handle exit of all possible states (of state_chart.main_region.Automatic_Mode.automatic_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case State_chart_main_region_Automatic_Mode_automatic_region_Off :
		{
			state_chart_exseq_main_region_Automatic_Mode_automatic_region_Off(handle);
			break;
		}
		case State_chart_main_region_Automatic_Mode_automatic_region_On :
		{
			state_chart_exseq_main_region_Automatic_Mode_automatic_region_On(handle);
			break;
		}
		case State_chart_main_region_Automatic_Mode_automatic_region_Dark_Waiting :
		{
			state_chart_exseq_main_region_Automatic_Mode_automatic_region_Dark_Waiting(handle);
			break;
		}
		case State_chart_main_region_Automatic_Mode_automatic_region_Bright_Waiting :
		{
			state_chart_exseq_main_region_Automatic_Mode_automatic_region_Bright_Waiting(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state Off. */
static void state_chart_react_main_region_Manual_Mode_manual_region_Off(State_chart* handle)
{
	/* The reactions of state Off. */
	if (state_chart_check_main_region_Manual_Mode_tr0_tr0(handle) == bool_true)
	{ 
		state_chart_effect_main_region_Manual_Mode_tr0(handle);
	}  else
	{
		if (state_chart_check_main_region_Manual_Mode_manual_region_Off_tr0_tr0(handle) == bool_true)
		{ 
			state_chart_effect_main_region_Manual_Mode_manual_region_Off_tr0(handle);
		} 
	}
}

/* The reactions of state On. */
static void state_chart_react_main_region_Manual_Mode_manual_region_On(State_chart* handle)
{
	/* The reactions of state On. */
	if (state_chart_check_main_region_Manual_Mode_tr0_tr0(handle) == bool_true)
	{ 
		state_chart_effect_main_region_Manual_Mode_tr0(handle);
	}  else
	{
		if (state_chart_check_main_region_Manual_Mode_manual_region_On_tr0_tr0(handle) == bool_true)
		{ 
			state_chart_effect_main_region_Manual_Mode_manual_region_On_tr0(handle);
		} 
	}
}

/* The reactions of state Off. */
static void state_chart_react_main_region_Automatic_Mode_automatic_region_Off(State_chart* handle)
{
	/* The reactions of state Off. */
	if (state_chart_check_main_region_Automatic_Mode_tr0_tr0(handle) == bool_true)
	{ 
		state_chart_effect_main_region_Automatic_Mode_tr0(handle);
	}  else
	{
		if (state_chart_check_main_region_Automatic_Mode_automatic_region_Off_tr0_tr0(handle) == bool_true)
		{ 
			state_chart_effect_main_region_Automatic_Mode_automatic_region_Off_tr0(handle);
		} 
	}
}

/* The reactions of state On. */
static void state_chart_react_main_region_Automatic_Mode_automatic_region_On(State_chart* handle)
{
	/* The reactions of state On. */
	if (state_chart_check_main_region_Automatic_Mode_tr0_tr0(handle) == bool_true)
	{ 
		state_chart_effect_main_region_Automatic_Mode_tr0(handle);
	}  else
	{
		if (state_chart_check_main_region_Automatic_Mode_automatic_region_On_tr0_tr0(handle) == bool_true)
		{ 
			state_chart_effect_main_region_Automatic_Mode_automatic_region_On_tr0(handle);
		} 
	}
}

/* The reactions of state Dark Waiting. */
static void state_chart_react_main_region_Automatic_Mode_automatic_region_Dark_Waiting(State_chart* handle)
{
	/* The reactions of state Dark Waiting. */
	if (state_chart_check_main_region_Automatic_Mode_tr0_tr0(handle) == bool_true)
	{ 
		state_chart_effect_main_region_Automatic_Mode_tr0(handle);
	}  else
	{
		if (state_chart_check_main_region_Automatic_Mode_automatic_region_Dark_Waiting_tr0_tr0(handle) == bool_true)
		{ 
			state_chart_effect_main_region_Automatic_Mode_automatic_region_Dark_Waiting_tr0(handle);
		}  else
		{
			if (state_chart_check_main_region_Automatic_Mode_automatic_region_Dark_Waiting_tr1_tr1(handle) == bool_true)
			{ 
				state_chart_effect_main_region_Automatic_Mode_automatic_region_Dark_Waiting_tr1(handle);
			} 
		}
	}
}

/* The reactions of state Bright Waiting. */
static void state_chart_react_main_region_Automatic_Mode_automatic_region_Bright_Waiting(State_chart* handle)
{
	/* The reactions of state Bright Waiting. */
	if (state_chart_check_main_region_Automatic_Mode_tr0_tr0(handle) == bool_true)
	{ 
		state_chart_effect_main_region_Automatic_Mode_tr0(handle);
	}  else
	{
		if (state_chart_check_main_region_Automatic_Mode_automatic_region_Bright_Waiting_tr0_tr0(handle) == bool_true)
		{ 
			state_chart_effect_main_region_Automatic_Mode_automatic_region_Bright_Waiting_tr0(handle);
		}  else
		{
			if (state_chart_check_main_region_Automatic_Mode_automatic_region_Bright_Waiting_tr1_tr1(handle) == bool_true)
			{ 
				state_chart_effect_main_region_Automatic_Mode_automatic_region_Bright_Waiting_tr1(handle);
			} 
		}
	}
}

/* Default react sequence for initial entry  */
static void state_chart_react_main_region_Manual_Mode_manual_region__entry_Default(State_chart* handle)
{
	/* Default react sequence for initial entry  */
	state_chart_enseq_main_region_Manual_Mode_manual_region_Off_default(handle);
}

/* Default react sequence for initial entry  */
static void state_chart_react_main_region_Automatic_Mode_automatic_region__entry_Default(State_chart* handle)
{
	/* Default react sequence for initial entry  */
	state_chart_enseq_main_region_Automatic_Mode_automatic_region_Off_default(handle);
}

/* Default react sequence for initial entry  */
static void state_chart_react_main_region__entry_Default(State_chart* handle)
{
	/* Default react sequence for initial entry  */
	state_chart_enseq_main_region_Manual_Mode_default(handle);
}


