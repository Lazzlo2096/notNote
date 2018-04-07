#include "notNoteForm.h"

	int row = 0;

//теги, по счелчку редактирование (мб новые строки), запись в бд
#define __CALLBACK_WX__
int callback_wx(void *data, int argc, char **argv, char **azColName){

	// fprintf(stderr, "%s: ", (const char*)data);
	
	for(int i = 0; i<argc; i++){
		if( row==0 )
			((MyFrame1*)data)->m_listCtrl1->AppendColumn( azColName[i] ,wxLIST_FORMAT_LEFT, -1 ); 
		if( i==0 ){
		    ((MyFrame1*)data)->m_listCtrl1->InsertItem(row, argv[i] ? argv[i] : "NULL"); //_id
			
		}else{
		    ((MyFrame1*)data)->m_listCtrl1->SetItem(row, i, wxString::FromUTF8( argv[i] ? argv[i] : "NULL" ));
		}	
		//wxLogDebug(wxT(argv[i]));
	}


	row++;
	
	return 0;
}

#include "mySqlLite.h" // Почему это находиться после обявления callback_wx ?

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 2, 0, 0 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	gSizer1->Add( bSizer2, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	gSizer1->Add( bSizer4, 1, wxEXPAND, 5 );


	// m_dataViewListCtrl1 = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	// bSizer2->Add( m_dataViewListCtrl1, 1, wxALL|wxEXPAND, 5 );
	m_listCtrl1 = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT );
	bSizer2->Add( m_listCtrl1, 1, wxALL|wxEXPAND, 5 );
	
	m_textCtrl2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	#ifdef __WXGTK__
	if ( !m_textCtrl2->HasFlag( wxTE_MULTILINE ) )
	{
		m_textCtrl2->SetMaxLength( 10 );
	}
	#else
		m_textCtrl2->SetMaxLength( 10 );
	#endif
	bSizer4->Add( m_textCtrl2, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	bSizer4->Add( m_staticText2, 0, wxEXPAND|wxALL, 5 );
	
	
	//bSizer1->Add( gSizer1, 1, wxEXPAND, 5 );
	
	this->SetSizer( gSizer1 );
	this->Layout();
	m_menubar1 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	wxMenuItem* m_menuItem1;
	m_menuItem1 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Open DB") ) + wxT('\t') + wxT("ctrl+o"), wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem1 );
	
	m_menubar1->Append( m_menu1, wxT("File") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( m_menuItem1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame1::openSqliteDB ) );
	this->Connect( m_listCtrl1->GetId(), wxEVT_LIST_ITEM_SELECTED, wxListEventHandler( MyFrame1::startEditSelected ) );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame1::openSqliteDB ) );
	this->Disconnect( wxID_ANY, wxEVT_LIST_ITEM_SELECTED, wxListEventHandler( MyFrame1::startEditSelected ) );
	
}


void MyFrame1::openSqliteDB( wxCommandEvent& event ) { 
	// event.Skip();

	mySqlLite mySqlNotes;
	
	char *sql = "SELECT _id, CONTENT from NOTE"; /* Create SQL statement */
	if( mySqlNotes.open("5b5-auto.db") ){		
		mySqlNotes.exec_wx(sql, (void*)this);
	}

	// wxLogDebug(wxT("Event handler (MyFrame::qwerty) not implemented yet"));
}

void MyFrame1::startEditSelected( wxListEvent& event ) { 
	// event.Skip();
	// event.Skip();
	long item = event.GetIndex();
	wxString item_s;
	item_s << item;

	//wxLogDebug(wxT("Event startEditSelected:", item_s));
	// wxTrace(wxT("Event startEditSelected:", item));


}
