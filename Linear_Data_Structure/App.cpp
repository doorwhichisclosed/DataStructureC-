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
	cout << "�ִ� �帣 ��ȣ:";
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
		default:cout << "�߸� �����ϼ̽��ϴ�.\n"; break;
		}
		cout << "�ƹ� Ű�� ��������.\n";
		ehglobal::getkey();
	}
}

int App::SelectMenu()
{
	ehglobal::clrscr();
	cout << "�帣 ���� ���α׷� [ESC]: ����\n";
	cout << "F1: �帣 �߰� F2: ��ȣ�� �帣 ���� F3: �̸����� �帣 ����\n";
	cout << "F4: ��ȣ�� �帣 �˻� F5: �̸����� �帣 �˻� F6: �帣 ��� ����\n";
	return ehglobal::getkey();
}

void App::AddGenre()
{
	int num = 0;
	cout << "�߰��� �帣 ��ȣ(1~" << max_genres << "):";
	num = ehglobal::getnum();
	if ((num <= 0) || (num > max_genres))
	{
		cout << "��ȿ�� �帣 ��ȣ�� �ƴմϴ�.\n";
		return;
	}
	if (genres[num - 1])
	{
		cout << "�̹� �ֽ��ϴ�.\n";
		return;
	}
	//MoreThan mt(num);
	//GIter seek = find_if(genres.begin(), genres.end(), mt);

	//if ((seek != genres.end()) && ((*seek)->GetNum() == num))
	//{
	//	cout << "�̹� �ֽ��ϴ�.\n";
	//	return;
	//}
	//last_gnum++;
	//cout << last_gnum << "��° �߰��� �帣��:";
	cout << "�߰��� �帣��:";
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
	cout << "������ �帣 ��ȣ(1~"<<max_genres<<"):";
	num = ehglobal::getnum();
	EqualerByNum ebnum(num);
	if ((num <= 0) || (num > max_genres))
	{
		cout << "��ȿ�� �帣 ��ȣ�� �ƴմϴ�.\n";
		return;
	}
	//GIter seek = find_if(genres.begin(), genres.end(), ebnum);
	//if (seek != genres.end())
	//{
	//	Genre* genre = (*seek);
	//	delete genre;
	//	genres.erase(seek);
	//	cout << "�����Ͽ����ϴ�.\n";
	//}
	//else
	//{
	//	cout << "�������� �ʴ� �帣 ��ȣ�Դϴ�.\n";
	//}
	if (genres[num - 1] == 0)
	{
		cout << "�����ϴ�.\n";
		return;
	}
	delete genres[num - 1];
	genres[num - 1] = 0;
}

void App::RemoveGenreByName()
{
	string name;
	cout << "������ ������:";
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
		cout << "�����Ͽ����ϴ�.\n";
	}
	else
	{
		cout << "�������� �ʴ� �帣���Դϴ�.\n";
	}
}

void App::FindGenreByNum()const
{
	int num = 0;
	cout << "�˻��� �帣 ��ȣ:";
	num = ehglobal::getnum();
	EqualerByNum ebnum(num);
	if ((num <= 0) || (num > max_genres))
	{
		cout << "��ȿ�� �帣 ��ȣ�� �ƴմϴ�.\n";
		return;
	}
	if (genres[num - 1] == 0)
	{
		cout << "�����ϴ�.\n";
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
	//	cout << "�������� �ʴ� �帣���Դϴ�.\n";
	//}
}

void App::FindGenreByName()const
{
	string name;
	cout << "�˻��� �帣��:";
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
		cout << "�������� �ʴ� �帣���Դϴ�.\n";
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