#include "good.h"

Good::Good(const char* date,const char* name,const char* phone)
{
	strcpy(m_strName,name);
	strcpy(m_strPhone,phone);
	strcpy(m_strDate,date);
}

void Good::setId(int id)
{
	m_iId = id;
}

void Good::setDate(const char* date)
{
	strcpy(m_strDate,date);
}

void Good::setName(const char* name)
{
	strcpy(m_strName,name);
}

void Good::setPhone(const char* phone)
{
	strcpy(m_strPhone,phone);
}

int Good::getId(void)
{
	return m_iId;
}

char* Good::getDate(void)
{
	return m_strDate;
}

char* Good::getName(void)
{
	return m_strName;
}

char* Good::getPhone(void)
{
	return m_strPhone;
}

ostream& operator<<(ostream& os,const Good& good)
{
	return os << good.m_iId << " " << good.m_strDate << " " << good.m_strName << " " << good.m_strPhone;
}

istream& operator>>(istream& is,Good& good)
{
	return is >> good.m_iId >> good.m_strDate >> good.m_strName >> good.m_strPhone;
}

