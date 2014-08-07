package wx;

import wx.Window;

class DataViewCtrl extends Window {
    public static function create( inParent:Window,
                                   ?inID:Int,
                                   ?inPosition:{ x:Int, y:Int },
                                   ?inSize:{ width:Int, height:Int },
                                   ?inStyle:Int,
                                   ?inValidator:Dynamic
                                   )
    {
        var handle = wx_dataviewctrl_create(
            [ inParent == null ? null : inParent.wxHandle
            , inID
            , ""
            , inPosition
            , inSize
            , inStyle
            ], inValidator);
        return new DataViewCtrl(handle);
    }

    public function new(inHandle:Dynamic)
    {
        super(inHandle);
    }

    static var wx_dataviewctrl_create:Array<Dynamic> -> Dynamic -> Dynamic = Loader.load("wx_dataviewctrl_create",2);
}
