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
		if (row >= 0 && row < M && col >=0 && col < N && _maze[row][col ] == 0)
			return true;
		else
			return false;
	}

	bool GetPath(Pos& entry)
	{
		stack<Pos> path;
		path.push(entry);
		bool isfirst = true;

		while (!path.empty())
		{
			Pos cur = path.top();

			_maze[cur._row][cur._col] = 2;

			if (cur._row == M)
				return true;
			
			Pos next = cur;

			//ио
			next._row--;
			if (Check(next))
			{
				path.push(next);
				continue;
			}

			//ср
			next = cur;
			next._col++;
			if (Check(next))
			{
				path.push(next);
				continue;
			}

			//об
			next = cur;
			next._row++;
			if (Check(next))
			{
				path.push(next);
				continue;
			}

			//вС
			next = cur;
			next._col--;
			if (Check(next))
			{
				path.push(next);
				continue;
			}
			path.pop();
			isfirst = false;
		}

		return false;
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
		{0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 0, 1, 1, 1, 1, 0, 1, 1},
		{1, 1, 0, 1, 1, 1, 1, 0, 1, 1},
		{1, 1, 0, 1, 1, 1, 1, 0, 1, 1},
		{1, 1, 0, 1, 1, 1, 1, 0, 1, 1},
		{1, 1, 0, 1, 1, 1, 1, 1, 1, 1}
	};
	Maze<10,10> map(maze);
	Pos entry(2, 0);
	map.Print();
	map.GetPath(entry);
	map.Print();
	return 0;
}