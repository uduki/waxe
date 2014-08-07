package wx;

import wx.Window;

class DataViewCtrl extends Window {
    public static function create( inParent:Window,
                                   ?inID:Int,
                                   ?inPosition:{ x:Int, y:Int },
                                   ?inSize:{ width:Int, height:Int },
                                   ?inStyle:Int,
                                   ?inValidator:Void
                                   )
    {
        var params = [ inParent == null ? null : inParent.wxHandle
                     , inID
                     , ""
                     , inPosition
                     , inSize
                     , inStyle
                     ];
        var handle = wx_dataviewctrl_create(params, inValidator);
        return new DataViewCtrl(handle);
    }

    public function new(inHandle:Dynamic)
    {
        super(inHandle);
    }

    static var wx_dataviewctrl_create:Array<Dynamic> -> Dynamic = Loader.load("wx_dataviewctrl_create",2);
}