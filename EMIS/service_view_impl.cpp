#include "service_view_impl.h"
#include "service_ctrl_impl.h"

ServiceViewImpl::ServiceViewImpl(void)
{
	srcCtrl = new ServiceCtrlImpl;
}

ServiceViewImpl::~ServiceViewImpl(void)	
{
	delete srcCtrl;
}

void ServiceViewImpl::menuSrc(void)
{
	while(true)
	{
		system("clear");
		cout << "***欢迎进入快递管理界面子系统***" << endl;
		cout << "1、增加货架" << endl;
		cout << "2、删除货架" << endl;
		cout << "3、列出所有货架" << endl;
		cout << "4、入库快递" << endl;
		cout << "5、出库快递" << endl;
		cout << "6、修改快递信息" << endl;
		cout << "7、生成当前货架快递列表" << endl;
		cout << "8、列出所有快递" << endl;
		cout << "9、返回子系统" << endl;
		switch(get_cmd('1','9'))
		{
			case '1':	addShelf();	break;
			case '2':	delShelf();	break;
			case '3':	listShelf();	break;
			case '4':	addGood();	break;
			case '5':	delGood();	break;
			case '6':	modGood();	break;
			case '7':	listGood();	break;
			case '8':	listAllGood();	break;
			case '9':	return;
		}
	}
}

void ServiceViewImpl::addShelf(void)
{
	cout << "请输入货架名：";
	char name[20] = {};
	get_str(name,sizeof(name));
	Shelf shelf(name);
	if(srcCtrl->addShelf(shelf))
	{
		cout << "添加货架成功" << endl;
		sleep(1);
		return;
	}
	cout << "添加货架失败" << endl;
	sleep(1);
}

void ServiceViewImpl::delShelf(void)
{
	cout << "请输入货架ID：";
	int id = 0;
	cin >> id;
	if(srcCtrl->delShelf(id))
	{
		cout << "删除货架成功"  << endl;
		sleep(1);
		return;
	}
	cout << "id未找到，删除货架失败" << endl;
	sleep(1);
}

void ServiceViewImpl::listShelf(void)
{
	vector<Shelf>& shelfArr = srcCtrl->listShelf();
	for(unsigned int i=0; i<shelfArr.size(); i++)
	{
		cout << shelfArr[i] << endl;
	}
	anykey_continue();
}

void ServiceViewImpl::addGood(void)
{
	int id = 0;
	char date[20],name[20] ={},phone[20];
	cout << "请输入货架ID：";
	cin >> id;
	cout << "请输入要入库快递的入库日期：";
	get_str(date,sizeof(date));
	cout << "请输入要入库快递的持有人姓名：";
	get_str(name,sizeof(name));
	cout << "请输入要入库快递的持有人电话：";
	get_str(phone,sizeof(phone));
	
	Good good(date,name,phone);
	if(srcCtrl->addGood(id,good))
	{
		cout << "入库成功" << endl;
		sleep(1);
		return;
	}
	else
	cout << "入库失败" << endl;
	sleep(1);	
}

void ServiceViewImpl::delGood(void)
{
	int id = 0; 
	cout << "请输入要出库的快递ID：" << endl;
	cin >> id;
	if(srcCtrl->delGood(id))
	{
		cout << "出库成功" << endl;
		sleep(1);
		return;
	}
	cout << "id未找到，出库失败" << endl;
	sleep(1);
}

void ServiceViewImpl::modGood(void)
{
	int id = 0;
	cout << "请输入要修改的快递ID：";
	cin >> id;
	cout << "1、日期   2、姓名   3、电话   4、退出" << endl;
	Good good;
	char key[20] = {};
	switch(get_cmd('1','4'))
	{
		case '1' :	get_str(key,sizeof(key));	good.setDate(key);	break;
		case '2' :	get_str(key,sizeof(key));	good.setName(key);	break;
		case '3' :	get_str(key,sizeof(key));	good.setPhone(key);	break;
		case '4' :	return;
	}
	if(srcCtrl->modGood(id,good))
	{
		cout << "修改成功" << endl;
		sleep(1);
		return;
	}
	cout << "查无id,修改失败" << endl;
	sleep(1);
}

void ServiceViewImpl::listGood(void)
{
	int id = 0;
	cout << "请输入货架ID：";
	cin >> id;
	Shelf* shelf = srcCtrl->listGood(id);
	if(shelf == NULL)
	{
		cout << "查无此货架" << endl;
		sleep(1);
		return;
	}
	for(unsigned int i=0; i<shelf->goodArr.size(); i++)
	{
		cout << (shelf->goodArr)[i] << endl;
	}
	anykey_continue();
}
	
void ServiceViewImpl::listAllGood(void)
{
	vector<Shelf>& shelfArr = srcCtrl->listAllGood();
	for(unsigned int i=0; i<shelfArr.size(); i++)
	{
		cout << "货架：" << shelfArr[i] << endl;
		for(unsigned int j=0; j<shelfArr[i].goodArr.size(); j++)
		{
			cout << (shelfArr[i].goodArr)[j] << endl;
		}
	}
	anykey_continue();
}

