#pragma once
#include "stdafx.h"
#include "frame.fwd.h"
namespace treesheets {

struct IPCServer : wxServer
{
    wxConnectionBase *OnAcceptConnection(const wxString& topic);
};

class App : public wxApp
{
  public:
    App();
    bool OnInit();
    int OnExit();
#ifdef __WXMAC__
    void MacOpenFile(const wxString &fn);
#endif
  private:
    Frame *frame;
    wxSingleInstanceChecker *checker;
    IPCServer *serv;

    DECLARE_EVENT_TABLE()
};
}
