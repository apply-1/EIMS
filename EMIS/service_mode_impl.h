#ifndef SERVICE_MODE_IMPL_H
#define SERVICE_MODE_IMPL_H

#include "service_mode.h"
#include "tools.h"

class ServiceModeImpl : public ServiceMode
{
	~ServiceModeImpl(void)	{}
	void load(vector<Shelf>& shelfArr);
	void save(vector<Shelf>& shelfArr);
};

#endif//SERVICE_MODE_IMPL_H
