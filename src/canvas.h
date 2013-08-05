#pragma once
#include "canvas.fwd.h"
#include "stdafx.h"
#include "frame.fwd.h"
#include "document.fwd.h"

namespace treesheets {
struct Canvas : public wxScrolledWindow
{
    Frame *frame;
    Document *doc;
    
    int mousewheelaccum;
    bool lastrmbwaswithctrl;
    wxPoint lastmousepos;
    Canvas(Frame *fr, wxWindow *parent, const wxSize &size = wxDefaultSize);
    ~Canvas() ;
    void OnPaint( wxPaintEvent &event );
    void UpdateHover(int mx, int my, wxDC &dc);
    void OnMotion(wxMouseEvent &me);
    void SelectClick(int mx, int my, bool right, int isctrlshift);
    void OnLeftDown(wxMouseEvent &me);
    void OnLeftUp(wxMouseEvent &me);
    void OnRightDown(wxMouseEvent &me);
    void OnLeftDoubleClick(wxMouseEvent &me);
    void OnChar(wxKeyEvent &ce);
    void OnMouseWheel(wxMouseEvent &me);
    void OnSize(wxSizeEvent &se);
    void OnContextMenuClick(wxContextMenuEvent &cme);
    void CursorScroll(int dx, int dy);
    void Status(const char *msg = NULL);
    DECLARE_EVENT_TABLE()
};
}
