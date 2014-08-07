#include "HaxeAPI.h"

value wx_frame_create(value inParams)
{
   CreationParams params(inParams,wxDEFAULT_FRAME_STYLE);
   wxFrame *frame = new wxFrame(params.parent,params.id,params.text,
                                params.position,params.size,params.flags);

   return WXToValue(frame);
}

DEFINE_PRIM(wx_frame_create,1)

value wx_frame_set_menu_bar(value inFrame, value inBar)
{
   wxFrame *frame;
   if (ValueToWX(inFrame,frame))
   {
      wxMenuBar *bar;
      ValueToWX(inBar,bar);
      frame->SetMenuBar(bar);
   }
   return alloc_null();
}
DEFINE_PRIM(wx_frame_set_menu_bar,2)

value wx_frame_create_statusbar(value inFrame, value number, value style, value inID, value inName)
{
    wxFrame *frame;
    if (ValueToWX(inFrame,frame))
    {
        frame->CreateStatusBar(Val2Int(number,1), Val2Int(style,wxSTB_DEFAULT_STYLE), Val2Int(inID,0), Val2Str(inName));
    }
    return alloc_null();
}
DEFINE_PRIM(wx_frame_create_statusbar,5)

value wx_frame_set_status_text(value inFrame, value text, value number)
{
    wxFrame *frame;
    if (ValueToWX(inFrame,frame))
    {
        frame->SetStatusText(Val2Str(text), Val2Int(number,0));
    }
    return alloc_null();
}
DEFINE_PRIM(wx_frame_set_status_text,3)

int link_Frame() { return 0; }

