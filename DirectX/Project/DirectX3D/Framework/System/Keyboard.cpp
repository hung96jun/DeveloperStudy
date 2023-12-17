#include "Framework.h"

void Keyboard::Update()
{
	memcpy(OldState, CurState, sizeof(OldState));

	GetKeyboardState(CurState);

	for (UINT i = 0; i < KEY_MAX; i++)
	{
		BYTE key = CurState[i] & 0x80;
		CurState[i] = key ? 1 : 0;

		BYTE old = OldState[i];
		BYTE cur = CurState[i];

		if (old == 0 && cur == 1)
			MapState[i] = DOWN;
		else if (old == 1 && cur == 0)
			MapState[i] = UP;
		else
			MapState[i] = NONE;
	}
}
