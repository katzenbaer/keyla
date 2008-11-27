#ifdef LAYOUTHOOKDLL_EXPORTS
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC __declspec(dllimport)
#endif

namespace layoutHookDll {

	// Messages.
	// Get actual message identifier by calling ::RegisterWindowMessage().

	// Message that the DLL will send when layout in a window was changed.
	// WPARAM - (HWND) window
	// LPARAM - (HKL) layout (guaranteed not to be HKL_NEXT or any other HKL_* constant)
	const LPCTSTR LayoutChangedMessage = _T("keyla - layout hook DLL - message - layout changed {0cedb92a-9df9-41a3-a057-8552f1a785e2}");

	// Message that can be send to a window using ::SendMessage() to change its layout.
	// LPARAM - (HKL) layout
	const LPCTSTR SetLayoutMessage = _T("keyla - layout hook DLL - message - set layout {09528aa9-d513-4eab-88a5-0b34a264f51a}");

	// Message that can be send to a window using ::SendMessage() to get its layout.
	// After ::SendMessage() returned call getLayoutResult() to get the layout
	const LPCTSTR GetLayoutMessage = _T("keyla - layout hook DLL - message - get layout {6d5caf64-dc9f-41c7-984d-209fc14f3aa1}");

	// Initialize.
	// window - the window where to send our messages
	DECLSPEC void create(HWND window);

	// Hook procedure
	DECLSPEC LRESULT CALLBACK proc(int code, WPARAM wparam, LPARAM lparam);

	// See description of GetLayoutMessage
	//
	// This hack is needed because our hook procesedure's return value
	// does not become the return value of ::SendMessage()
	//
	DECLSPEC HKL getLayoutResult();

	// Deinitialize.
	DECLSPEC void destroy();
}
