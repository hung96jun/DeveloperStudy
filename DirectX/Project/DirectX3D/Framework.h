#pragma once

#include "targetver.h"
#define _CRTDBG_MAP_ALLOC

#define WIN32_LEAN_AND_MEAN

#include "Utilities/Defines.h"

#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <assert.h>
#include <crtdbg.h>

#include <d3d11.h>
#include <DirectXMath.h>
#include <d3dcompiler.h>
#include <DirectXTex.h>
#include <DirectXCollision.h>
#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>
#include <ImGuiFileDialog.h>
#include <d2d1_2.h>
#include <dwrite.h>
#include <Assimp/Importer.hpp>
#include <Assimp/scene.h>
#include <Assimp/postprocess.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "DirectXTex.lib")
#pragma comment(lib, "ImGui.lib")
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")
#pragma comment(lib, "assimp-vc143-mtd.lib")

using namespace std;
using namespace DirectX;
using namespace DirectX::TriangleTests;

typedef XMFLOAT4 Float4;
typedef XMFLOAT3 Float3;
typedef XMFLOAT2 Float2;
//typedef XMVECTOR Vector4;
typedef XMMATRIX Matrix;
typedef XMFLOAT4X4 Float4x4;

//typedef function<void()> Event;
//typedef function<void(void*)> ParamEvent;
//typedef function<void(int)> IntParamEvent;

///////////////////////////////////////////////////////////////////////////////
// System
///////////////////////////////////////////////////////////////////////////////
#include "Framework/System/Keyboard.h"
#include "Framework/System/Timer.h"
#include "Framework/System/Device.h"

///////////////////////////////////////////////////////////////////////////////
// Framework
///////////////////////////////////////////////////////////////////////////////
#include "Framework/Math/Vector.h"
#include "Framework/Math/Math.h"
#include "Framework/Math/Transformation.h"


#include "Scenes/Scene.h"
///////////////////////////////////////////////////////////////////////////////
// Buffer
///////////////////////////////////////////////////////////////////////////////
#include "Framework/Buffer/VertexBuffer.h"
#include "Framework/Buffer/IndexBuffer.h"
#include "Framework/Buffer/ConstBuffer.h"
#include "Framework/Buffer/GlobalBuffer.h"

///////////////////////////////////////////////////////////////////////////////
// State
///////////////////////////////////////////////////////////////////////////////
#include "Framework/State/BlendState.h"
#include "Framework/State/RasterizerState.h"
#include "Framework/State/SamplerState.h"

///////////////////////////////////////////////////////////////////////////////
// Environment
///////////////////////////////////////////////////////////////////////////////
#include "Framework/Environment/Camera.h"
#include "Framework/Environment/Environment.h"

///////////////////////////////////////////////////////////////////////////////
// Manager
///////////////////////////////////////////////////////////////////////////////
#include "Manager/GameManager.h"
#include "Manager/SceneManager.h"

///////////////////////////////////////////////////////////////////////////////
// Instance Object Management Class
///////////////////////////////////////////////////////////////////////////////
#include "Utilities/GameInstance.h"


extern HWND hWnd;
//extern Vector2 MousePos;

//Keyboard* Key;
//Timer* Time;
//Device* DeviceSystem;
//
//#define KEYBOARD Key
//#define TIMER Time
//#define DEVICE DeviceSystem
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Instance Object Method
///////////////////////////////////////////////////////////////////////////////
//Keyboard* GetKeyboard() { return Key; }
//Timer* GetTimer() { return Time; }
//Device* GetDevice() { return DeviceSystem; }
///////////////////////////////////////////////////////////////////////////////
