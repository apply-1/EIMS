#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "tools.h"
#include "good.h"

class Shelf
{
	int m_iId;
	char m_strName[20];
public:
	vector<Good> goodArr;
	Shelf(const char* name);
	Shelf(void)	{}
	void setId(int id);
	void setName(const char* name);
	int getId(void);
	char* getName(void);
	
	friend ostream& operator<<(ostream& os,const Shelf& shelf);
	friend istream& operator>>(istream& is,Shelf& shelf);
};

#endif//DEPARTMENT_H
