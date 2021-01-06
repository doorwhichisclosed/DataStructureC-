#pragma once
#include "Genre.h"
#include "ehglobal.h"
#include <vector>
#include <algorithm>

typedef vector<Genre*>Genres;
typedef Genres::iterator GIter;
typedef Genres::const_iterator GCIter;
class App
{
	Genres genres;
	int max_genres;
	//int last_gnum;
public:
	App(void);
	~App(void);
	void Run();
private:
	int SelectMenu();
	void AddGenre();
	void RemoveGenreByNum();
	void RemoveGenreByName();
	void FindGenreByNum()const;
	void FindGenreByName()const;
	void ListGenre()const;
};