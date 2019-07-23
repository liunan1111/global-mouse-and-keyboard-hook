
#include <Windows.h>
#include <iostream>

class MyHook{
public:
	//single ton
	static MyHook& Instance(){
		static MyHook myHook;
		return myHook;
	}	
	HHOOK hook; // handle to the hook	
	void InstallHook(); // function to install our hook
	void UninstallHook(); // function to uninstall our hook

	MSG msg; // struct with information about all messages in our queue
	int Messsages(); // function to "deal" with our messages 

	HHOOK keyboardhook;
};
LRESULT WINAPI MyMouseCallback(int nCode, WPARAM wParam, LPARAM lParam); //callback declaration
LRESULT WINAPI MyKeyBoardCallback(int nCode, WPARAM wParam, LPARAM lParam);