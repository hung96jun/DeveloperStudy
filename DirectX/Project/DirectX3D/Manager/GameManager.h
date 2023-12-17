#pragma once

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Update();
	void Render();

private:
	void Init();

	void Create();
	void Delete();

};

