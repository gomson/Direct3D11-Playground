#pragma once

#include "Window.h"
#include "MessageQueue.h"

class HostWindow final : public Window
{
public:
	bool IsActive()    const;
	bool IsMinimized() const;
	bool IsResizing()  const;
	HWND GetHWND()     const;

	bool Initialize(LPCWSTR applicationName, int iCmdshow, int width, int height, MessageQueue::Pusher* messageQueue);
	void Teardown();

protected:
	virtual LRESULT MessageHandler(UINT, WPARAM, LPARAM);

private:
	LPCWSTR               applicationName = nullptr;
	HINSTANCE             hInstance       = nullptr;
	MessageQueue::Pusher* messageQueue    = nullptr;

	bool isActive    = false;
	bool isResizing  = false;
	bool isMinimized = false;
	bool isMaximized = false;
};