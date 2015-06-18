#ifndef __SERVICE_H__
#define __SERVICE_H__
#include <net/ni.h>

#define LB_SERVICE_STATE_OK		1
#define LB_SERVICE_STATE_REMOVING	2

#define LB_SCHEDULE_ROUND_ROBIN 1

typedef struct {
	uint32_t	robin;
	uint8_t		state;
	uint64_t	event_id;
	uint64_t	timeout;
	uint8_t		protocol;
	uint32_t	addr;
	uint16_t	port;
	uint8_t		schedule;
	NetworkInterface* ni;
	uint8_t		ni_num;
	List*		servers;
	Map*		sessions;
} Service;

bool service_add(uint8_t protocol, uint32_t addr, uint16_t port, uint8_t schedule, uint8_t ni_num, uint64_t timeout);
bool service_is_empty(NetworkInterface* ni);
Service* find_service(NetworkInterface* ni, uint8_t protocol, uint32_t addr, uint16_t port);
bool service_remove(uint8_t protocol, uint32_t addr, uint16_t port, uint8_t ni_num, uint64_t wait);
bool service_remove_force(uint8_t protocol, uint32_t addr, uint16_t port, uint8_t ni_num);
void service_is_remove_grace(Service* service);
void service_dump();
#endif
