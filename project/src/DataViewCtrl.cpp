#include "HaxeAPI.h"

value wx_dataviewctrl_create(value inParams, value inValidator)
{
    wxValidator *validator;
    bool isSuccess = ValueToWX(inValidator, validator);
    if (!isSuccess || validator == 0) validator = &wxDefaultValidator;
    CreationParam params(inParams, 0);
    wxDataViewCtrl *ctrl = new wxDataViewCtrl(params.parent, params.id,
                                              params.position, params.size,
                                              params.flags, *validator);
    return WXToValue(ctrl);
}
DEFINE_PRIM(wx_dataviewctrl_create,2)