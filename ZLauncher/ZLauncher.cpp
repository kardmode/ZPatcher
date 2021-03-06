//////////////////////////////////////////////////////////////////////////
//
// ZLauncher - Patcher system - Part of the ZUpdater suite
// Felipe "Zoc" Silveira - (c) 2016
//
//////////////////////////////////////////////////////////////////////////
//
// ZLauncher.cpp
// Implement the entry point for the launcher
//
//////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ZLauncher.h"
#include "ZLauncherFrame.h"

wxIMPLEMENT_APP(VisualCreatePatch);

bool VisualCreatePatch::OnInit()
{
	if (!wxApp::OnInit())
		return false;

	wxInitAllImageHandlers();
	
	//////////////////////////////////////////////////////////////////////////
	// Simple config section
	wxString	updateURL				= wxT("https://raw.githubusercontent.com/TheZoc/ZPatcher/master/tests/zpatcher_test.xml");
	wxString	versionFile				= wxT("zpatcher_test.zversion");
	wxString	targetDirectory			= wxT("./");
	wxString	launcherExecutableName	= wxT("Example.exe");

	//////////////////////////////////////////////////////////////////////////
	// Run the launcher!
	ZLauncherFrame* f = new ZLauncherFrame(nullptr);
	f->SetLaunchExecutableName(launcherExecutableName);

#ifdef _WIN32
	f->SetIcon(wxICON(frame_icon));
#elif __APPLE__
	// TODO: Remove this hardcode
	f->SetIcon(wxIcon("ZLauncher.icns"));
//#else __linux__
//	// TODO: Find out how this works in linux!
#endif

	f->Show(true);

	f->DoStartCreatePatchThread(updateURL, versionFile, targetDirectory);

	return true;
}

