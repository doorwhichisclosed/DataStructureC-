#include "App.h"

class EqualerByNum
{
	int num;
public:
	EqualerByNum(int num)
	{
		this->num = num;
	}
	bool operator()(const Genre* genre)const
	{
		return num == genre->GetNum();
	}
};

class EqualerByName
{
	string name;
public:
	EqualerByName(string name)
	{
		this->name = name;
	}
	bool operator()(const Genre* genre)const
	{
		if (genre == 0)
		{
			return false;
		}
		return name.compare(genre->GetName()) == 0;
	}
};

class MoreThan
{
	int num;
public:
	MoreThan(int num)
	{
		this->num = num;
	}

	bool operator()(const Genre* genre)const
	{
		return num <= genre->GetNum();
	}
};

App::App(void)
{
	cout << "최대 장르 번호:";
	max_genres = ehglobal::getnum();
	genres.resize(max_genres, 0);
	//last_gnum = 0;
}

void App::Run()
{
	int key = NO_DEFINED;
	while ((key = SelectMenu()) != ESC)
	{
		switch (key)
		{
		case F1:AddGenre(); break;
		case F2:RemoveGenreByNum(); break;
		case F3:RemoveGenreByName(); break;
		case F4:FindGenreByNum(); break;
		case F5:FindGenreByName(); break;
		case F6:ListGenre(); break;
		default:cout << "잘못 선택하셨습니다.\n"; break;
		}
		cout << "아무 키나 누르세요.\n";
		ehglobal::getkey();
	}
}

int App::SelectMenu()
{
	ehglobal::clrscr();
	cout << "장르 관리 프로그램 [ESC]: 종료\n";
	cout << "F1: 장르 추가 F2: 번호로 장르 삭제 F3: 이름으로 장르 삭제\n";
	cout << "F4: 번호로 장르 검색 F5: 이름으로 장르 검색 F6: 장르 목록 보기\n";
	return ehglobal::getkey();
}

void App::AddGenre()
{
	int num = 0;
	cout << "추가할 장르 번호(1~" << max_genres << "):";
	num = ehglobal::getnum();
	if ((num <= 0) || (num > max_genres))
	{
		cout << "유효한 장르 번호가 아닙니다.\n";
		return;
	}
	if (genres[num - 1])
	{
		cout << "이미 있습니다.\n";
		return;
	}
	//MoreThan mt(num);
	//GIter seek = find_if(genres.begin(), genres.end(), mt);

	//if ((seek != genres.end()) && ((*seek)->GetNum() == num))
	//{
	//	cout << "이미 있습니다.\n";
	//	return;
	//}
	//last_gnum++;
	//cout << last_gnum << "번째 추가할 장르명:";
	cout << "추가할 장르명:";
	string name = ehglobal::getstr();
	Genre* genre = new Genre(num, name);
	genres[num - 1] = genre;
	//genres.insert(seek, genre);
	//Genre* genre = new Genre(last_gnum, name);
	//genres.push_back(genre);
}

void App::ListGenre()const
{
	for (int i = 0; i < max_genres; i++)
	{
		if (genres[i])
		{
			genres[i]->View();
		}
	}
	//GCIter seek = genres.begin();
	//GCIter last = genres.end();
	//const Genre* genre;
	//for (; seek != last; seek++)
	//{
	//	genre = (*seek);
	//	genre->View();
	//}
}

void App::RemoveGenreByNum()
{
	int num = 0;
	cout << "삭제할 장르 번호(1~"<<max_genres<<"):";
	num = ehglobal::getnum();
	EqualerByNum ebnum(num);
	if ((num <= 0) || (num > max_genres))
	{
		cout << "유효한 장르 번호가 아닙니다.\n";
		return;
	}
	//GIter seek = find_if(genres.begin(), genres.end(), ebnum);
	//if (seek != genres.end())
	//{
	//	Genre* genre = (*seek);
	//	delete genre;
	//	genres.erase(seek);
	//	cout << "삭제하였습니다.\n";
	//}
	//else
	//{
	//	cout << "존재하지 않는 장르 번호입니다.\n";
	//}
	if (genres[num - 1] == 0)
	{
		cout << "없습니다.\n";
		return;
	}
	delete genres[num - 1];
	genres[num - 1] = 0;
}

void App::RemoveGenreByName()
{
	string name;
	cout << "삭제할 자을명:";
	name = ehglobal::getstr();
	EqualerByName ebname(name);
	GIter seek = find_if(genres.begin(), genres.end(), ebname);
	if (seek != genres.end())
	{
		Genre* genre = (*seek);
		int num = genre->GetNum();
		delete genre;
		//genres.erase(seek);
		genres[num - 1] = 0;
		cout << "삭제하였습니다.\n";
	}
	else
	{
		cout << "존재하지 않는 장르명입니다.\n";
	}
}

void App::FindGenreByNum()const
{
	int num = 0;
	cout << "검색할 장르 번호:";
	num = ehglobal::getnum();
	EqualerByNum ebnum(num);
	if ((num <= 0) || (num > max_genres))
	{
		cout << "유효한 장르 번호가 아닙니다.\n";
		return;
	}
	if (genres[num - 1] == 0)
	{
		cout << "없습니다.\n";
		return;
	}
	genres[num - 1]->View();
	//GCIter seek = find_if(genres.begin(), genres.end(), ebnum);
	//if (seek != genres.end())
	//{
	//	Genre* genre = (*seek);
	//	genre->View();
	//}
	//else
	//{
	//	cout << "존재하지 않는 장르명입니다.\n";
	//}
}

void App::FindGenreByName()const
{
	string name;
	cout << "검색할 장르명:";
	name = ehglobal::getstr();
	EqualerByName ebname(name);
	GCIter seek = find_if(genres.begin(), genres.end(), ebname);
	if (seek != genres.end())
	{
		Genre* genre = (*seek);
		genre->View();
	}
	else
	{
		cout << "존재하지 않는 장르명입니다.\n";
	}
}

App::~App(void)
{
	for (int i = 0; i < max_genres; i++)
	{
		if (genres[i])
		{
			delete genres[i];
		}
	}
	//GIter seek = genres.begin();
	//GIter last = genres.end();
	//Genre* genre;
	//for (; seek != last; ++seek)
	//{
	//	genre = (*seek);
	//	delete genre;
	//}
}