#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "tools.h"

class Good
{
	int m_iId;
	char m_strDate[20];
	char m_strName[20];
	char m_strPhone[20];
public:
	Good(const char* name="",const char* phone="",const char* date="");
	void setId(int id);
	void setDate(const char* date);
	void setName(const char* name);
	void setPhone(const char* phone);
	int getId(void);
	char* getDate(void);
	char* getName(void);
	char* getPhone(void);
	
	friend ostream& operator<<(ostream& os,const Good& good);
	friend istream& operator>>(istream& is,Good& good);
};

#endif//EMPLOYEE_H
