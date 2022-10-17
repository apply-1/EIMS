#ifndef SERVICE_VIEW_IMPL_H
#define SERVICE_VIEW_IMPL_H

#include "tools.h"
#include "service_view.h"
#include "service_ctrl.h"

class ServiceViewImpl : public ServiceView
{
	ServiceCtrl* srcCtrl;
public:
	ServiceViewImpl(void);
	~ServiceViewImpl(void);
	void menuSrc(void);
	void addShelf(void);
	void delShelf(void);
	void listShelf(void);
	void addGood(void);
	void delGood(void);
	void modGood(void);
	void listGood(void);
	void listAllGood(void);
};

#endif//SERVICE_VIEW_IMPL_H
