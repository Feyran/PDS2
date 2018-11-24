/*
 * This file: EventManager.h
 *
 * This file contains the declaration of several constant used
 * to control the operations of the EventManager application.
 *
 */
#ifndef _EVENT_MNGR_H
#define _EVENT_MNGR_H

#include <string>
#include <iostream>
#include "Scheduler.h"

using namespace UT_315;

// Options for the program
#define EXIT_MNGR 0
#define ADD_EVENT 1
#define REMOVE_EVENT 2
#define FIND_EVENT 3
#define FIND_EVENT_DATE 4
#define FIND_EVENT_ROOM 5
#define FIND_EVENT_PERIOD 6
#define REMOVE_EVENTS_ROOM 7
#define ADD_ROOM_INFO 8
#define PRINT_EVENTS_FOR 9
#define PRINT_EVENTS_BAC 10


void print_menu();
int get_option();
void add_event(Scheduler& event_scheduler);
void remove_event(Scheduler& event_scheduler);
void find_event(Scheduler& event_scheduler);
void remove_all_events(Scheduler& event_scheduler);
void find_events_date(Scheduler& event_scheduler);
void find_events_room(Scheduler& event_scheduler);
void find_events_byperiod(Scheduler& event_scheduler);
void print_events_order(Scheduler& event_scheduler);
void print_events_rev_order(Scheduler& event_scheduler);
void add_room_info(Scheduler& event_scheduler);
void find_event_by_name(Scheduler& event_scheduler);
#endif

