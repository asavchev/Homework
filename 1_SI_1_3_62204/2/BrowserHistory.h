#pragma once
#include <cstring>
struct HistoryEntry
{
	int month;
	char URL[64];
	HistoryEntry();
	HistoryEntry(int month,const char* URL);
	HistoryEntry& operator=(const HistoryEntry& rhs);
};
class BrowserHistory
{
private:
	int n;
	HistoryEntry entry[1024];
	int entrycount = 0;

public:
	BrowserHistory();
	BrowserHistory(int n);
	BrowserHistory(const BrowserHistory& entry);
	BrowserHistory& operator=(const BrowserHistory& rhs);

	void AddEntry(const HistoryEntry& entry);
	BrowserHistory operator+(const BrowserHistory& rhs);
	
	void print();
	int Month(int month); // po daden mesec namira borq na saitovete koito sa poseteni
	int MostMonth();      // namira meseca s nai-mnogo poseteni saitove i iztriva posledniq sait dobaven

};