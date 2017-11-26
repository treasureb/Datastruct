#include<iostream>
#include<stack>
using namespace std;


struct Pos
{
	int _row;
	int _col;
	Pos(int row, int col)
		:_row(row)
		, _col(col)
	{}
}; 

template <size_t M,size_t N>
class Maze
{
public:
	Maze(int maze[][N])
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				_maze[i][j] = maze[i][j];
			}
		}
	}

	bool Check(Pos next)
	{
		if (next._row >= 0 && next._row < M && next._col >= 0 && next._col <= N && _maze[next._row][next._col] == 0)
		{
			return true;
		}

		return false;
	}

	//栈实现
	//bool GetPath(Pos& entry)
	//{
	//	stack<Pos> path;
	//	path.push(entry);
	//	bool isfirst = true;

	//	while (!path.empty())
	//	{
	//		Pos cur = path.top();

	//		_maze[cur._row][cur._col] = 2;

	//		if (cur._row == M - 1)
	//			return true;
	//		
	//		Pos next = cur;

	//		//上
	//		next._row--;
	//		if (Check(next))
	//		{
	//			path.push(next);
	//			continue;
	//		}

	//		//右
	//		next = cur;
	//		next._col++;
	//		if (Check(next))
	//		{
	//			path.push(next);
	//			continue;
	//		}

	//		//下
	//		next = cur;
	//		next._row++;
	//		if (Check(next))
	//		{
	//			path.push(next);
	//			continue;
	//		}

	//		//左
	//		next = cur;
	//		next._col--;
	//		if (Check(next))
	//		{
	//			path.push(next);
	//			continue;
	//		}
	//		path.pop();
	//		isfirst = false;
	//	}

	//	return false;
	//}


	bool Check(Pos cur, Pos next)
	{
		if (next._row >= 0 && next._row < M && next._col >= 0 && next._col <= N)
		{
			if (_maze[next._row][next._col] == 0)
			{
				return true;
			}
			else if (_maze[next._row][next._col] == 1)
			{
				return false;
			}
			else
			{
				return _maze[next._row][next._col] > _maze[cur._row][cur._col];
			}
		}
		else
		{
			return false;
		}

		return false;

	}

	//求最短路径可走回头路
	void GetShortPath_R(Pos entry,stack<Pos>& path,stack<Pos>& ShortPath)
	{
		Pos cur = entry;
		path.push(cur);
				
		if (entry._row == M - 1)
		{
			if (ShortPath.empty() || path.size() < ShortPath.size())
			{
				ShortPath = path;
			}
			printf("出口的坐标为：[%d][%d]\n", cur._row, cur._col);
		
		}
		
		Pos next = cur;
		
		//上
		next._row -= 1;
		if (Check(cur,next))
		{
			_maze[next._row][next._col] = _maze[cur._row][cur._col] + 1;
			GetShortPath_R(next, path, ShortPath);
		}

		//右
		next = cur;
		next._col += 1;
		if (Check(cur,next))
		{	
			_maze[next._row][next._col] = _maze[cur._row][cur._col] + 1;
			GetShortPath_R(next, path, ShortPath);
		}

		//下
		next = cur;
		next._row += 1;
		if (Check(cur,next))
		{
			_maze[next._row][next._col] = _maze[cur._row][cur._col] + 1;
			GetShortPath_R(next, path, ShortPath);
		}

		//左
		next = cur;
		next._col -= 1;
		if (Check(cur,next))
		{
			_maze[next._row][next._col] = _maze[cur._row][cur._col] + 1;
			GetShortPath_R(next, path, ShortPath);
		}
		
		path.pop();

	}

	//不能走回头路
	//void GetShortPath_R(Pos entry, stack<Pos>& path, stack<Pos>& ShortPath)
	//{
	//	Pos cur = entry;
	//	path.push(cur);
	//	_maze[cur._row][cur._col] = 2;
	//	

	//	if (entry._row == M - 1)
	//	{
	//		if (ShortPath.empty() || path.size() < ShortPath.size())
	//		{
	//			ShortPath = path;
	//		}
	//		printf("出口的坐标为：[%d][%d]\n", cur._row, cur._col);
	//		//return true;
	//	}

	//	Pos next = cur;

	//	//上
	//	next._row -= 1;
	//	if (Check(next))
	//	{
	//		GetShortPath_R(next, path, ShortPath);
	//		
	//	}

	//	//右
	//	next = cur;
	//	next._col += 1;
	//	if (Check(next))
	//	{
	//		
	//		GetShortPath_R(next, path, ShortPath);
	//		
	//	}

	//	//下
	//	next = cur;
	//	next._row += 1;
	//	if (Check(next))
	//	{
	//		
	//		GetShortPath_R(next, path, ShortPath);
	//		
	//	}

	//	//左
	//	next = cur;
	//	next._col -= 1;
	//	if (Check(next))
	//	{
	//	
	//		GetShortPath_R(next, path, ShortPath);
	//	}

	//	path.pop();
	//}



	void Print()
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << _maze[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

private:
	int _maze[M][N];
};

int main()
{
	int maze[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 0, 1, 1}
	};
	Maze<10,10> map(maze);
	Pos entry(2, 0);
	map.Print();
	stack<Pos> path;
	stack<Pos> Shortpath;
	map.GetShortPath_R(entry,path,Shortpath);
	map.Print();
	cout <<"最短路径为："<< Shortpath.size() << endl;
	return 0;
}
