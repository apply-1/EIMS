#ifndef SERVICE_CTRL_IMPL_H
#define SERVICE_CTRL_IMPL_H

#include "service_ctrl.h"
#include "service_mode.h"

class ServiceCtrlImpl : public ServiceCtrl
{
	ServiceMode* srcMode;
	vector<Shelf> shelfArr;
public:
	ServiceCtrlImpl(void);
	~ServiceCtrlImpl(void);
	bool addShelf(Shelf& shelf);
	int delShelf(int id);
	vector<Shelf>& listShelf(void);
	bool addGood(int id,Good& good);
	bool delGood(int id);
	bool modGood(int id,Good& good);
	Shelf* listGood(int id);
	vector<Shelf>& listAllGood(void);
};

#endif//SERVICE_CTRL_IMPL_H
