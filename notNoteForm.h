///////////////////////////////////////////////////////////////////////////

#ifndef __NOTNOTEFORM_H__
#define __NOTNOTEFORM_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/dataview.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
// #include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>

#include <wx/listctrl.h>
#include <wx/log.h> //wxLogDebug()

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame 
{
	private:
	
	protected:
		friend int callback_wx(void *data, int argc, char **argv, char **azColName);
		wxDataViewListCtrl* m_dataViewListCtrl1;
		wxTextCtrl* m_textCtrl2;
		wxStaticText* m_staticText2;
		wxMenuBar* m_menubar1;
		wxMenu* m_menu1;
		wxListCtrl* m_listCtrl1;
		
		void openSqliteDB( wxCommandEvent& event );
		void startEditSelected( wxListEvent& event );
	
	public:
		
		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 519,319 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MyFrame1();
	
};

#endif //__NOTNOTEFORM_H__
