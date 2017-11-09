# check jupyter widget

import ipywidgets as widgets
from traitlets import Unicode, validate

def check(key=None):
    def wrap(widget):
        l = key if key is not None else widget.__module__ + widget.__name__
        print(key)
        return widget
    return wrap



@check
class HelloWidget(widgets.DOMWidget):
    _view_name = Unicode('HelloView').tag(sync=True)
    _view_module = Unicode('hello').tag(sync=True)
    _view_module_version = Unicode('0.1.0').tag(sync=True)
    value = Unicode('Hello World!').tag(sync=True)


if __name__ == "__main__":
    from notebook import notebookapp
    notebookapp.launch_new_instance()