#pragma once
#include "Window.h"


class AppWindow: public Window
{
public:
	AppWindow() = default;


	// Geerbt über Window
	virtual void onCreate() override;

	virtual void onUpdate() override;

	virtual void onDestroy() override;

};

