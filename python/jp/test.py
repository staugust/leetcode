# check jupyter widget

import ipywidgets as widgets
from traitlets import Unicode, validate
from beakerx import *


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


class AugSlider(widgets.IntSlider):
    def __init__(self):
        super(self.__class__, self)


class Test(BeakerxText):
    def __init__(self):
        super(self.__class__, self)

import ipykernel.kernelapp as app

class Defs(app.IPKernelApp):
    pass

if __name__ == "__main__":
    from notebook import notebookapp
    notebookapp.launch_new_instance()
    # print(AugSlider.__class__)
    # print(type(Test))
    #
    # Defs.launch_instance()