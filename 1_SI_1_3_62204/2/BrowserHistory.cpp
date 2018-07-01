#include "stdafx.h"
#include <iostream>
#include "BrowserHistory.h"

BrowserHistory::BrowserHistory():n(32)
{
}

BrowserHistory::BrowserHistory(int n)
{
	this->n = n;
}

BrowserHistory::BrowserHistory(const BrowserHistory & entry)
{
	this->n = entry.n;
	this->entrycount = entry.entrycount;
	for (int i = 0; i < this->entrycount; i++)
	{
		this->entry[i] = entry.entry[i];
	}
}

BrowserHistory & BrowserHistory::operator=(const BrowserHistory & rhs)
{
	this->n = rhs.n;
	this->entrycount = rhs.entrycount;
	for (int i = 0; i < this->entrycount; i++)
	{
		this->entry[i] = rhs.entry[i];
	}
	return *this;
}

void BrowserHistory::AddEntry(const HistoryEntry& entry)
{
	if (entrycount>=n)
	{
		std::cout << "Error" << '\n';
	}
	else
	{
		this->entry[entrycount].month = entry.month;
		strcpy_s(this->entry[entrycount].URL, entry.URL);
		entrycount++;
	}
}

BrowserHistory BrowserHistory::operator+(const BrowserHistory & rhs)
{
	BrowserHistory result;
	result.n = this->n + rhs.n;
	for (int i = 0; i < this->entrycount; i++)
	{
		result.AddEntry(this->entry[i]);
	}
	for (int i = 0; i < rhs.entrycount; i++)
	{
		result.AddEntry(rhs.entry[i]);
	}
	return result;
}



void BrowserHistory::print()
{
	for (int i = 0; i < entrycount; i++)
	{
		std::cout << this->entry[i].month <<" ";
		std::cout << this->entry[i].URL;
		std::cout << '\n';
	}
}

int BrowserHistory::Month(int month)
{
	int br = 0;
	for (int i = 0; i <entrycount; i++)
	{
		if (this->entry[i].month == month)
			br++;
	}
	return br;
}

int BrowserHistory::MostMonth()
{
	int a[13],max,maxi,i;
	for (i = 1; i <= 12; i++)
	{
		a[i] = 0;
	}
	for (i = 0; i < entrycount; i++)
	{
		a[this->entry[i].month]++;
	}
	max = a[1];
	maxi = 1;
	for (int i = 2; i <= 12; i++)
	{
		if (max < a[i])
		{
			max = a[i];
			maxi = i;
		}
	}
	entrycount--;
	return maxi;
}


HistoryEntry::HistoryEntry():month(0),URL("ERROR")
{
}

HistoryEntry::HistoryEntry(int month,const char* URL)
{
	this->month = month;
	strcpy_s(this->URL, URL);
}

HistoryEntry & HistoryEntry::operator=(const HistoryEntry& rhs)
{
	if (this != &rhs)
	{
		this->month = rhs.month;
		strcpy(this->URL, rhs.URL);
	}
	return *this;
}
