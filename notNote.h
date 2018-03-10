#ifndef INCLUDED_HELLOWORLDAPP_H
#define INCLUDED_HELLOWORLDAPP_H
 
class notNote : public wxApp
{
public:
	virtual bool OnInit();
};
 
DECLARE_APP(notNote)
 
#endif // INCLUDED_HELLOWORLDAPP_H