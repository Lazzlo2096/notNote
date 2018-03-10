// For compilers that don't support precompilation, include "wx/wx.h"
#include "wx/wxprec.h"
 
#ifndef WX_PRECOMP
#	include "wx/wx.h"
#endif
 
#include "notNote.h"
#include "notNoteForm.h"
 
IMPLEMENT_APP(notNote)
 
// This is executed upon startup, like 'main()' in non-wxWidgets programs.
bool notNote::OnInit()
{
	wxFrame *frame = new MyFrame1((wxFrame*) NULL, -1, _T("notNote"));
	// frame->CreateStatusBar();
	// frame->SetStatusText(_T("Hello World"));
	frame->Show(true);
	SetTopWindow(frame);
	return true;
}