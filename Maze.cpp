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

	bool Check(const Pos& next)
	{
		int row = next._row;
		int col = next._col;
		if (row >= 0 && row < M && col >= 0 && col < N && _maze[row][col] == 0)
			return true;
		else
			return false;
	}

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

	bool Check(Pos &cur, Pos& next)
	{
		if (next._row >= 0 && next._row < M && next._col >= 0 && next._col < N && _maze[next._row][next._col] == 0)
		{
			_maze[next._row][next._col] = _maze[cur._row][cur._col] + 1;
			return true;
		}

		else if (_maze[cur._row][cur._col] + 1 < _maze[next._row][next._col])
		{
			_maze[next._row][next._col] = _maze[cur._row][cur._col] + 1;
			return true;
		}

		return false;

	}

	void GetPath_R(Pos& entry,stack<Pos>& path,stack<Pos>& ShortPath)
	{
		Pos next = entry;
		Pos cur = entry;

		_maze[next._row][next._col] = 2;
				
		if (next._row == M - 1)
		{
			if (ShortPath.empty() || path.size() < ShortPath.size())
				ShortPath = path;
			
			printf("出口的坐标为：[%d][%d]\n", next._row, next._col);
			return ;	
		}

		
		//上

		next._row -= 1;
		if (Check(next))
		{
			path.push(next);
			GetPath_R(next, path, ShortPath);
		}

		//右
		next = entry;
		next._col += 1;
		if (Check(next))
		{
			path.push(next);
			GetPath_R(next,path,ShortPath);
		}

		//下
		next = entry;
		next._row += 1;
		if (Check(next))
		{
			path.push(next);
			GetPath_R(next, path, ShortPath);
		}

		//左
		next = entry;
		next._col -= 1;
		if (Check(next))
		{
			path.push(next);
			GetPath_R(next, path, ShortPath);
		}
		
		path.pop();

	}



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
	map.GetPath_R(entry,path,Shortpath);
	map.Print();
	cout <<"最短路径为："<< Shortpath.size() << endl;
	return 0;
}