```C++
struct Vector
{
    Vector() : x(0), y(0) {}
    Vector(const int x, const int y) : x(x), y(y) {}

    bool operator==(const Vector& other)
    {
        return (x == other.x && y == other.y);
    }

    int x, y;
};

struct Edge
{
    Edge() : start(0, 0), end(0, 0) {}
    Edge(Vector start, Vector end) : start(start), end(end) {}
    Edge(int startX, int startY, int endX, int endY) : start(startX, startY), end(endX, endY) {}

    bool operator==(const Edge& other)
    {
        return start == other.start && end == other.end;
    }

    Edge reverse()
    {
        return Edge(end, start);
    }

    Vector start, end;
};

int solution(string dirs) {
    int answer = 0;
    vector<Edge> edges;
    Vector beforePos, nextPos;
    beforePos = nextPos = Vector(0, 0);
    
    for (char d : dirs)
    {
        beforePos = nextPos;

        switch (d)
        {
        case 'U':
            if (nextPos.y < 5)
                nextPos.y++;
            else
                continue;
            break;
        case 'D':
            if (nextPos.y > -5)
                nextPos.y--;
            else
                continue;
            break;
        case 'L':
            if (nextPos.x > -5)
                nextPos.x--;
            else
                continue;
            break;
        case 'R':
            if (nextPos.x < 5)
                nextPos.x++;
            else
                continue;
            break;
        }

        Edge edge = Edge(beforePos, nextPos);
        bool check = false;

        for (Edge beforeEdges : edges)
        {
            if (beforeEdges == edge || beforeEdges == edge.reverse())
            {
                check = true;
                break;
            }
        }

        if (check == false)
            edges.push_back(edge);
    }

    return edges.size();
}
```
일단은 반복문으로 처리 했지만 너무 비효율적이라 다른 방법 생각나면 개선

