import ipywidgets as widgets
from traitlets import List, Unicode, observe, CInt
from IPython.display import display_html
import json
import inspect

class ListEncoder(json.JSONEncoder):
    def default(self, o):
        if hasattr(o, '__dict__'):
            d = dict(
                (key,value)
                for key, value in inspect.getmembers(o)
                if value is not None
                and not key == "Position"
                and not key == "colorProvider"
                and not key == "toolTipBuilder"
                and not key == "parent"
                and not key.startswith("__")
                and not inspect.isabstract(value)
                and not inspect.isbuiltin(value)
                and not inspect.isfunction(value)
                and not inspect.isgenerator(value)
                and not inspect.isgeneratorfunction(value)
                and not inspect.ismethod(value)
                and not inspect.ismethoddescriptor(value)
                and not inspect.isroutine(value)
            )
            return self.default(d)
        return o

class ListMnt:
    def __init__(self, *args, **kwargs):
        self.type = self.__class__.__name__
        self.values = []

        if isinstance(args[0], list):
            self.values = args[0]
    def transform(self):
        model = json.dumps(self, cls=ListEncoder)
        return json.loads(model)

    def transformBack(self, dict):
        self.__dict__ = dict

    @observe('values')
    def _value_changed(self, change):
        """Called when the comm is changed."""
        if change['new'] is None:
            return
        self._model_id = self.model_id

        self.comm.on_msg(self._handle_msg)




class ListDisplay(widgets.DOMWidget):
    """An example widget."""
    _view_name = Unicode('HelloView').tag(sync=True)
    _model_name = Unicode('HelloModel').tag(sync=True)
    _view_module = Unicode('jupyter_skydata').tag(sync=True)
    _model_module = Unicode('jupyter_skydata').tag(sync=True)
    _view_module_version = Unicode('^0.1.0').tag(sync=True)
    _model_module_version = Unicode('^0.1.0').tag(sync=True)
    model = List().tag(sync=True)

    def __init__(self, *args, **kwargs):
        super(ListDisplay, self).__init__(**kwargs)
        self.model = args[0]
        args[0].model = self.model

    @observe('model')
    def _model_changed(self, change):
        if change['new'] is None:
            return
        self.model = change['new']


class ListDisplayWrapper(object):
    def __get__(self, model_instance, model_class):
        def f():
            print(type(model_instance))
            display_html(ListDisplay(model_instance))
        return f


class NumDisplay(widgets.DOMWidget):
    _view_name = Unicode('HelloView').tag(sync=True)
    _model_name = Unicode('HelloModel').tag(sync=True)
    _view_module = Unicode('jupyter_skydata').tag(sync=True)
    _model_module = Unicode('jupyter_skydata').tag(sync=True)
    _view_module_version = Unicode('^0.1.0').tag(sync=True)
    _model_module_version = Unicode('^0.1.0').tag(sync=True)
    model = CInt().tag(sync=True)

    def __init__(self, *args, **kwargs):
        super(ListDisplay, self).__init__(**kwargs)
        self.model = args[0]
        args[0].model = self.model


class NumDisplayWrapper(object):
    def __get__(self, instance, owner):
        def f():
            display_html(NumDisplay(instance))
        return f

class AugList(list):
    pass

class AugInt(int):
    pass