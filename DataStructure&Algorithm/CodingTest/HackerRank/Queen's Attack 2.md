- k : 장애물의 갯수
- n : 체스판의 갯수
- 
- 체스판 안에서 퀸이 움직일수 있는 모든 경우의 수를 구하는 문제
![[Pasted image 20231018184501.png]]
- 장애물이 존재한다.
- 좌우 (x = 0, y = n)
- 상하 (x = n, y = 0)
- 대각선 (abs(x) == abs(y))
위의 조건에 부합한 위치를 구하면 된다.
단, obstracle 부터 넘어서의 위치는 구하지 못한다.

```C++
enum Direction
{
	None,
	Up,
	Down,
	Left,
	Right,
	UpLeft,
	UpRight,
	DownLeft,
	DownRight,
};

struct Pos
{
	Pos() {}
	Pos(int x) : x(x), y(x) {}
	Pos(int x, int y) : x(x), y(y) {}

	static Pos absDist(Pos a, Pos b)
	{
		return Pos(abs(a.x) - abs(b.x), abs(a.y) - abs(b.y));
	}

	static Pos dist(Pos a, Pos b)
	{
		return a - b;
	}

	static int dist(Pos a)
	{
		if (abs(a.x) == abs(a.y))
			return abs(a.x);
		else if (a.x == 0)
			return abs(a.y);
		else if (a.y == 0)
			return abs(a.x);

		return -1;
	}

	int dist()
	{
		if (abs(x) == abs(y))
			return abs(x);
		else if (x == 0)
			return abs(y);
		else if (y == 0)
			return abs(x);

		return -1;
	}

	Direction getDirection()
	{
		if (abs(x) == abs(y) && (x > 0 && y < 0))
			return Direction::UpLeft;
		else if (abs(x) == abs(y) && (x < 0 && y < 0))
			return Direction::UpRight;
		else if (abs(x) == abs(y) && (x > 0 && y > 0))
			return Direction::DownLeft;
		else if (abs(x) == abs(y) && (x < 0 && y > 0))
			return Direction::DownRight;
		else if (x > 0 && y == 0)
			return Direction::Left;
		else if (x < 0 && y == 0)
			return Direction::Right;
		else if (x == 0 && y < 0)
			return Direction::Up;
		else if (x == 0 && y > 0)
			return Direction::Down;
		else return Direction::None;
	}

	const Pos& operator-(const Pos& other)
	{
		this->x = this->x - other.x;
		this->y = this->y - other.y;	
		return *this;
	}

	int x = -1;
	int y = -1;
};

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) 
{
	map<Direction, int> moveDistance;

	Pos curPos = Pos(c_q, r_q);

	int rightMax = n - c_q;
	int upMax = n - r_q;
	int leftMax = c_q - 1;
	int downMax = r_q - 1;

	{
		pair<Direction, int> distPair;
		{
			distPair.first = Direction::Up;
			distPair.second = Pos(0, upMax).dist();
			moveDistance.insert(distPair);
		}
		{
			distPair.first = Direction::Down;
			distPair.second = Pos(0, downMax).dist();
			moveDistance.insert(distPair);
		}
		{
			distPair.first = Direction::Left;
			distPair.second = Pos(leftMax, 0).dist();
			moveDistance.insert(distPair);
		}
		{
			distPair.first = Direction::Right;
			distPair.second = Pos(rightMax, 0).dist();
			moveDistance.insert(distPair);
		}
		{
			distPair.first = Direction::UpLeft;
			int minValue = min(upMax, leftMax);
			distPair.second = Pos(minValue).dist();
			moveDistance.insert(distPair);
		}
		{
			distPair.first = Direction::UpRight;
			int minValue = min(upMax, rightMax);
			distPair.second = Pos(minValue).dist();
			moveDistance.insert(distPair);
		}
		{
			distPair.first = Direction::DownLeft;
			int minValue = min(downMax, leftMax);
			distPair.second = Pos(minValue).dist();
			moveDistance.insert(distPair);
		}
		{
			distPair.first = Direction::DownRight;
			int minValue = min(downMax, rightMax);
			distPair.second = Pos(minValue).dist();
			moveDistance.insert(distPair);
		}
	}

	for (int i = 0; i < obstacles.size(); i++)
	{
		Pos obstacle = Pos(obstacles[i][1], obstacles[i][0]);
		Pos dist = Pos::dist(curPos, obstacle);
		Direction dir = dist.getDirection();
		if (dir == Direction::None)
			continue;

		if (moveDistance[dir] > (dist.dist() - 1))
			moveDistance[dir] = dist.dist() - 1;
	}

	int result = 0;

	for (pair<Direction, int> temp : moveDistance)
	{
		result += temp.second;
	}

	return result;
}
```